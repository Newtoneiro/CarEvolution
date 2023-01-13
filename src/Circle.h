#ifndef CAREVOLUTION_CIRCLE_H
#define CAREVOLUTION_CIRCLE_H

#include "../config/FigureCategories.h"
#include "../config/EnvironmentConfig.h"

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

#include "Figure.h"

/*
Author: Bartosz Latosek
Purpose: This is a header file for specialisation of figure class representing a circle
*/
class Circle : public Figure {
public:
    explicit Circle(float radius);

    Circle(float radius, float posX, float posY);

    float getRadius() const;

    void createBody() override;

    void updateShape() override;

    sf::Shape &getShape() override;

    bool isAlive() const noexcept { return _isAlive; };

    void setIsAlive(const bool val) noexcept { _isAlive = val; };

private:
    float _radius;
    sf::CircleShape _shape;
    bool _isAlive = true;
};

#endif // CAREVOLUTION_CIRCLE_H
