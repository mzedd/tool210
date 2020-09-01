cmake_minimum_required(VERSION 3.5)
project(tool210-lib LANGUAGES CXX)

###########################
# Dependencies
find_package(Qt5 COMPONENTS Core Gui REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} SHARED
  # source
  ## controllers
  source/controllers/maincontroller.cpp
  source/controllers/timelinecontroller.cpp

  ## models
  source/models/cliplistmodel.cpp
  source/models/openglmodel.cpp
  source/models/Demo.cpp
  source/models/Clip.cpp
  source/models/ShaderOnlyScene.cpp

  # public
  ## controllers
  public/controllers/maincontroller.h
  public/controllers/timelinecontroller.h

  ## models
  public/models/cliplistmodel.h
  public/models/openglmodel.h
  public/models/Demo.h
  public/models/Clip.h
  public/models/Scene.h
  public/models/ShaderOnlyScene.h
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:
      public
      public/controllers
      public/models
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
      ${CMAKE_CURRENT_SOURCE_DIR}/public/controllers
      ${CMAKE_CURRENT_SOURCE_DIR}/public/models
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    ${CMAKE_CURRENT_SOURCE_DIR}/source/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/source/models
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    TOOL210_LIBRARY
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
