cmake_minimum_required(VERSION 3.7.2)
project(tool210-control LANGUAGES CXX)

###########################
# Dependencies
find_package(Qt5 COMPONENTS Core Gui REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} STATIC
  # source
  ## controllers
  source/controllers/maincontroller.cpp
  source/controllers/rendercontext.cpp

  ## models
  source/models/cliplistmodel.cpp
  source/models/scenelistmodel.cpp
  source/models/openglrenderer.cpp

  ## interactors
  source/interactors/addsceneinteractor.cpp

  # public
  ## controllers
  public/controllers/maincontroller.h
  public/controllers/rendercontext.h
  public/controllers/renderer.h

  ## models
  public/models/cliplistmodel.h
  public/models/scenelistmodel.h
  public/models/openglrenderer.h

  ## interactors
  public/interactors/addsceneinteractor.h

  ## file accessor
  public/demofileaccessinterface.h
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
    TOOL210_CONTROL
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt5::Core
    Qt5::Gui
    tool210-entities
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
