cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)
 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(main.cpp test.cpp)

find_package(GTest REQUIRED)
include_directories(include tests ${GTEST_INCLUDE_DIRS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
