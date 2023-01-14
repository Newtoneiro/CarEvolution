#ifndef CAREVOLUTION_CARBODY_H
#define CAREVOLUTION_CARBODY_H

#include "../config/FigureCategories.h"
#include "../config/EnvironmentConfig.h"

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

    void setIsAlive(const bool val) noexcept { isAlive = val; };

    b2Vec2 getLeftWheel();

    b2Vec2 getRightWheel();

    sf::Shape &getShape() override;

    std::vector<unsigned int> getGenome() const noexcept { return genome; };

    bool isBodyAlive() const noexcept { return isAlive; };

private:
    bool isAlive = true;
    std::vector<unsigned int> genome;
    b2Vec2 points[8];
    sf::ConvexShape shape;
};

#endif //CAREVOLUTION_CARBODY_H
