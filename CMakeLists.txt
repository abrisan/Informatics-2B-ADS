cmake_minimum_required(VERSION 3.6)
project(test_build)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES C++/Note3/Tester.cpp)
add_executable(test_build ${SOURCE_FILES})