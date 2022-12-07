#ifndef CAREVOLUTION_CIRCLE_H
#define CAREVOLUTION_CIRCLE_H

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Figure.h"

class Circle : public Figure {
public:

    explicit Circle(float radius);

    Circle(float radius, float posX, float posY);

    float getRadius() const;

    void createBody() override;

    void updateShape() override;

    sf::Shape &getShape() override;

private:
    float _radius;
    sf::CircleShape _shape;

};


#endif //CAREVOLUTION_CIRCLE_H
