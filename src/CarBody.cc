#include "CarBody.h"

/*
Autor: Radoslaw Kostrzewski
Cel: Plik implementujący ciało samochodu - obiektu reprezentującego
     kształt samochodu
*/
void CarBody::createBody() {
    b2PolygonShape shape;
    shape.Set(_points, 8);
    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = 1.0f;
    fixture.friction = 0.3f;
    fixture.restitution = 0.5f;
    _body->CreateFixture(&fixture);
}

void CarBody::updateShape() {
    b2Vec2 position = _body->GetPosition();
    float angle = _body->GetAngle();
    _shape.setPosition(sf::Vector2f(position.x, position.y));
    _shape.setRotation((angle / (float) M_PI) * 180);
}

b2Vec2 CarBody::getLeftWheel() {
    return _points[3];
}

b2Vec2 CarBody::getRightWheel() {
    return _points[1];
}

sf::Shape &CarBody::getShape() { return _shape; }

CarBody::CarBody(const std::vector<unsigned int> &bodyRadiuses) : Figure() {
    _bodyDef.type = b2_dynamicBody;
    _shape.setPointCount(bodyRadiuses.size());
    
    const b2Vec2 center(100, 100);
    float angle = 0.f;
    int i = 0;
    for (auto radius: bodyRadiuses) {
        b2Vec2 newPoint(center.x + radius * cos(angle), center.y + radius * sin(angle));
        _points[i] = newPoint;
        _shape.setPoint(i, sf::Vector2f(newPoint.x, newPoint.y));
        angle += M_PI / 4;
        i++;
    }
}
