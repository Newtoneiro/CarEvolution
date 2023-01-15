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

    void updateShape() override;

    sf::Shape &getShape() override { return shape_; };

    float getRadius() const;

    void setIsAlive(const bool val) noexcept { isAlive_ = val; };

    bool isCircleAlive() const noexcept { return isAlive_; };

private:
    bool isAlive_ = true;
    sf::CircleShape shape_;
    float radius_;
};

#endif // CAREVOLUTION_CIRCLE_H
