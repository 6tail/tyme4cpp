cmake_minimum_required(VERSION 3.29.2)

project(tyme CXX)

add_library(tyme SHARED util.cpp tyme.cpp)
target_include_directories(tyme PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
