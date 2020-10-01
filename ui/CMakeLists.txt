cmake_minimum_required(VERSION 3.7.2)
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

  # views
  ## timeline
  views/timeline/timelineview.cpp
  views/timeline/timelineview.h
  views/timeline/cliplistview.cpp
  views/timeline/cliplistview.h

  # clipscreen
  views/clipscreen/clipscreenview.cpp
  views/clipscreen/clipscreenview.h
  views/clipscreen/aspectratiowidget.cpp
  views/clipscreen/aspectratiowidget.h
  views/clipscreen/openglscreen.cpp
  views/clipscreen/openglscreen.h

  # clipinspector
  views/clipinspector/clipinspectorview.cpp
  views/clipinspector/clipinspectorview.h

  # sceneeditor
  views/sceneeditor/sceneeditorview.cpp
  views/sceneeditor/sceneeditorview.h
  views/sceneeditor/filepathwidget.cpp
  views/sceneeditor/filepathwidget.h
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
  tool210-control
  tool210-storage
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
