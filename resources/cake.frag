#version 330 core

uniform vec2 iResolution;
uniform float iTime;

#define OBJECT_COUNT 3
#define DEFAULT_ID 0
#define PLANE_ID 1
#define CAKE_ID 2
#define LIGHTBOX_ID 3
#define REFLECTION_STEPS 2
#define MAX_STEPS 128
#define MAX_DISTANCE 30.0

float pi = acos(-1.0);
int AA = 2;
const vec3 c = vec3(-1.0, 0.0, 1.0);

struct Hit {
	int objectId;
    float dist;
};

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


float sdSphere(in vec3 p, in float r) {
	return length(p)-r;
}

float sdPlane(in vec3 p) {
	return p.y;
}

float smin( float a, float b, float k )
{
	float h = clamp( 0.5 + 0.5*(b-a)/k, 0.0, 1.0 );
	return mix( b, a, h ) - k*h*(1.0-h);
}

Hit map(in vec3 p) {
    float r = 0.3;
    float dis = 0.55;
    
	float dSphere1 = sdSphere(abs(p)-vec3(dis,dis,dis), 0.3);
    float dSphere2 = sdSphere(abs(p)-vec3(dis,dis,0.0), 0.3);
    float dSphere3 = sdSphere(abs(p)-vec3(0.0,dis,dis), 0.3);
    float dSphere4 = sdSphere(abs(p)-vec3(dis,0.0,dis), 0.3);
    float dSphere5 = sdSphere(abs(p)-vec3(dis,0.0,0.0), 0.3);
    float dSphere6 = sdSphere(abs(p)-vec3(0.0,0.0,dis), 0.3);
    float dSphere7 = sdSphere(abs(p)-vec3(0.0,dis,0.0), 0.3);
    float dPlane = sdPlane(p-vec3(0.0,-0.9,0.0));
    float dBox = sdBox(p-vec3(2.0, 3.0, 0.0), vec3(0.9));
    
    float d = 0.15; 
    float dCake = smin(smin(smin(smin(smin(smin(dSphere1, dSphere2, d),dSphere3, d),dSphere4, d), dSphere5, d),dSphere6, d), dSphere7, d);
    
    float dists[OBJECT_COUNT];
    dists[0] = dPlane;
    dists[1] = dCake;
    dists[2] = dBox;
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
    
    for(int i = 0; i < MAX_STEPS; i++) {
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
    vec3 lpos = vec3(2.0, 2.0, 1.0);
    
    vec3 N = calcNormal(p);
    vec3 V = normalize(ro-p);

    vec3 intensity = vec3(1.0f) * 20.0f;
    vec3 albedo = vec3(1.0, 0.0, 0.0);
    float metallic = 0.5f;
    float roughness = 0.0f;
    float ao = 1.0f;
    
    switch(hit.objectId) {
    	case CAKE_ID: 
        	albedo = vec3(1.0, 0.0, 0.0);
        	metallic = 0.05f;
        	roughness = 0.0f;
        	break;
        case PLANE_ID:
        	albedo = vec3(0.1, 0.1, 0.1);
        	metallic = 0.0f;
        	roughness = 0.0f;
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
	color = ambient + Lo;

    return color;
}

void main(void)
{   
    vec2 uv = (gl_FragCoord.xy/iResolution.xy-.5)*vec2(iResolution.x/iResolution.y, 1.0);
    vec3 color = vec3(1.0);

    vec2 m = sqrt(18.0)*vec2(cos(iTime-pi/4.0), sin(iTime-pi/4.0));
	vec3 ro = vec3(m.x,2.65,m.y);
    vec3 ta = vec3(0.0,-.05,0.0);
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
    
    /*for(int i = 0; i < 2; i++) {
        if(firstRay) {
        	firstRay = false;
        } else {
        	ro = p-0.001*rd;
            rd = normalize(reflect(rd, calcNormal(p)));
        }
        hit = castRay(ro, rd);
        p = ro+hit.dist*rd;
        /*if(hit.objectId == DEFAULT_ID) {
            color[i] = color[i-1];
        } else {
            color[i] = getColor(hit, p, ro);
        }*/
    //}

    //col = mix(color[0], color[1], 0.5);
    
    color = color / (color + vec3(1.0)); // HDR to LDR correction
	color = pow(color, vec3(1.0 / 2.2)); // gamma correction
    
    gl_FragColor = vec4(color,1.0);
}