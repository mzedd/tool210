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
  views/view.h

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

  # cameraInspector
  views/camerainspector/camerainspectorpresenter.cpp
  views/camerainspector/camerainspectorpresenter.h
  views/camerainspector/camerainspectorviewmodel.cpp
  views/camerainspector/camerainspectorviewmodel.h
  views/camerainspector/camerainspectorview.cpp
  views/camerainspector/camerainspectorview.h
  views/camerainspector/camerainspectorview.ui
  views/camerainspector/pointview.cpp
  views/camerainspector/pointview.h
  views/camerainspector/pointview.ui
  views/camerainspector/pointviewmodel.cpp
  views/camerainspector/pointviewmodel.h
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    "${CMAKE_SOURCE_DIR}/ui"
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
    AUTOUIC ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Copy <filename> to build directory
set(copy_source_dir "${CMAKE_SOURCE_DIR}/resources")
set(copy_dest_dir "${CMAKE_BINARY_DIR}/bin/Debug/resources")
set(copy_file_name "quad.vert")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${copy_dest_dir}
)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${copy_source_dir}/${copy_file_name}" "${copy_dest_dir}/${copy_file_name}"
    COMMENT "Copying ${copy_file_name} to build directory"
)
