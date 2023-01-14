#include "Circle.h"

/*
Author: Bartosz Latosek
Purpose: This is a implementation of specialisation of figure class representing a circle
*/
Circle::Circle(float radius, float posX = 0.0f, float posY = 0.0f)
        : Figure(), radius(radius) {
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(posX, posY);
    shape.setOrigin(radius, radius);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Magenta);
}

Circle::Circle(float radius) : Figure(), radius(radius) {
    shape.setOrigin(radius, radius);
    shape.setRadius(radius);
}

float Circle::getRadius() const { return radius; }

void Circle::createBody() {
    b2CircleShape shape;
    shape.m_radius = radius;
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = EnvironmentConfig::FIGURE_DENSITY;
    fixture.friction = EnvironmentConfig::FIGURE_FRICTION;
    fixture.restitution = EnvironmentConfig::FIGURE_RESTITUTION;
    fixture.filter.categoryBits = FigureCategories(circleCategory);
    fixture.filter.maskBits = FigureCategories(groundCategory);
    body->CreateFixture(&fixture);
}

void Circle::updateShape() {
    if (isCircleAlive()) {
        b2Vec2 position = body->GetPosition();
        shape.setPosition(sf::Vector2f(position.x, position.y));
        // Let the circle spin
        body->SetAngularVelocity(1.0f);
    }
}
