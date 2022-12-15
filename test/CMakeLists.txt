find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(ExampleTests ExampleTests.cc)
target_link_libraries(ExampleTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
add_test(NAME ExampleTests COMMAND ExampleTests)