cmake_minimum_required(VERSION 2.6)

project(ShapeOOC)

set(CMAKE_BUILD_TYPE Debug)

enable_testing()




set(CFILES
        main.c
        )



add_executable( ShapeOOC ${CFILES} )
add_test(ShapeOOC ShapeOOC)
