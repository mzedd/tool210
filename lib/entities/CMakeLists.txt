cmake_minimum_required(VERSION 3.7.2)
project(tool210-entities LANGUAGES CXX)

###########################
# Targets
add_library(${PROJECT_NAME} STATIC
  # source
  source/demo.cpp
  source/clip.cpp
  source/scene.cpp
  source/camera.cpp
  source/point.cpp

  # public
  public/demo.h
  public/clip.h
  public/scene.h
  public/camera.h
  public/point.h
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:
      public
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    TOOL210_ENTITIES
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_14
)

###########################
# Include tests

add_subdirectory(tests)
