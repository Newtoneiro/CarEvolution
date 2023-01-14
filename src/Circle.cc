#include "Circle.h"

/*
Author: Bartosz Latosek
Purpose: This is a implementation of specialisation of figure class representing a circle
*/
Circle::Circle(float radius, float posX = 0.0f, float posY = 0.0f)
        : Figure(), _radius(radius) {
    _bodyDef.type = b2_dynamicBody;
    _bodyDef.position.Set(posX, posY);
    _shape.setOrigin(radius, radius);
    _shape.setRadius(radius);
    _shape.setFillColor(sf::Color::Magenta);
}

Circle::Circle(float radius) : Figure(), _radius(radius) {
    _shape.setOrigin(radius, radius);
    _shape.setRadius(radius);
}

float Circle::getRadius() const { return _radius; }

void Circle::createBody() {
    b2CircleShape shape;
    shape.m_radius = _radius;
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = EnvironmentConfig::FIGURE_DENSITY;
    fixture.friction = EnvironmentConfig::FIGURE_FRICTION;
    fixture.restitution = EnvironmentConfig::FIGURE_RESTITUTION;
    fixture.filter.categoryBits = FigureCategories(circleCategory);
    fixture.filter.maskBits = FigureCategories(groundCategory);
    _body->CreateFixture(&fixture);
}

void Circle::updateShape() {
    if (isAlive()) {
        b2Vec2 position = _body->GetPosition();
        _shape.setPosition(sf::Vector2f(position.x, position.y));
        // Let the circle spin
        _body->SetAngularVelocity(1.0f);
    }
}

sf::Shape &Circle::getShape() { return _shape; }
