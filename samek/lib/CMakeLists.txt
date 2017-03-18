
cmake_minimum_required(VERSION 2.6)

project(SamekOOC)

set(CMAKE_BUILD_TYPE Debug)

enable_testing()



set(CFILES
	object.c
	shapes.c
	string.c
	)

	
set(HFILES
	object.h
	shapes.h
	string.h
	)


add_library(sameklib ${CFILES} ${HFILES})

add_executable(samek test.c)

target_link_libraries(samek sameklib)

add_test(samek samek)

