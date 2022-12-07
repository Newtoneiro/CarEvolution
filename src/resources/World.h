#ifndef CAREVOLUTION_WORLD_H
#define CAREVOLUTION_WORLD_H

#include <box2d/b2_world.h>
#include "Figure.h"
#include "GroundElement.hpp"

class World {
public:

    explicit World(const b2World &world);

    ~World();

    void createBody(Figure *fig);

    b2World &getWorld();

    void updateElements();

    std::vector<Figure *> getElements();

    std::vector<GroundElement> getFloor();

    void step();

    void generateFloor();


private:
    b2World _world;
    std::vector<Figure *> _elements;
    std::vector<GroundElement> _ground;

};

#endif //CAREVOLUTION_WORLD_H
