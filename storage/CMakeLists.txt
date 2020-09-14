cmake_minimum_required(VERSION 3.5)
project(tool210-storage LANGUAGES CXX)

###########################
# Dependencies

find_package(Qt5 COMPONENTS Core REQUIRED)

###########################
# Target

add_executable(${PROJECT_NAME}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    source
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
  Qt5::Core
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
