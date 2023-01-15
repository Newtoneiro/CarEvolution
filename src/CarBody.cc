#include "CarBody.h"

/*
Author: Bartosz Latosek
Purpose: A file containing implementation of CarBody - entity representing polynomial shape of car's body
*/
void CarBody::createBody() {
    b2PolygonShape shape;
    shape.Set(points_, 8);
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = EnvironmentConfig::FIGURE_DENSITY;
    fixture.friction = EnvironmentConfig::FIGURE_FRICTION;
    fixture.restitution = EnvironmentConfig::FIGURE_RESTITUTION;
    fixture.filter.categoryBits = FigureCategories(carBodyCategory);
    fixture.filter.maskBits = FigureCategories(groundCategory);
    body_->CreateFixture(&fixture);
}

void CarBody::updateShape() {
    if (isBodyAlive()) {
        b2Vec2 position = body_->GetPosition();
        float angle = body_->GetAngle();
        shape_.setPosition(sf::Vector2f(position.x, position.y));
        shape_.setRotation((angle / (float) M_PI) * 180);
    }
}

b2Vec2 CarBody::getLeftWheel() {
    return points_[3];
}

b2Vec2 CarBody::getRightWheel() {
    return points_[1];
}

sf::Shape &CarBody::getShape() { return shape_; }

CarBody::CarBody(const std::vector<unsigned int> &bodyRadiuses) : Figure() {
    bodyDef_.type = b2_dynamicBody;
    shape_.setPointCount(bodyRadiuses.size());
    genome_ = bodyRadiuses;

    const b2Vec2 center(100, 100);
    float angle = 0.f;
    int i = 0;
    for (auto radius: bodyRadiuses) {
        b2Vec2 newPoint(center.x + radius * cos(angle), center.y + radius * sin(angle));
        points_[i] = newPoint;
        shape_.setPoint(i, sf::Vector2f(newPoint.x, newPoint.y));
        angle += M_PI / 4;
        ++i;
    }
}
