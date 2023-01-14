#include <iostream>

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
    if (EnvironmentConfig::SEED == 0){
        srand(time(0));   
    }
    else{
        srand(EnvironmentConfig::SEED);
    }

    EvolutionAlgorithm algorithm;
    WindowHandle windowHandle;

    algorithm.init();

    while (windowHandle.isOpen() && !algorithm.isDone()) {
        sf::Event event{};
        while (windowHandle.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowHandle.close();
        }

        b2Vec2 viewPos = algorithm.updateWorld();
        windowHandle.step(viewPos, algorithm.getWorldElements(), algorithm.getCurEpoch());
    }
    return EXIT_SUCCESS;
}
