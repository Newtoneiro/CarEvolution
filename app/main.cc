#include <iostream>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

#include "../src/EvolutionAlgorithm.h"
#include "../src/WindowHandle.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is a main file combining the logic and other aspects
         serving as presentation of app's purpose
*/
int main() {
    EvolutionAlgorithm algorithm;
    WindowHandle windowHandle;

    algorithm.init();

    while (windowHandle.isOpen() && !algorithm.isDone()) {
        sf::Event event{};
        while (windowHandle.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandle.close();
        }

        b2Vec2 view_pos = algorithm.updateWorld();
        windowHandle.step(view_pos, algorithm.getWorldElements(), algorithm.epoch());
    }
    return EXIT_SUCCESS;
}
