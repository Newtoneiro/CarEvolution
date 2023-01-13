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
    _shape.setOrigin(GroundConfig::GROUND_ELEMENT_WIDTH / 2, GroundConfig::GROUND_ELEMENT_HEIGHT / 2);
    _shape.setRotation((rotation / (float) M_PI) * 180);
    _shape.setFillColor(sf::Color::Cyan);
    _shape.setSize(sf::Vector2f(GroundConfig::GROUND_ELEMENT_WIDTH, GroundConfig::GROUND_ELEMENT_HEIGHT));
}

void GroundElement::createBody() {
    b2PolygonShape shape;
    shape.SetAsBox(GroundConfig::GROUND_ELEMENT_WIDTH / 2, GroundConfig::GROUND_ELEMENT_HEIGHT / 2);
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = EnvironmentConfig::FIGURE_DENSITY;
    fixture.friction = EnvironmentConfig::FIGURE_FRICTION;
    fixture.restitution = EnvironmentConfig::FIGURE_RESTITUTION;
    fixture.filter.categoryBits = FigureCategories(groundCategory);
    _body->CreateFixture(&fixture);
}

void GroundElement::updateShape() {
    b2Vec2 position = _body->GetPosition();
    _shape.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Shape &GroundElement::getShape() { return _shape; }

