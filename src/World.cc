#include "World.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is the implemenation of world class responsible for
         providing a space for objects to interact with eachother
*/
World::World(const b2World &world) : _world(world) { srand(time(0)); }

void World::createBody(Figure *fig) {
    b2BodyDef bodyDef = fig->getBodyDef();
    b2Body *newBody = _world.CreateBody(&bodyDef);
    fig->setBody(newBody);
    fig->createBody();
    _elements.push_back(fig);
}

void World::createCar(Car *car) {
    createBody(car->getCarBody());
    createBody(car->getLeftCircle());
    createBody(car->getRightCircle());
    carCreateWheels(car);
}

b2World &World::getWorld() { return _world; }

void World::updateElements() {
    for (auto &element: _elements) {
        element->updateShape();
    }
}

std::vector<Figure *> World::getElements() { return _elements; }

void World::step() {
    _world.Step(1.0f / 120, 6, 2);
}

void World::generateFloor() {
    float curX = 0.0f;
    float curY = 400.0f;
    for (int i = 0; i < 10; i++) {
        // Generating random angle from -maxStope to maxStope
        float newAngle = (-maxStope + (rand() % int(2 * maxStope - 1)));

        // Converting to radians
        newAngle = (newAngle / 180) * M_PI;

        if (i < 2) {
            newAngle = 0;
        }

        curX += GroundConfig::groundElementWidth / 2 * cos(newAngle);
        curY += GroundConfig::groundElementWidth / 2 * sin(newAngle);

        auto elem = new GroundElement(curX, curY, newAngle);
        createBody(elem);

        curX += GroundConfig::groundElementWidth / 2 * cos(newAngle);
        curY += GroundConfig::groundElementWidth / 2 * sin(newAngle);

    }
}

void World::carCreateWheels(Car *car) {
    b2RevoluteJointDef *leftWheelJoint = new b2RevoluteJointDef();
    b2RevoluteJointDef *rightWheelJoint = new b2RevoluteJointDef();

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

    _world.CreateJoint(leftWheelJoint);
    _world.CreateJoint(rightWheelJoint);
}

World::~World() = default;
