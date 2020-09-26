cmake_minimum_required(VERSION 3.7.2)
project(tool210-storage-tests LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    tool210-control
    tool210-storage
)

target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_14
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
