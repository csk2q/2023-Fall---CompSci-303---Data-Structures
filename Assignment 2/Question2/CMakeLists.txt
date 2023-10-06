cmake_minimum_required(VERSION 3.26)
project(Question2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Question2
        main.cpp
        Employee.h
        Professional.h
        Professional.cpp
        NonProfessional.cpp
        NonProfessional.h
)
