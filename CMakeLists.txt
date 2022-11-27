# Misc
cmake_minimum_required(VERSION 3.23)
project(CarEvolution)
set(CMAKE_CXX_STANDARD 14)

# Libraries
include(FetchContent)

if (EXISTS ${CMAKE_BINARY_DIR}/_deps)
    set(FETCHCONTENT_FULLY_DISCONNECTED 1)
endif ()


## Box2d
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG main
)

FetchContent_MakeAvailable(box2d)

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

get_filename_component(ROOT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)
file(MAKE_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

add_executable(CarEvolution src/main.cpp)
target_link_libraries(CarEvolution box2d ${SDL2_LIBRARIES})
