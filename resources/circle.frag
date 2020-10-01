#version 330 core

#define OBJECT_COUNT 1
#define DEFAULT_ID 0
#define PLANE_ID 1
#define CAKE_ID 2
#define LIGHTBOX_ID 3
#define REFLECTION_STEPS 2
#define MAX_STEPS 128
#define MAX_DISTANCE 30.0

uniform vec2 iResolution;
uniform float iTime;

float pi = acos(-1.0);
int AA = 2;
const vec3 c = vec3(-1.0, 0.0, 1.0);

struct Hit {
	int objectId;
    float dist;
};

vec2 hash22(vec2 st){
    st = vec2( dot(st,vec2(127.1,311.7)),
              dot(st,vec2(269.5,183.3)) );
    return -1.0 + 2.0*fract(sin(st)*43758.5453123);
}

float sm(in float d)
{
    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);
}

float manDist(in vec2 a, in vec2 b) {
	return abs(a.x-b.x)+abs(a.y-b.y);
}

float maxDist(in vec2 a, in vec2 b) {
	vec2 d = abs(a-b);
    return max(d.x,d.y);
}

float cellVoronoi(in vec2 uv, float t) {
    vec2 f = fract(uv)-.5;
    vec2 i = floor(uv);
    float minDist = 100.0;
    float secMinDist = 100.0;
    vec2 p1, p2;
    
    for(int x = -1; x < 2; x++) {
        for(int y = -1; y < 2; y++) {
            vec2 off = vec2(x,y);
            vec2 p = off+(sin(hash22(i+off)*t)+cos(hash22(i+off)*t))*0.25;

            //float d = length(f-p); // euclidian distance
            float d = manDist(f,p); // manhatten distance
            //float d = maxDist(f,p); // max norm
            
            if(d <= minDist) {
                secMinDist = minDist;
                minDist = d;
                p2 = p1;
                p1 = p;
            } else if(d < secMinDist) {
                secMinDist = d;
               	p2 = p;
            }
        }
    }

 	return sm(manDist(p2,f)-manDist(p1,f)-0.04);
}

// John Hoskins random
float hash11(float p)
{
    p = fract(p * .1031);
    p *= p + 33.33;
    p *= p + p;
    return fract(p);
}

// by John Hoskins
float hash12(vec2 p)
{
	vec3 p3  = fract(vec3(p.xyx) * .1031);
    p3 += dot(p3, p3.yzx + 33.33);
    return fract((p3.x + p3.y) * p3.z);
}

float pattern(in vec2 uv, float d) {
    float t = 6.0;
    uv *= vec2(0.5, 1.0);
    uv.x += hash11(floor(t*uv.y))*hash11(floor(t*uv.y));
    
	float noise = hash12(floor(t*uv));
	return step(d, noise);
}


float sdBox(in vec3 p, in vec3 r) {
    p = abs(p)-r;
    return length(max(p,0.0))+min(max(max(p.x,p.y),p.z),0.0);
}
    
vec2 iSphere(in vec3 ro, in vec3 rd, in vec4 sph) {
	vec3 oc = ro - sph.xyz;
	float b = dot( oc, rd );
	float c = dot( oc, oc ) - sph.w*sph.w;
	float h = b*b - c;
	if( h<0.0 )
        return vec2(-1.0);
	h = sqrt( h );
    
    return vec2(-b-h, -b+h);
}


float iPlane(in vec3 ro, vec3 rd) {
	return -ro.y/rd.y;
}

float iTex(in vec3 ro, vec3 rd) {
	float t = iPlane(ro, rd);
    
    vec3 p = ro+rd*t;
    
    
    
    float x = cellVoronoi(2.0*p.xz, 3.6);
    
    return (t+1.0)*step(1.0, x)-1.0;
}

vec3 metallicPattern(in vec2 uv) {
	vec3 color =  0.5*vec3(0.184, 0.31, 0.31);
    vec3 lightSlateGray = vec3(0.466, 0.533, 0.6);
    vec3 gray = vec3(0.4);
    
    float t = 6.0;
    uv *= vec2(0.5*hash11(floor(t*uv.y)), 1.0);
    uv.x += hash11(floor(t*uv.y))*hash11(floor(t*uv.y));
    
	float noise = hash12(floor(t*uv));
	
    
    return color = mix(color, gray, noise);
}

float iTex2(in vec3 ro, vec3 rd) {
	float t = iPlane(ro, rd);
    vec3 p = ro+rd*t;
    
    float x = pattern(p.xz, 0.35);
    
    return (t+1.0)*step(1.0, x)-1.0;
}

float sdSphere(in vec3 p, in float r) {
	return length(p)-r;
}

float sdPlane(in vec3 p) {
	return p.y;
}

float sdTex(in vec3 p) {
	return p.y;
}

float smin( float a, float b, float k )
{
	float h = clamp( 0.5 + 0.5*(b-a)/k, 0.0, 1.0 );
	return mix( b, a, h ) - k*h*(1.0-h);
}

Hit map(in vec3 p) {
    float dPlane = sdTex(p);
    
    float dists[OBJECT_COUNT];
    dists[0] = dPlane;

    int id = DEFAULT_ID;
    float dist = MAX_DISTANCE;
    
    for(int i = 0; i < OBJECT_COUNT; i++) {
        if(dists[i] < dist) {
            dist = dists[i];
            id = i+1;
        }
    }
    
    return Hit(id, dist);
}

vec3 calcNormal(in vec3 p) {
    vec2 e = vec2(0.05, 0.0);
	return normalize(vec3(
        map(p+e.xyy).dist-map(p-e.xyy).dist,
        map(p+e.yxy).dist-map(p-e.yxy).dist,
        map(p+e.yyx).dist-map(p-e.yyx).dist));
}

