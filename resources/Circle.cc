#include "Circle.h"

/*
Author: Bartosz Latosek
Purpose: This is a implementation of specialisation of figure class representing a circle
*/
Circle::Circle(float radius, float posX = 0.0f, float posY = 0.0f)
    : _radius(radius), Figure() {
  _bodyDef.position.Set(posX, posY);
  _shape.setRadius(radius);
}

Circle::Circle(float radius) : _radius(radius), Figure() {
  _shape.setRadius(radius);
}

float Circle::getRadius() const { return _radius; }

void Circle::createBody() {
  b2CircleShape shape;
  shape.m_radius = _radius;
  b2FixtureDef fixture;
  fixture.shape = &shape;
  fixture.density = 1.0f;
  fixture.friction = 0.3f;
  fixture.restitution = 0.5f;
  _body->CreateFixture(&fixture);
}

void Circle::updateShape() {
  b2Vec2 position = _body->GetPosition();
  _shape.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Shape &Circle::getShape() { return _shape; }
