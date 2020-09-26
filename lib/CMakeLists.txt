cmake_minimum_required(VERSION 3.7.2)
project(tool210 LANGUAGES CXX)

add_subdirectory(entities)
add_subdirectory(control)
add_subdirectory(storage)

add_library(${PROJECT_NAME} SHARED
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    TOOL210_LIBRARY
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    tool210-control
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_14
)
