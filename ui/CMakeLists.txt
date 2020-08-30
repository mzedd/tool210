cmake_minimum_required(VERSION 3.5)
project(tool210-ui LANGUAGES CXX)

###########################
# Dependencies

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

###########################
# Target

add_executable(${PROJECT_NAME}
  main.cpp
  mainwindow.cpp
  mainwindow.h
  views/cliplistview.cpp
  views/cliplistview.h
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    source
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
  Qt5::Core
  Qt5::Widgets
  Qt5::Gui
  tool210-lib
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_14
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
