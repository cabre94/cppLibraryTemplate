cmake_minimum_required(VERSION 3.16)


# project(myLib)
project(myLib LANGUAGES CXX)	# This sets CMAKE_PROJECT_NAME, but nested
									# calls changes PROJECT_NAME, CMAKE_PROJECT_NAME

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# # TODO: use variable to activate tests
# enable_testing()	# TODO: no entiendo porque esto es necesario aca








add_subdirectory(src)

# TODO: use variable to activate tests
enable_testing()	# TODO: capaz tenga que mover esto mas tarde
add_subdirectory(test)