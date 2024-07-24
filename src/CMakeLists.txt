# add_library(libraryName
#             [STATIC|SHARED|MODULE]
#             [EXCLUDE_FROM_ALL]
#             source1 source2 ....)

# The source files can be omitted if added later using ``target_sources()``

# .a STATIC
# .so SHARED, .dll on Windows

# add_library(${PROJECT_NAME} STATIC Complex.cpp)

add_library(${PROJECT_NAME} STATIC)

target_sources(
	${PROJECT_NAME}
	PRIVATE
	Complex.cpp
)

# definitions of CMAKE_INSTALL_LIBDIR, CMAKE_INSTALL_INCLUDEDIR and others
include(GNUInstallDirs)

# overwrite default installation path to install the artifacts into install folder
# if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#     message(
#         STATUS
#         "CMAKE_INSTALL_PREFIX is not set\n"
#         "Default value: ${CMAKE_INSTALL_PREFIX}\n" # --> /usr/local
#         "Will set it to ${CMAKE_SOURCE_DIR}/install"
#     )
#     set(CMAKE_INSTALL_PREFIX
#         "${CMAKE_SOURCE_DIR}/install"
#         CACHE PATH "Where the library will be installed to" FORCE
#     )
# else()
#     message(
#         STATUS
#         "CMAKE_INSTALL_PREFIX was already set\n"
#         "Current value: ${CMAKE_INSTALL_PREFIX}"
#     )
# endif()


# without it public headers won't get installed
set(public_headers
	${PROJECT_SOURCE_DIR}/include/Complex.h
)

# Option 1
# note that ${public_headers} has to be in quotes
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

# Option 2
# the variant with PUBLIC_HEADER property unfortunately does not preserve the folder structure
#set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")
# so instead we iterate through public headers and install them "manually"
# foreach(header ${public_headers})
#     file(RELATIVE_PATH header_file_path "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}" "${header}")
#     get_filename_component(header_directory_path "${header_file_path}" DIRECTORY)
#     install(
#         FILES ${header}
#         DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${header_directory_path}"
#     )
# endforeach()


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

# Used to Debug
message(STATUS "src - PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "src - PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "src - CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# Certainly, just building the library is already enough to be able to link to
# it, but we want to do it in the most comfortable way: not by providing paths
# to its binaries and headers from both build and sources directories, but by 
# installing just the artifacts we need and using find_package command.

# With find_package you let CMake to worry about finding the library, its public
# headers and configuring all that. Here’s a more detailed documentation about 
# how find_package works, and here’s how you can create a CMake config of your own.


########################################################
#### Here come the actual installation instructions: ###
########################################################

# install the target and create export-set
install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}Targets"
    # these get default values from GNUInstallDirs, no need to set them
    #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # bin
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    #ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    # except for public headers, as we want them to be inside a library folder
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME} # include/SomeLibrary
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} # include
)