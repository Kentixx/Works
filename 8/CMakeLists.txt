cmake_minimum_required(VERSION 3.29)
project(8-clion)

set(CMAKE_CXX_STANDARD 20)

add_executable(8-clion main.cpp stack.cpp calculator.cpp)
enable_testing()
add_subdirectory(tests)
