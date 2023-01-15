#include "GroundElement.h"

/*
Author: Radoslaw Kostrzewski
Purpose: This is file containing the implementation of single ground block - a static rectangle
         that serves as a wall stoping dynamic objects from moving and interacting with them
*/
GroundElement::GroundElement(float posX, float posY, float rotation) : Figure() {
    bodyDef_.type = b2_staticBody;
    bodyDef_.position.Set(posX, posY);
    bodyDef_.angle = rotation;
    shape_.setOrigin(GroundConfig::GROUND_ELEMENT_WIDTH / 2, GroundConfig::GROUND_ELEMENT_HEIGHT / 2);
    shape_.setRotation((rotation / (float) M_PI) * 180);
    shape_.setFillColor(sf::Color::Cyan);
    shape_.setSize(sf::Vector2f(GroundConfig::GROUND_ELEMENT_WIDTH, GroundConfig::GROUND_ELEMENT_HEIGHT));
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
    body_->CreateFixture(&fixture);
}

void GroundElement::updateShape() {
    b2Vec2 position = body_->GetPosition();
    shape_.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Shape &GroundElement::getShape() { return shape_; }

