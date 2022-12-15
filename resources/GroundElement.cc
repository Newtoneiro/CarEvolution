#include "GroundElement.h"
#include "Figure.h"
/*
Author: Radoslaw Kostrzewski
Purpose: This is the implemenation of single ground block - a static rectangle
         that serves as a wall stoping dynamic objects from moving and interacting with them
*/
GroundElement::GroundElement(float xPos) {
  _bodyDef.position.Set(xPos, 400.0f);
  _bodyDef.angle = M_PI / 18;
};

GroundElement::~GroundElement() = default;

void GroundElement::setBody(b2Body *newBody) { _body = newBody; }

const b2BodyDef *GroundElement::getBodyDef() { return &_bodyDef; }
