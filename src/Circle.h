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

    void createBody() override;
    
    void setIsAlive(const bool val) noexcept { isAlive = val; };

    void updateShape() override;

    float getRadius() const;

    sf::Shape & getShape() override { return shape; };

    bool isCircleAlive() const noexcept { return isAlive; };

private:
    bool isAlive = true;
    sf::CircleShape shape;
    float radius;
};

#endif // CAREVOLUTION_CIRCLE_H
