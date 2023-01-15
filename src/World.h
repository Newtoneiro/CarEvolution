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

    void setEndOfEpoch(const bool val) noexcept { endOfEpoch_ = val; }

    std::vector<PFigure> getElements();

    bool isEndOfEpoch() const noexcept { return endOfEpoch_; }

    std::vector<PCar> getCurrentPopulation() const noexcept { return cars_; };

    b2Vec2 getCameraPosition();

private:
    void carCreateWheels(const PCar &car);

    void destroyCar(const PCar &car);

    static void checkIfCarIsAlive(const PCar &car);

    Pb2World world_;
    std::vector<PFigure> elements_;
    std::vector<PFigure> ground_;
    std::vector<PCar> cars_;
    std::vector<PJoint> joints_;
    bool endOfEpoch_ = false;
    PCar bestAliveCar_;
};

#endif // CAREVOLUTION_WORLD_H
