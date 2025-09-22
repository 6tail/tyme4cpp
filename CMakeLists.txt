cmake_minimum_required(VERSION 3.20)
project(tyme4cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tyme)
add_subdirectory(tests)
enable_testing()
add_test(NAME tyme_test COMMAND tests)
