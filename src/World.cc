#include "World.h"

#include <memory>
#include "../config/CarConfig.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is the implemenation of World class responsible for
         providing a space for objects to interact with eachother
*/

World::World() {
    srand(time(0));
    _world = std::make_shared<b2World>(b2Vec2(0.0f, EnviromentConfig::GRAVITY));
}

void World::createBody(const PFigure &fig) {
    b2BodyDef bodyDef = fig->getBodyDef();
    b2Body *newBody = _world->CreateBody(&bodyDef);
    fig->setBody(newBody);
    fig->createBody();
    _elements.push_back(fig);
}

void World::createCar(const PCar &car) {
    car->setIsCarAlive(true);
    createBody(car->getCarBody());
    createBody(car->getLeftCircle());
    createBody(car->getRightCircle());
    carCreateWheels(car);
    _cars.push_back(car);
}

void World::respawnCar(const PCar &car) {
    b2Vec2 rightWheelPos = car->getCarBody()->getRightWheel();
    b2Vec2 leftWheelPos = car->getCarBody()->getLeftWheel();
    car->getCarBody()->getBody()->SetTransform(b2Vec2_zero, 0.0f);
    car->getLeftCircle()->getBody()->SetTransform(leftWheelPos, 0.0f);
    car->getRightCircle()->getBody()->SetTransform(rightWheelPos, 0.0f);
    car->setIsCarAlive(true);
}

void World::createCars(int number) {
    for (int i = 0; i < number; i++) {
        std::vector<unsigned int> diameters;
        std::vector<float> radiuses;
        for (int j = 0; j < 8; j++) {
            diameters.push_back(rand() % (CarConfig::MAX_DIAMETER - CarConfig::MIN_DIAMETER) + CarConfig::MIN_DIAMETER);
        }
        for (int j = 0; j < 2; j++) {
            radiuses.push_back(rand() % (CarConfig::MAX_RADIUS - CarConfig::MIN_RADIUS) + CarConfig::MIN_RADIUS);
        }
        createCar(std::make_shared<Car>(diameters, radiuses));
    }
}

PCar World::updateCars() {
    b2Vec2 firstCarPos = b2Vec2(-100, 0);
    PCar eliteCar;

    for (PCar &car: _cars) {
        if (!car->isCarAlive()) continue;

        auto currentPos = car->getCarBody()->getBody()->GetPosition();
        if (currentPos.x > firstCarPos.x) { 
            firstCarPos = currentPos;
            eliteCar = car;
        }
        car->timerStep();
        auto speed = car->getCarBody()->getBody()->GetLinearVelocity();
        auto timer = car->getTime();
        if (abs(speed.x) < 1 && abs(speed.y) < 1) {
            car->increaseInertiaTimer();
            if (car->isDeadFromInertia() || timer > EnviromentConfig::MAX_TIME_ALIVE) {
                car->timerReset();
                car->inertiaTimerReset();
                car->setIsCarAlive(false);
                // destroyCar(car);
            }
        } else {
            car->timerReset();
        }
    }
    if (std::all_of(_cars.begin(), _cars.end(), [](const PCar& car){return !car->isCarAlive();})) {
        setEndOfEpoch(true);
    }
    return eliteCar;
}

void World::updateElements() {
    for (PFigure &element: _elements) {
        element->updateShape();
    }
}

std::vector<PFigure> World::getElements() { return _elements; }

void World::step() {
    _world->Step(1.0f / EnviromentConfig::FPS,
                 EnviromentConfig::VELOCITY_ITERATIONS,
                 EnviromentConfig::POSITION_ITERATIONS);
}

void World::generateFloor() {
    float curX = 0.0f;
    float curY = 400.0f;
    for (int i = 0; i < 100; i++) {
        // Generating random angle from -maxStope to maxStope
        float newAngle = (-GroundConfig::MAX_STOPE + (rand() % int(2 * GroundConfig::MAX_STOPE - 1)));

        // Converting to radians
        newAngle = (newAngle / 180) * M_PI;

        if (i < 2) {
            newAngle = 0;
        }

        curX += GroundConfig::groundElementWidth / 2 * cos(newAngle);
        curY += GroundConfig::groundElementWidth / 2 * sin(newAngle);

        PFigure elem = std::make_shared<GroundElement>(curX, curY, newAngle);
        createBody(elem);

        curX += GroundConfig::groundElementWidth / 2 * cos(newAngle);
        curY += GroundConfig::groundElementWidth / 2 * sin(newAngle);

    }
}

void World::respawnCars(const std::vector<Genome> &newPopulationGenome) noexcept {
    std::vector<PCar> newPopulation;
    _cars = newPopulation;
    for (const Genome genome: newPopulationGenome) {
        createCar(std::make_shared<Car>(genome.first, genome.second));
    }
}

void World::carCreateWheels(const PCar &car) {
    PJoint leftWheelJoint = std::make_shared<b2RevoluteJointDef>();
    PJoint rightWheelJoint = std::make_shared<b2RevoluteJointDef>();

    _joints.push_back(leftWheelJoint);
    _joints.push_back(rightWheelJoint);

    leftWheelJoint->bodyA = car->getCarBody()->getBody();
    rightWheelJoint->bodyA = car->getCarBody()->getBody();

    leftWheelJoint->bodyB = car->getLeftCircle()->getBody();
    rightWheelJoint->bodyB = car->getRightCircle()->getBody();

    leftWheelJoint->localAnchorA = car->getCarBody()->getLeftWheel();
    rightWheelJoint->localAnchorA = car->getCarBody()->getRightWheel();

    leftWheelJoint->collideConnected = false;
    rightWheelJoint->collideConnected = false;

    leftWheelJoint->Initialize(leftWheelJoint->bodyA, leftWheelJoint->bodyB, leftWheelJoint->localAnchorA);
    rightWheelJoint->Initialize(rightWheelJoint->bodyA, rightWheelJoint->bodyB, rightWheelJoint->localAnchorA);

    _world->CreateJoint(leftWheelJoint.get());
    _world->CreateJoint(rightWheelJoint.get());
}

World::~World() = default;
