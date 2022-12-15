#include "GroundElement.h"
#include "Figure.h"

GroundElement::GroundElement(float xPos) {
    _bodyDef.position.Set(xPos, 800.0f);
    _bodyDef.angle = M_PI / 18;
};

GroundElement::~GroundElement() = default;

void GroundElement::setBody(b2Body *newBody) {
    _body = newBody;
}

const b2BodyDef *GroundElement::getBodyDef() {
    return &_bodyDef;
}