Hit castRay(in vec3 ro, in vec3 rd) {
    float t = 0.0;
	int id = DEFAULT_ID;
    
    /*for(int i = 0; i < MAX_STEPS; i++) {
    	vec3 p = ro+t*rd;
        Hit hit = map(p);
        if(abs(hit.dist) < 0.001) {
            id = hit.objectId;
        	break;
        } else if(t > MAX_DISTANCE) {
        	id = DEFAULT_ID;
            t = -1.0;
            break;
        }
        t += hit.dist;
    }  */
    
    
    id = PLANE_ID;
    
    float offset = 1.0*iTime;
    
    float t1 = iTex2(ro+vec3(offset, 0.0, 0.0),rd);
    t = t1;
    
    if(t < 0.0) {
        t = iTex(ro+vec3(offset, 0.2, 0.0), rd);
        id = CAKE_ID;
    }
    

    
    if(t < 0.0) {
    	id = DEFAULT_ID;
    }
    
    return Hit(id, t);
}

vec3 fresnelSchlick(float cosTheta, vec3 F0) {
	return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}

float DistributionGGX(vec3 N, vec3 H, float roughness) {
	float a = roughness * roughness;
	float a2 = a*a;
	float NdotH = max(dot(N, H), 0.0);
	float NdotH2 = NdotH*NdotH;

	float num = a2;
	float denom = (NdotH2 * (a2 - 1.0) + 1.0);
	denom = pi * denom * denom;

	return num / denom;
}

float GeometrySchlickGGX(float NdotV, float roughness) {
	float r = (roughness + 1.0);
	float k = (r*r) / 8.0;

	float num = NdotV;
	float denom = NdotV * (1.0 - k) + k;

	return num / denom;
}

float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness) {
	float NdotV = max(dot(N, V), 0.0);
	float NdotL = max(dot(N, V), 0.0);
	float ggx2  = GeometrySchlickGGX(NdotV, roughness);
	float ggx1  = GeometrySchlickGGX(NdotL, roughness);

	return ggx1 * ggx2;
}

vec3 getColor(in Hit hit, in vec3 p, in vec3 ro) {
    vec3 color = vec3(0.0);
    vec3 lpos = vec3(4.0, 2.0, -3.0);
    
    vec3 N = calcNormal(p);
    vec3 V = normalize(ro-p);

    vec3 intensity = vec3(1.0f) * 20.0f;
    vec3 albedo = vec3(1.0, 0.0, 0.0);
    float metallic = 0.5f;
    float roughness = 0.0f;
    float ao = 1.0f;
    vec3 emit = vec3(0.0);
    
    switch(hit.objectId) {
		
        case PLANE_ID:
        	albedo = metallicPattern(vec2(0.5,6.0)*(p.xz+vec2(iTime,0.0)));
        	metallic = 0.3f;
        	roughness = .5f;
        	emit = 0.5*vec3(pattern(vec2(5.0,5.0)*(p.xz+vec2(iTime,0.0)), 0.99));
        break;
        
        case CAKE_ID:
        	albedo = vec3(1.0, 0.5, 0.0);
        	metallic = 0.5f;
        	roughness = 0.0f;
        	emit = 1.0*albedo;
        break;
        
        case DEFAULT_ID:
        	albedo = vec3(1.0);
        	break;
    }
    
    

    
    vec3 F0 = vec3(0.04); // assumption from metallic workflow
    F0 = mix(F0, albedo, metallic);

	vec3 Lo = vec3(0.0);
    // calculate per-light radiance
    vec3 L = normalize(lpos - p);
    vec3 H = normalize(V + L);
    float d = length(lpos - p);
    float attenuation = 1.0 / (d * d);
    vec3 radiance = intensity * attenuation;

    // cook-torrance brdf
    float NDF = DistributionGGX(N, H, roughness);
    float G = GeometrySmith(N, V, L, roughness);
    vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

    vec3 kS = F; // ratio of reflection
    vec3 kD = vec3(1.0) - kS; // ratio of recfraction
    kD *= 1.0 - metallic; // if surface gets more metallic reduce refraction

    vec3 numerator = NDF * G * F;
    float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0);
    vec3 specular = numerator / max(denominator, 0.001);

    // add to outgoing radiance Lo
    float NdotL = max(dot(N, L), 0.0);
    Lo += (kD * albedo / pi + specular) * radiance * NdotL;

    vec3 ambient = vec3(0.03) * albedo * ao;
	color = ambient + Lo + emit;

    return color;
}

void main(void)
{   
    

    vec3 color = vec3(1.0);

    vec2 uv = (gl_FragCoord.xy/iResolution.xy-.5)*vec2(iResolution.x/iResolution.y, 1.0);
        
    vec2 m = sqrt(18.0)*vec2(cos(iTime-pi/4.0), sin(iTime-pi/4.0));
	m = vec2(iTime, 0.0);
    
    //vec3 ro = vec3(m.x,2.65,m.y);
    vec3 ro = normalize(vec3(-2.0, 2.0, 2.0))*5.0;
    vec3 ta = vec3(0.0, 0.0, 0.0);
    vec3 f = normalize(ta-ro);
    vec3 r = cross(c.yzy,f);
    vec3 u = cross(f,r);
    float zoom = 1.5;
    vec3 rd = normalize(uv.x*r+uv.y*u+zoom*f);
    
    bool firstRay = true;
    
    Hit hit;
    vec3 p;
        
	hit = castRay(ro, rd);
	p = ro+hit.dist*rd;
    color = getColor(hit, p, ro);
    
    color = color / (color + vec3(1.0)); // HDR to LDR correction
	color = pow(color, vec3(1.0 / 2.2)); // gamma correction

    //color = metallicPattern(uv);
    
    gl_FragColor = vec4(color,1.0);
}
