cmake_minimum_required(VERSION 3.6)
project(Mydate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MyDate.h MyDate.cpp)
add_executable(Mydate ${SOURCE_FILES})