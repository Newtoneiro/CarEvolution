#ifndef CAREVOLUTION_CARBODY_H
#define CAREVOLUTION_CARBODY_H

#include "Figure.h"

/*
Autor: Radosław Kostrzewski
Cel: Plik naglowkowy ciała samochodu - obiektu reprezentującego
     kształt samochodu
*/
class CarBody : public Figure {
public:
    CarBody(const std::vector<unsigned int> &bodyRadiuses);

    void createBody() override;

    void updateShape() override;

    sf::Shape &getShape() override;

private:
    b2Vec2 _points[8];
    sf::ConvexShape _shape;
};


#endif //CAREVOLUTION_CARBODY_H