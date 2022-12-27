#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include <vector>

#include "../src/CarBody.h"
#include "../src/Car.h"
#include "../src/Circle.h"
#include "../src/World.h"

#include "../config/EnviromentConfig.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is a main file combining the logic and other aspects
         serving as presentation of app's purpose
*/
int main(int argc, char *argv[]) {

    sf::RenderWindow window(sf::VideoMode({EnviromentConfig::WINDOW_WIDTH,
                                           EnviromentConfig::WINDOW_HEIGHT}), "SFML window");

    World world(*new b2World(b2Vec2(0.0f, EnviromentConfig::GRAVITY)));

    std::vector<unsigned int> test = {
            25, 50, 25, 50, 25, 15, 15, 15
    };

    std::vector<float> test2 = {
            30, 30
    };

//    Circle testCirc(50, 250, 0);
    Car car(test, test2);
    world.createCar(&car);
//    world.createBody(&testCirc);

    world.generateFloor();

    sf::View view(sf::Vector2f(EnviromentConfig::WINDOW_WIDTH / 2,
                                EnviromentConfig::WINDOW_HEIGHT / 2),
                   sf::Vector2f(EnviromentConfig::WINDOW_WIDTH,
                                EnviromentConfig::WINDOW_HEIGHT));
    window.setView(view);
    
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

        b2Vec2 pos = car.getCarBody()->getBody()->GetPosition();
        view.setCenter(pos.x + 100, pos.y + 100);
        window.setView(view);

        window.display();
    }
    return EXIT_SUCCESS;
}
