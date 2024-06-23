# add_library(libraryName
#             [STATIC|SHARED|MODULE]
#             [EXCLUDE_FROM_ALL]
#             source1 source2 ....)

# The source files can be omitted if added later using ``target_sources()``

# .a STATIC
# .so SHARED, .dll on Windows

# add_library(${PROJECT_NAME} STATIC myLib.cpp)

add_library(${PROJECT_NAME} STATIC)

target_sources(
	${PROJECT_NAME}
	PRIVATE
	myLib.cpp
)




if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX is not set\n"
        "Default value: ${CMAKE_INSTALL_PREFIX}\n"
        "Will set it to ${CMAKE_SOURCE_DIR}/install"
    )
    set(CMAKE_INSTALL_PREFIX
        "${CMAKE_SOURCE_DIR}/install"
        CACHE PATH "Where the library will be installed to" FORCE
    )
else()
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX was already set\n"
        "Current value: ${CMAKE_INSTALL_PREFIX}"
    )
endif()


# without it public headers won't get installed
set(public_headers
    include/myLib.h
)
# note that ${public_headers} has to be in quotes
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

# when install headers, folder strcuture doestn preserve, check 
# https://decovar.dev/blog/2021/03/08/cmake-cpp-library/




message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
message(CMAKE_CURRENT_SOURCE_DIR/srr="${CMAKE_CURRENT_SOURCE_DIR}/src")
message(CMAKE_INSTALL_INCLUDEDIR="${CMAKE_INSTALL_INCLUDEDIR}")
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")


# target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}
        # ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Certainly, just building the library is already enough to be able to link to it, but we want to do it in the most comfortable way: not by providing paths to its binaries and headers from both build and sources directories, but by installing just the artifacts we need and using find_package command.

# With find_package you let CMake to worry about finding the library, its public headers and configuring all that. Here’s a more detailed documentation about how find_package works, and here’s how you can create a CMake config of your own.
