project(myLib)


add_subdirectory(src)

# TODO: use variable to activate tests
enable_testing()	# TODO: capaz tenga que mover esto mas tarde
add_subdirectory(test)