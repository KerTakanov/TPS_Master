cmake_minimum_required(VERSION 3.8)
project(TP1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GrayLevelImage2D.cpp GrayLevelImage2D.h MedianFilter.cpp MedianFilter.h)
add_executable(TP1 ${SOURCE_FILES})