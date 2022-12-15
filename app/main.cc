#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include <cstdio>
#include <iostream>
#include <vector>

#include "../resources/Circle.h"
#include "../resources/World.h"

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

  Circle circle1(8, 3.0f, 0.0f);
  Circle circle2(6);

  world.createBody(&circle1);
  world.createBody(&circle2);
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
    for (auto shape : world.getElements()) {
      window.draw(shape->getShape());
    }
    window.display();
  }
  return EXIT_SUCCESS;
}
