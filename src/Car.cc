#include "Car.h"

/*
Autor: Bartosz Latosek
Cel: Plik implementujący samochod - obiektu reprezentującego
     samochod
*/
Car::Car(const std::vector<unsigned int> &bodyRadiuses,
         const std::vector<float> &wheelRadiuses) {
    _carBody = std::make_shared<CarBody>(bodyRadiuses);
    _leftCircle = std::make_shared<Circle>(wheelRadiuses[0], _carBody->getLeftWheel().x, _carBody->getLeftWheel().y);
    _rightCircle = std::make_shared<Circle>(wheelRadiuses[1], _carBody->getRightWheel().x, _carBody->getRightWheel().y);
}

void Car::updateShape() noexcept {
    if (_isAlive) {
        _carBody->updateShape();
        _leftCircle->updateShape();
        _rightCircle->updateShape();
    }
}

PCarBody Car::getCarBody() const noexcept {
    return _carBody;
}

PCircle Car::getLeftCircle() const noexcept {
    return _leftCircle;
}

PCircle Car::getRightCircle() const noexcept {
    return _rightCircle;
}

void Car::setIsCarAlive(bool alive) noexcept {
    _isAlive = alive;
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

