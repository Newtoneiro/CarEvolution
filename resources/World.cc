#include "World.h"
#include "Car.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is the implemenation of world class responsible for
         providing a space for objects to interact with eachother
*/
World::World(const b2World &world) : _world(world) {}

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

void World::step() { _world.Step(1.0f / 60, 6, 2); }

void World::generateFloor() {
    for (int i = 0; i < 10; i++) {
        auto elem = new GroundElement(i * 100, -M_PI / 72);
        b2Body *groundBody = _world.CreateBody(elem->getBodyDef());
        b2PolygonShape groundShape;
        groundShape.SetAsBox(100.0f, 10.0f);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &groundShape;
        fixtureDef.density = 0.0f;
        fixtureDef.restitution = 0.5f;
        groundBody->CreateFixture(&fixtureDef);
        elem->setBody(groundBody);
        _ground.push_back(*elem);
    }
}

void World::carCreateWheels(Car *car) {
    b2RevoluteJointDef* leftWheelJoint = new b2RevoluteJointDef();
    b2RevoluteJointDef* rightWheelJoint = new b2RevoluteJointDef();
    
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

std::vector<GroundElement> World::getFloor() { return _ground; }

World::~World() = default;
