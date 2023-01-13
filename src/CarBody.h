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

    b2Vec2 getLeftWheel();

    b2Vec2 getRightWheel();

    sf::Shape &getShape() override;

    std::vector<unsigned int> getGenome() const noexcept { return _genome; };

    bool isAlive() const noexcept { return _isAlive; };

    void setIsAlive(const bool val) noexcept { _isAlive = val; };
private:
    std::vector<unsigned int> _genome;
    b2Vec2 _points[8];
    sf::ConvexShape _shape;
    bool _isAlive = true;
};


#endif //CAREVOLUTION_CARBODY_H
