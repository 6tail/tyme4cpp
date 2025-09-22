cmake_minimum_required(VERSION 3.20)

project(tests CXX)

add_executable(tests tests.cpp)
target_link_libraries(tests tyme)
