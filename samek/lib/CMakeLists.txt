cmake_minimum_required(VERSION 2.6)

set(CFILES
	object.c
	shapes.c
	string.c)

	
set(HFILES
	object.h
	shapes.h
	string.h)


add_library(sameklib STATIC ${CFILES} ${HFILES})


add_executable(SameklibTest test.c)
target_link_libraries(SameklibTest sameklib)
add_test(SameklibTest SameklibTest )
