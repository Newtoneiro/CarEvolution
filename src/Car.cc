#include "Car.h"

/*
Author: Bartosz Latosek
Purpose: A file containing implementation of Car entity - main evolution target of the code
*/
Car::Car(const std::vector<unsigned int> &bodyRadiuses,
         const std::vector<float> &wheelRadiuses) {
    carBody = std::make_shared<CarBody>(bodyRadiuses);
    leftCircle = std::make_shared<Circle>(wheelRadiuses[0], carBody->getLeftWheel().x, carBody->getLeftWheel().y);
    rightCircle = std::make_shared<Circle>(wheelRadiuses[1], carBody->getRightWheel().x, carBody->getRightWheel().y);
}

void Car::updateShape() noexcept {
    if (isAlive) {
        carBody->updateShape();
        leftCircle->updateShape();
        rightCircle->updateShape();
    }
}

PCarBody Car::getCarBody() const noexcept {
    return carBody;
}

PCircle Car::getLeftCircle() const noexcept {
    return leftCircle;
}

PCircle Car::getRightCircle() const noexcept {
    return rightCircle;
}

void Car::setIsCarAlive(bool alive) noexcept {
    isAlive = alive;
    getCarBody()->setIsAlive(alive);
    getLeftCircle()->setIsAlive(alive);
    getRightCircle()->setIsAlive(alive);
    if (!alive) {
        getCarBody()->getShape().setFillColor(sf::Color::Blue);
    } else {
        getCarBody()->getShape().setFillColor(sf::Color::White);
    }
}

Genome Car::getGenome() const noexcept {
    return std::make_pair(getCarBody()->getGenome(), getWheelsGenome());
}

std::vector<float> Car::getWheelsGenome() const noexcept {
    std::vector<float> wheelRadiuses;
    wheelRadiuses.push_back(getLeftCircle()->getRadius());
    wheelRadiuses.push_back(getRightCircle()->getRadius());

    return wheelRadiuses;
}

