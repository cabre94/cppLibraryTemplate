# find_package(PkgConfig)	# might be useful in future
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)  # Asegúrate de incluir el directorio con los headers

# pkg_search_module(dss-common REQUIRED IMPORTED_TARGET dss-common)	# PkgConfig

set(TEST_NAME tests_myLib)

add_executable(
	${TEST_NAME}
	test_myLib.cpp
)

target_link_directories(${TEST_NAME} PRIVATE ${CMAKE_BINARY_DIR}/src)

target_link_libraries(
	${TEST_NAME}
	PRIVATE
	GTest::GTest
	${GTEST_LIBRARIES}
	${PROJECT_NAME}	# Here add myLib
)

# Used to Debug
message(STATUS "test - GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")
message(STATUS "test - GTEST_LIBRARIES: ${GTEST_LIBRARIES}")
message(STATUS "test - PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "test - PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "test - CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# add_test(${TEST_NAME} ${TEST_NAME}) # this doesnt find tests in nested folders

# find tests in nested folders
include(GoogleTest)
gtest_discover_tests(${TEST_NAME} XML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/reports)