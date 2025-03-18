cmake_minimum_required(VERSION 3.30)
project(Works)

set(CMAKE_CXX_STANDARD 23)

add_executable(Works main.cpp
        students.h
        students.cpp
        studentAfterFirstSession.h
        studentAfterFirstSession.cpp
        studentAfterSecondSession.h
        studentAfterSecondSession.cpp)
