find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Tests ExampleTests.cc CarTest.cc)
target_link_libraries(Tests Source Config box2d sfml-system sfml-graphics sfml-audio sfml-window ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
add_test(NAME CarTest COMMAND Tests)
add_test(NAME Tests COMMAND Tests)