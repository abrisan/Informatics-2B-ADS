cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 Tester)
set(SOURCE_FILES_1 C++/Note1/Tester.cpp)

add_executable(${BUILD_1} ${SOURCE_FILES_1})