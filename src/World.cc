#include "World.h"

#include <memory>
#include "../config/CarConfig.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is the implemenation of World class responsible for
         providing a space for objects to interact with eachother
*/

World::World() {
    world = std::make_shared<b2World>(b2Vec2(0.0f, EnvironmentConfig::GRAVITY));
}

void World::createBody(const PFigure &fig, bool isGround = false) {
    b2BodyDef bodyDef = fig->getBodyDef();
    b2Body *newBody = world->CreateBody(&bodyDef);
    fig->setBody(newBody);
    fig->createBody();
    elements.push_back(fig);
    if (isGround) {
        ground.push_back(fig);
    }
}

void World::createCar(const PCar &car) {
    createBody(car->getCarBody());
    createBody(car->getLeftCircle());
    createBody(car->getRightCircle());
    carCreateWheels(car);
    cars.push_back(car);
}

void World::destroyCar(const PCar &car) {
    world->DestroyBody(car->getCarBody()->getBody());
    world->DestroyBody(car->getLeftCircle()->getBody());
    world->DestroyBody(car->getRightCircle()->getBody());
}


void World::createCars(int number) {
    for (int i = 0; i < number; ++i) {
        std::vector<unsigned int> diameters;
        std::vector<float> radiuses;
        for (int j = 0; j < 8; ++j) {
            diameters.push_back(
                    rand() % (CarConfig::MAX_BODY_RADIUS - CarConfig::MIN_BODY_RADIUS) + CarConfig::MIN_BODY_RADIUS);
        }
        for (int j = 0; j < 2; ++j) {
            radiuses.push_back(
                    rand() % (CarConfig::MAX_WHEEL_RADIUS - CarConfig::MIN_WHEEL_RADIUS) + CarConfig::MIN_WHEEL_RADIUS);
        }
        createCar(std::make_shared<Car>(diameters, radiuses));
    }
}

void World::checkIfCarIsAlive(const PCar &car) {
    car->timerStep();
    auto speed = car->getCarBody()->getBody()->GetLinearVelocity();
    auto timer = car->getTime();
    if (abs(speed.x) < EnvironmentConfig::MINIMAL_SPEED && abs(speed.y) < EnvironmentConfig::MINIMAL_SPEED) {
        if (timer > EnvironmentConfig::MAX_TIME_ALIVE) {
            car->timerReset();
            car->setIsCarAlive(false);
        }
    } else {
        car->timerReset();
    }

}

PCar World::updateCars() {
    b2Vec2 firstCarPos = b2Vec2(-100, 0);
    PCar eliteCar;

    for (PCar &car: cars) {
        if (bestAliveCar == nullptr) {
            bestAliveCar = car;
        }
        auto currentPos = car->getCarBody()->getBody()->GetPosition();
        if (currentPos.x > firstCarPos.x) {
            firstCarPos = currentPos;
            eliteCar = car;
        }
        if (!car->isCarAlive()) continue;

        auto currentCameraPosition = bestAliveCar->getCarBody()->getBody()->GetPosition();
        if (currentPos.x > currentCameraPosition.x + 1 || !bestAliveCar->isCarAlive()) {
            bestAliveCar = car;
        }
        checkIfCarIsAlive(car);

    }
    if (std::all_of(cars.begin(), cars.end(), [](const PCar &car) { return !car->isCarAlive(); })) {
        setEndOfEpoch(true);
    }
    return eliteCar;
}

void World::updateElements() {
    for (PFigure &element: elements) {
        element->updateShape();
    }
}

std::vector<PFigure> World::getElements() {
    return elements;
}

void World::step() {
    world->Step(1.0f / EnvironmentConfig::FPS,
                 EnvironmentConfig::VELOCITY_ITERATIONS,
                 EnvironmentConfig::POSITION_ITERATIONS);
}

void World::generateFloor() {
    float curX = GroundConfig::GROUND_STARTING_X;
    float curY = GroundConfig::GROUND_STARTING_Y;
    for (int i = 0; i < GroundConfig::GROUND_ELEMENTS_NUMBER; ++i) {
        // Generating random angle from -maxStope to maxStope
        float newAngle = (-GroundConfig::MAX_STOPE + (rand() % int(2 * GroundConfig::MAX_STOPE - 1)));

        // Converting to radians
        newAngle = (newAngle / 180) * M_PI;

        if (i < GroundConfig::GROUND_MARGIN) {
            newAngle = 0;
        }

        curX += GroundConfig::GROUND_ELEMENT_WIDTH / 2 * cos(newAngle);
        curY += GroundConfig::GROUND_ELEMENT_WIDTH / 2 * sin(newAngle);

        PFigure elem = std::make_shared<GroundElement>(curX, curY, newAngle);
        createBody(elem, true);

        curX += GroundConfig::GROUND_ELEMENT_WIDTH / 2 * cos(newAngle);
        curY += GroundConfig::GROUND_ELEMENT_WIDTH / 2 * sin(newAngle);

    }
}

void World::respawnCars(const std::vector<Genome> &newPopulationGenome) noexcept {
    for (const auto &car: cars) {
        destroyCar(car);
    }
    cars.clear();
    joints.clear();
    elements.clear();
    std::copy(ground.begin(), ground.end(), std::back_inserter(elements));
    for (const Genome &genome: newPopulationGenome) {
        createCar(std::make_shared<Car>(genome.first, genome.second));
    }
}

void World::carCreateWheels(const PCar &car) {
    PJoint leftWheelJoint = std::make_shared<b2RevoluteJointDef>();
    PJoint rightWheelJoint = std::make_shared<b2RevoluteJointDef>();

    joints.push_back(leftWheelJoint);
    joints.push_back(rightWheelJoint);

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

    world->CreateJoint(leftWheelJoint.get());
    world->CreateJoint(rightWheelJoint.get());
}

b2Vec2 World::getCameraPosition() {
    return bestAliveCar->getRightCircle()->getBody()->GetPosition();
}

World::~World() = default;
