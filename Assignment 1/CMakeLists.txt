cmake_minimum_required(VERSION 3.26)
project(Question1)

set(CMAKE_CXX_STANDARD 17)

include_directories(Question1)

add_executable(Question1
        Question1/main.cpp
        Question1/Question1.cpp
        Question1/Question1.h)


project(Question2)

set(CMAKE_CXX_STANDARD 17)

include_directories(Question2)

add_executable(Question2
        Question2/main.cpp
        Question2/Question2.cpp
        Question2/Question2.h)