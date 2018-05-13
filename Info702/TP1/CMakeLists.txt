cmake_minimum_required(VERSION 3.8)
project(TP1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GrayLevelImage2D.cpp GrayLevelImage2D.h MedianFilter.cpp MedianFilter.h Image2D.h Color.h testImage2D.cpp testImage2D.h Image2DWriter.h Filter.h InvertRedBlueFilter.h Image2DReader.h Accessor.h save-channel.cpp save-channel.h Histogramme.cpp Histogramme.h invert-red-blue.cpp)
add_executable(TP1 ${SOURCE_FILES})