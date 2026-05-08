cmake_minimum_required(VERSION 3.20)

project(tests CXX)

if (NOT TARGET tyme)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../tyme tyme_build)
endif()
add_executable(tests tests.cpp)
target_link_libraries(tests tyme)
