#ifndef CAREVOLUTION_WORLD_H
#define CAREVOLUTION_WORLD_H

#include <memory>

#include "../config/GroundConfig.h"
#include "../config/EnvironmentConfig.h"

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

typedef std::shared_ptr<b2World> Pb2World;
typedef std::shared_ptr<Figure> PFigure;
typedef std::shared_ptr<Car> PCar;
typedef std::shared_ptr<b2RevoluteJointDef> PJoint;

class World {

public:
    explicit World();

    ~World();

    void createBody(const PFigure &fig, bool isGround);

    void createCar(const PCar &car);

    void createCars(int number);

    PCar updateCars();

    void updateElements();

    void step();

    void generateFloor();

    void respawnCars(const std::vector<Genome> &newPopulationGenome) noexcept;

    void setEndOfEpoch(const bool val) noexcept { endOfEpoch = val; }

    std::vector<PFigure> getElements();

    bool isEndOfEpoch() const noexcept { return endOfEpoch; }

    std::vector<PCar> getCurrentPopulation() const noexcept { return cars; };

    b2Vec2 getCameraPosition();

private:
    void carCreateWheels(const PCar &car);

    void destroyCar(const PCar &car);

    static void checkIfCarIsAlive(const PCar &car);

    Pb2World world;
    std::vector<PFigure> elements;
    std::vector<PFigure> ground;
    std::vector<PCar> cars;
    std::vector<PJoint> joints;
    bool endOfEpoch = false;
    PCar bestAliveCar;
};

#endif // CAREVOLUTION_WORLD_H
