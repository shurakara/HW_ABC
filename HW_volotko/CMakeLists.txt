cmake_minimum_required(VERSION 3.20)
project(HW_volotko)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW_volotko main.cpp container.cpp container.h rnd.h Shape.cpp Shape.h sphere.cpp sphere.h regularTetrahedron.cpp regularTetrahedron.h parallelepiped.cpp parallelepiped.h)
