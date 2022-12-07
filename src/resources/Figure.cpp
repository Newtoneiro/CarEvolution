#include "Figure.h"

Figure::Figure() {
    _bodyDef.type = b2_dynamicBody;
}

Figure::~Figure() = default;

b2Body *Figure::getBody() {
    return _body;
}

b2Vec2 Figure::getPosition() {
    return _body->GetPosition();
}

void Figure::setBody(b2Body *newBody) {
    _body = newBody;
}

b2BodyDef Figure::getBodyDef() {
    return _bodyDef;
}


