cmake_minimum_required(VERSION 2.6)

project(ObjectOrientedC)

set(CMAKE_BUILD_TYPE Debug)
enable_testing()
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-W -Wall -Wextra  -Werror -std=c99")

add_subdirectory("samek")
add_subdirectory("weirich")

