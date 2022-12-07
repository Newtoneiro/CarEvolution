set(CXX_CLANG_TIDY)
add_executable(CarEvolution main.cpp)
target_link_libraries(CarEvolution Resources box2d sfml-system sfml-graphics sfml-audio sfml-window)
