#include "Car.h"

/*
Autor: Bartosz Latosek
Cel: Plik implementujący samochod - obiektu reprezentującego
     samochod
*/
Car::Car(const std::vector<unsigned int> &bodyRadiuses,
         const std::vector<float> &wheelRadiuses) {
    _carBody = new CarBody(bodyRadiuses);
    _leftCircle = new Circle(wheelRadiuses[0], _carBody->getLeftWheel().x, _carBody->getLeftWheel().y);
    _rightCircle = new Circle(wheelRadiuses[1], _carBody->getRightWheel().x, _carBody->getRightWheel().y);
}

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

CarBody *Car::getCarBody() {
    return _carBody;
}

Circle *Car::getLeftCircle() {
    return _leftCircle;
}

Circle *Car::getRightCircle() {
    return _rightCircle;
}

sf::Shape &Car::getShape() { return _carBody->getShape(); }