cmake_minimum_required(VERSION 3.29)
project(8)

set(CMAKE_CXX_STANDARD 20)

add_executable(8 main.cpp stack.cpp calculator.cpp)
enable_testing()
add_subdirectory(tests)
