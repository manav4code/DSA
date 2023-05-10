
cmake_minimum_required(VERSION 3.15)
project(SimpleCmakeExample)


add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Whether or not to build examples" ON)

if(BUILD_EXAMPLES)
	message(STATUS "Building Examples...")
	add_subdirectory(example)
endif()

