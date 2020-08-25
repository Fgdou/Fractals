cmake_minimum_required(VERSION 3.10)
project(fractals)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(fractals main.cpp Three.cpp Three.h Tree2.cpp Tree2.h Squares.cpp Squares.h)


target_link_libraries(fractals ${SDL2_LIBRARIES})