cmake_minimum_required(VERSION 3.16)

project(projectName LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# enable_testing()	# TODO: capaz tenga que mover esto mas tarde

# add_subdirectory(myApp)
add_subdirectory(myLib)