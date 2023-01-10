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
    car->setCarAlive(true);
    createBody(car->getCarBody());
    createBody(car->getLeftCircle());
    createBody(car->getRightCircle());
    carCreateWheels(car);
    _cars.push_back(car);
}

void World::createCars(int number) {
    srand(time(nullptr));
    for (int i = 0; i < number; i++) {
        std::vector<unsigned int> diameters;
        std::vector<float> radiuses;
        for (int j = 0; j < 8; j++) {
            diameters.push_back(rand() % (CarConfig().maxDiameter - CarConfig().minDiameter) + CarConfig().minDiameter);
        }
        for (int j = 0; j < 2; j++) {
            radiuses.push_back(rand() % (CarConfig().maxRadius - CarConfig().minRadius) + CarConfig().minRadius);
        }
        createCar(std::make_shared<Car>(diameters, radiuses));
    }
}

b2Vec2 World::destroyCars() {
    b2Vec2 firstCarPos = b2Vec2(-100, 0);
    for (const PCar &car: _cars) {
        if (!car->isCarAlive()) break;

        auto currentPos = car->getCarBody()->getBody()->GetPosition();
        if (std::max(currentPos.x, firstCarPos.x) == currentPos.x) { firstCarPos = currentPos; }
        car->timerStep();
        auto speed = car->getCarBody()->getBody()->GetLinearVelocity();
        auto timer = car->getTime();
        if (abs(speed.x) < 1 && abs(speed.y) < 1) {
            if (timer > 3600) {
                _world->DestroyBody(car->getCarBody()->getBody());
                _world->DestroyBody(car->getLeftCircle()->getBody());
                _world->DestroyBody(car->getRightCircle()->getBody());
                car->setCarAlive(false);
                car->timerReset();
            }
        } else {
            car->timerReset();
        }
    }
    return firstCarPos;
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
        float newAngle = (-maxStope + (rand() % int(2 * maxStope - 1)));

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
