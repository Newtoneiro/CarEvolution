cmake_minimum_required(VERSION 3.23)
project(CarEvolution)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(app)
add_subdirectory(resources)

get_filename_component(ROOT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)
file(MAKE_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

