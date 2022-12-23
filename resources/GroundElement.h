#ifndef CAREVOLUTION_GROUNDELEMENT_HPP
#define CAREVOLUTION_GROUNDELEMENT_HPP

#include "SFML/Graphics.hpp"
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>

/*
Autor: Radoslaw Kostrzewski
Cel: Plik naglowkowy podlogi - staly element
     bedacy przeszkoda dla dynamicznych obiektow i
     oddzialujacy z nimi
*/
class GroundElement {

public:
    explicit GroundElement(float xPos, float rotation);

    ~GroundElement();

    void setBody(b2Body *newBody);

    const b2BodyDef *getBodyDef();

    sf::RectangleShape getShape();

private:
    b2BodyDef _bodyDef;
    sf::RectangleShape _shape;
    b2Body *_body{};
};

#endif // CAREVOLUTION_GROUNDELEMENT_HPP