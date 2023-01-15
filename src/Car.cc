#include "Car.h"

/*
Author: Bartosz Latosek
Purpose: A file containing implementation of Car entity - main evolution target of the code
*/
Car::Car(const std::vector<unsigned int> &bodyRadiuses,
         const std::vector<float> &wheelRadiuses) {
    carBody_ = std::make_shared<CarBody>(bodyRadiuses);
    leftCircle_ = std::make_shared<Circle>(wheelRadiuses[0], carBody_->getLeftWheel().x, carBody_->getLeftWheel().y);
    rightCircle_ = std::make_shared<Circle>(wheelRadiuses[1], carBody_->getRightWheel().x, carBody_->getRightWheel().y);
}

void Car::updateShape() noexcept {
    if (isAlive_) {
        carBody_->updateShape();
        leftCircle_->updateShape();
        rightCircle_->updateShape();
    }
}

PCarBody Car::getCarBody() const noexcept {
    return carBody_;
}

PCircle Car::getLeftCircle() const noexcept {
    return leftCircle_;
}

PCircle Car::getRightCircle() const noexcept {
    return rightCircle_;
}

void Car::setIsCarAlive(bool alive) noexcept {
    isAlive_ = alive;
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

