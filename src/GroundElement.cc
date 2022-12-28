#include "GroundElement.h"

/*
Autor: Radoslaw Kostrzewski
Cel: Plik implementujacy podloge - staly element
     bedacy przeszkoda dla dynamicznych obiektow i
     oddzialujacy z nimi
*/
GroundElement::GroundElement(float posX, float posY, float rotation) : Figure() {
    _bodyDef.type = b2_staticBody;
    _bodyDef.position.Set(posX, posY);
    _bodyDef.angle = rotation;
    _shape.setOrigin(GroundConfig::groundElementWidth / 2, GroundConfig::groundElementHeight / 2);
    _shape.setRotation((rotation / (float) M_PI) * 180);
    _shape.setFillColor(sf::Color::Cyan);
    _shape.setSize(sf::Vector2f(GroundConfig::groundElementWidth, GroundConfig::groundElementHeight));
}

void GroundElement::createBody() {
    b2PolygonShape shape;
    shape.SetAsBox(GroundConfig::groundElementWidth / 2, GroundConfig::groundElementHeight / 2);
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = 1.0f;
    fixture.friction = 0.7f;
    fixture.restitution = 0.5f;
    fixture.filter.categoryBits = FigureCategories(ground);
    _body->CreateFixture(&fixture);
}

void GroundElement::updateShape() {
    b2Vec2 position = _body->GetPosition();
    _shape.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Shape &GroundElement::getShape() { return _shape; }

