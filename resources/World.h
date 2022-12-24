#ifndef CAREVOLUTION_WORLD_H
#define CAREVOLUTION_WORLD_H

#include <box2d/b2_world.h>

#include "Figure.h"
#include "GroundElement.h"
#include "Car.h"
/*
Author: Radoslaw Kostrzewski
Purpose: This is the header file of world class responsible for
         providing a space for objects to interact with eachother
*/
class World {
public:
  explicit World(const b2World &world);

  ~World();

  void createBody(Figure *fig);

  void createCar(Car *car);

  b2World &getWorld();

  void updateElements();

  std::vector<Figure *> getElements();

  std::vector<GroundElement> getFloor();

  void step();

  void generateFloor();

private:
  void carCreateWheels(Car *car);

  b2World _world;
  std::vector<Figure *> _elements;
  std::vector<GroundElement> _ground;
};

#endif // CAREVOLUTION_WORLD_H
