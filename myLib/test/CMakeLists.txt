# GTest include code would
# go somewhere in here

set(TEST_NAME tests_myLib)


add_executable(
	${TEST_NAME}
	test_myLib.cpp
)

target_link_libraries(
	${TEST_NAME}
	PRIVATE
	GTest::GTest
	${PROJECT_NAME}
)

add_test(${TEST_NAME} ${TEST_NAME})