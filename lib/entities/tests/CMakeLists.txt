cmake_minimum_required(VERSION 3.7.2)
project(tool210-entities-tests LANGUAGES CXX)

find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

enable_testing(true)

###########################
# Targets

add_executable(${PROJECT_NAME}
    demotest.cpp

    demotest.h
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt5::Test
    tool210-entities
)

target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_14
)



