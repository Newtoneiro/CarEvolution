# Misc
cmake_minimum_required(VERSION 3.23)
project(CarEvolution)
set(CMAKE_CXX_STANDARD 14)

# Libraries
include(FetchContent)

if (EXISTS ${CMAKE_BINARY_DIR}/_deps)
    set(FETCHCONTENT_FULLY_DISCONNECTED 1)
endif ()


## SDL
FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG main
)

## Box2d
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG main
)

FetchContent_MakeAvailable(SDL2 box2d)


get_filename_component(ROOT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)
file(MAKE_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

add_executable(CarEvolution src/main.cpp)
target_link_libraries(CarEvolution SDL2 box2d)
