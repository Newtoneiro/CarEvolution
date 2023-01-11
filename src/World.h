#ifndef CAREVOLUTION_WORLD_H
#define CAREVOLUTION_WORLD_H

#include <memory>

#include "../config/GroundConfig.h"
#include "../config/EnviromentConfig.h"

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

typedef std::shared_ptr<b2World> PWorld;
typedef std::shared_ptr<Figure> PFigure;
typedef std::shared_ptr<Car> PCar;
typedef std::shared_ptr<b2RevoluteJointDef> PJoint;

class World {

public:
    explicit World();

    ~World();

    void createBody(const PFigure &fig);

    void createCar(const PCar &car);

    void createCars(int number);

    PCar updateCars();

    void updateElements();

    std::vector<PFigure> getElements();

    void step();

    void generateFloor();

    void respawnCars(const std::vector<Genome> &newPopulationGenome) noexcept;

    void setEndOfEpoch(const bool val) noexcept { _endOfEpoch = val; }

    bool isEndOfEpoch() const noexcept { return _endOfEpoch; }

    std::vector<PCar> getCurrentPopulation() const noexcept { return _cars; };

private:
    void carCreateWheels(const PCar &car);

    void respawnCar(const PCar &car);
    
    PWorld _world;
    std::vector<PFigure> _elements;
    std::vector<PCar> _cars;
    std::vector<PJoint> _joints;
    bool _endOfEpoch = false;
};

#endif // CAREVOLUTION_WORLD_H
