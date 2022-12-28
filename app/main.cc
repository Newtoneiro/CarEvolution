#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include <vector>

#include "../src/CarBody.h"
#include "../src/Car.h"
#include "../src/Circle.h"
#include "../src/World.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is a main file combining the logic and other aspects
         serving as presentation of app's purpose
*/
constexpr unsigned int WINDOW_WIDTH_PIXELS = 600;
constexpr float WINDOW_WIDTH = 10.0;
constexpr unsigned int PIXELS_PER_UNIT = WINDOW_WIDTH_PIXELS / WINDOW_WIDTH;
constexpr float BOX_WIDTH = 1.0;
constexpr int GRAVITY = 9;
constexpr uint32 VELOCITY_ITERATIONS = 6;
constexpr uint32 POSITION_ITERATIONS = 2;

const float FPS = 60;

int main(int argc, char *argv[]) {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    World world(*new b2World(b2Vec2(0.0f, GRAVITY)));

    std::vector<unsigned int> test = {
            25, 50, 25, 50, 25, 15, 15, 15
    };

    std::vector<unsigned int> test3 = {
            25, 50, 35, 20, 25, 35, 15, 15
    };

    std::vector<unsigned int> test5 = {
            15, 50, 25, 30, 20, 15, 25, 15
    };

    std::vector<float> test2 = {
            30, 30
    };

    std::vector<float> test4 = {
            10, 20
    };

    std::vector<float> test6 = {
            35, 15
    };

//    Circle testCirc(50, 250, 0);
    Car car(test, test2);
    Car car2(test3, test4);
    Car car3(test5, test6);
    world.createCar(&car);
    world.createCar(&car2);
    world.createCar(&car3);
//    world.createBody(&testCirc);

    world.generateFloor();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        world.step();
        world.updateElements();
        window.clear();

        for (auto shape: world.getElements()) {
            window.draw(shape->getShape());
        }

        car.timerStep();
        car2.timerStep();
        car3.timerStep();
        world.destroyCar(&car);
        world.destroyCar(&car2);
        world.destroyCar(&car3);
        window.display();
    }
    return EXIT_SUCCESS;
}
