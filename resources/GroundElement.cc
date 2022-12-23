#include "GroundElement.h"
#include "Figure.h"

/*
Autor: Radoslaw Kostrzewski
Cel: Plik implementujacy podloge - staly element
     bedacy przeszkoda dla dynamicznych obiektow i
     oddzialujacy z nimi
*/
GroundElement::GroundElement(float xPos, float rotation) {
    _bodyDef.position.Set(xPos, 400.0f);
    _bodyDef.angle = rotation;
};

GroundElement::~GroundElement() = default;

void GroundElement::setBody(b2Body *newBody) { _body = newBody; }

const b2BodyDef *GroundElement::getBodyDef() { return &_bodyDef; }

sf::RectangleShape GroundElement::getShape() {
    sf::RectangleShape sp;
    const float width = 100.f;
    const float height = 10.f;
    b2Vec2 position = _body->GetPosition();
    float rotation = _body->GetAngle();
    sp.setPosition(position.x + abs((width / 2) * cos(rotation)),
                   position.y - abs((width / 2) * sin(rotation) - height / 2));
    sp.setOrigin(width / 2, height / 2);
    sp.rotate((rotation / (float) M_PI) * 180);
    sp.setFillColor(sf::Color::Cyan);
    sp.setSize(sf::Vector2f(width, height));
    return sp;
}
