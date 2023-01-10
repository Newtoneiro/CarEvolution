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

Car::~Car() = default;

void Car::createBody() {
    _carBody->createBody();
    _leftCircle->createBody();
    _rightCircle->createBody();
}

void Car::updateShape() {
    _carBody->updateShape();
    _leftCircle->updateShape();
    _rightCircle->updateShape();
}

PCarBody Car::getCarBody() {
    return _carBody;
}

PCircle Car::getLeftCircle() {
    return _leftCircle;
}

PCircle Car::getRightCircle() {
    return _rightCircle;
}

sf::Shape &Car::getShape() { return _carBody->getShape(); }

int Car::getTime() const {
    return _timer;
}

void Car::timerReset() {
    _timer = 0;
}

void Car::timerStep() {
    _timer++;
}

bool Car::isCarAlive() {
    return isAlive;
}

void Car::setCarAlive(bool alive) {
    isAlive = alive;
}

