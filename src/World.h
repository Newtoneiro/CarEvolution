#ifndef CAREVOLUTION_WORLD_H
#define CAREVOLUTION_WORLD_H

#include "../config/GroundConfig.h"

#include <box2d/b2_world.h>
#include <box2d/b2_math.h>

#include "Figure.h"
#include "GroundElement.h"
#include "Car.h"
#include "random"

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

    void updateElements();

    std::vector<Figure *> getElements();

    void step();

    void generateFloor();

private:
    static constexpr float maxStope = 70.0f;

    void carCreateWheels(Car *car);

    b2World _world;
    std::vector<Figure *> _elements;
};

#endif // CAREVOLUTION_WORLD_H
