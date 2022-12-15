cmake_minimum_required(VERSION 3.22)
project(CarEvolution)
set(CMAKE_CXX_STANDARD 17)

get_filename_component(ROOT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)
file(MAKE_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

add_subdirectory(resources)

add_executable(CarEvolution app/main.cpp)
target_link_libraries(CarEvolution Resources box2d sfml-system sfml-graphics sfml-audio sfml-window)

enable_testing()

add_subdirectory(test)