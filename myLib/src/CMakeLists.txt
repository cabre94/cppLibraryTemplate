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



target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
