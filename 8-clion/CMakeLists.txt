cmake_minimum_required(VERSION 3.30)
project(8_clion)

set(CMAKE_CXX_STANDARD 20)

add_library(lib STATIC stack.cpp calculator.cpp)
add_subdirectory(tests lib)
enable_testing()
add_executable(8_clion
        main.cpp
        calculator.cpp
        stack.cpp
        calculator.cpp
        tests/tests.cpp
)
target_link_libraries(8_clion PRIVATE gtest gtest_main)
#target_link_libraries(tests gtest gtest_main)
add_executable(tests tests/tests.cpp)
