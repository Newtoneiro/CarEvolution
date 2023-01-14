cmake_minimum_required(VERSION 3.22)
project(CarEvolution)
set(CMAKE_CXX_STANDARD 17)

get_filename_component(ROOT_DIR ${CMAKE_BINARY_DIR} DIRECTORY)
file(MAKE_DIRECTORY ${ROOT_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
if (CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    append_coverage_compiler_flags()
    set(COVERAGE_EXCLUDES
            ${PROJECT_SOURCE_DIR}/test/*
            ${PROJECT_SOURCE_DIR}/app/*
            )

    setup_target_for_coverage_gcovr_html(NAME Coverage EXECUTABLE Tests)
endif ()

add_subdirectory(src)
add_subdirectory(config)


add_executable(CarEvolution app/main.cc)
target_link_libraries(CarEvolution Source Config box2d sfml-system sfml-graphics sfml-audio sfml-window gcov)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

enable_testing()

add_subdirectory(test)