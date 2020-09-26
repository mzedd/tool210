cmake_minimum_required(VERSION 3.7.2)
project(tool210-entities-tests LANGUAGES CXX)

###########################
# Targets

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    tool210-entities
)

target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_14
)
