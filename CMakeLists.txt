cmake_minimum_required(VERSION 3.16)

project(projectName LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# TODO: use variable to activate tests
enable_testing()	# TODO: no entiendo porque esto es necesario aca

add_subdirectory(myLib)

# add_subdirectory(myApp)