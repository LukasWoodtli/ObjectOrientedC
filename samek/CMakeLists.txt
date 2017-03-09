
cmake_minimum_required(VERSION 2.6)

project(SamekOOC)

set(CMAKE_BUILD_TYPE Debug)

enable_testing()



set(CFILES
	test.c
	object.c
	shapes.c
	string.c
	)

	
set(HFILES
	object.h
	shapes.h
	string.h
	)


add_executable( Samek ${CFILES} ${HFLES} )

add_test(Samek Samek)

