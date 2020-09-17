cmake_minimum_required(VERSION 3.7.2)
project(tool210-entities LANGUAGES CXX)

###########################
# Dependencies
find_package(Qt5 COMPONENTS Core Gui REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} STATIC
  # source
  source/Demo.cpp
  source/Clip.cpp
  source/ShaderOnlyScene.cpp

  # public
  public/Demo.h
  public/Clip.h
  public/Scene.h
  public/ShaderOnlyScene.h
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

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt5::Core
    Qt5::Gui
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_14
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
