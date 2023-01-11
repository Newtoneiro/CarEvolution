#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include <vector>

#include "../src/CarBody.h"
#include "../src/Car.h"
#include "../src/World.h"
#include "../src/EvolutionAlgorithm.h"
#include "../src/WindowHandle.h"

#include "../config/EnviromentConfig.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is a main file combining the logic and other aspects
         serving as presentation of app's purpose
*/
int main(int argc, char *argv[]) {
    
    EvolutionAlgorithm algorithm;
    WindowHandle windowHandle;

    algorithm.init();

    while (windowHandle.isOpen()) {
        sf::Event event{};
        while (windowHandle.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandle.close();
        }

        b2Vec2 view_pos = algorithm.step();
        windowHandle.step(view_pos, algorithm.getWorldElements());
    }
    return EXIT_SUCCESS;
}
