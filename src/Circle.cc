#include "Circle.h"
#include "../config/CarConfig.h"

/*
Author: Bartosz Latosek
Purpose: This is a implementation of specialisation of figure class representing a circle
*/
Circle::Circle(float radius, float posX = 0.0f, float posY = 0.0f)
        : Figure(), radius_(radius) {
    bodyDef_.type = b2_dynamicBody;
    bodyDef_.position.Set(posX, posY);
    shape_.setOrigin(radius, radius);
    shape_.setRadius(radius);
    shape_.setFillColor(sf::Color::Magenta);
}

Circle::Circle(float radius) : Figure(), radius_(radius) {
    shape_.setOrigin(radius, radius);
    shape_.setRadius(radius);
}

float Circle::getRadius() const { return radius_; }

void Circle::createBody() {
    b2CircleShape shape;
    shape.m_radius = radius_;
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = EnvironmentConfig::FIGURE_DENSITY;
    fixture.friction = EnvironmentConfig::FIGURE_FRICTION;
    fixture.restitution = EnvironmentConfig::FIGURE_RESTITUTION;
    fixture.filter.categoryBits = FigureCategories(circleCategory);
    fixture.filter.maskBits = FigureCategories(groundCategory);
    body_->CreateFixture(&fixture);
}

void Circle::updateShape() {
    if (isCircleAlive()) {
        b2Vec2 position = body_->GetPosition();
        shape_.setPosition(sf::Vector2f(position.x, position.y));
        // Let the circle spin
        body_->SetAngularVelocity(CarConfig::CAR_VELOCITY);
        body_->SetAngularDamping(CarConfig::CAR_VELOCITY);
    }
}
