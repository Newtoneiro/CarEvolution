#include "CarBody.h"

/*
Author: Bartosz Latosek
Purpose: A file containing implementation of CarBody - entity representing polynomial shape of car's body
*/
void CarBody::createBody() {
    b2PolygonShape shape;
    shape.Set(points, 8);
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = EnvironmentConfig::FIGURE_DENSITY;
    fixture.friction = EnvironmentConfig::FIGURE_FRICTION;
    fixture.restitution = EnvironmentConfig::FIGURE_RESTITUTION;
    fixture.filter.categoryBits = FigureCategories(carBodyCategory);
    fixture.filter.maskBits = FigureCategories(groundCategory);
    body->CreateFixture(&fixture);
}

void CarBody::updateShape() {
    if (isBodyAlive()) {
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        shape.setPosition(sf::Vector2f(position.x, position.y));
        shape.setRotation((angle / (float) M_PI) * 180);
    }
}

b2Vec2 CarBody::getLeftWheel() {
    return points[3];
}

b2Vec2 CarBody::getRightWheel() {
    return points[1];
}

sf::Shape &CarBody::getShape() { return shape; }

CarBody::CarBody(const std::vector<unsigned int> &bodyRadiuses) : Figure() {
    bodyDef.type = b2_dynamicBody;
    shape.setPointCount(bodyRadiuses.size());
    genome = bodyRadiuses;

    const b2Vec2 center(100, 100);
    float angle = 0.f;
    int i = 0;
    for (auto radius: bodyRadiuses) {
        b2Vec2 newPoint(center.x + radius * cos(angle), center.y + radius * sin(angle));
        points[i] = newPoint;
        shape.setPoint(i, sf::Vector2f(newPoint.x, newPoint.y));
        angle += M_PI / 4;
        ++i;
    }
}
