# Misc
cmake_minimum_required(VERSION 3.23)
project(CarEvolution)
set(CMAKE_CXX_STANDARD 17)

# Libraries
include(FetchContent)

#if (EXISTS ${CMAKE_BINARY_DIR}/_deps)
#    set(FETCHCONTENT_FULLY_DISCONNECTED 1)
#endif ()


## Box2d
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG main
)

## sfml
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
)

FetchContent_MakeAvailable(box2d)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(src/app)
add_subdirectory(src/resources)

get_filename_component(ROOT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)
file(MAKE_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

