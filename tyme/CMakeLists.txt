cmake_minimum_required(VERSION 3.20)

project(tyme CXX)

add_library(tyme SHARED util.cpp tyme.cpp)
target_include_directories(tyme PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(tyme PRIVATE BUILDING_TYME_DLL)

if (MINGW)
    target_link_libraries(tyme PRIVATE
            -Wl,-Bstatic
            winpthread
            -Wl,-Bdynamic
    )
    target_link_options(tyme PRIVATE
            -static-libgcc
            -static-libstdc++
    )
endif ()
