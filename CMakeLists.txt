# https://decovar.dev/blog/2021/03/08/cmake-cpp-library/

cmake_minimum_required(VERSION 3.16)

# project(myLib)
project(myLib LANGUAGES CXX)	# This sets CMAKE_PROJECT_NAME, but nested
								# calls changes PROJECT_NAME, CMAKE_PROJECT_NAME

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

# TODO: use variable to activate tests
enable_testing()
add_subdirectory(test)