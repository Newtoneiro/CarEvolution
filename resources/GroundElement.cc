#include "GroundElement.h"
#include "Figure.h"

/*
Autor: Radoslaw Kostrzewski
Cel: Plik implementujacy podloge - staly element
     bedacy przeszkoda dla dynamicznych obiektow i
     oddzialujacy z nimi
*/
GroundElement::GroundElement(float xPos) {
  _bodyDef.position.Set(xPos, 800.0f);
  _bodyDef.angle = M_PI / 18;
};

GroundElement::~GroundElement() = default;

void GroundElement::setBody(b2Body *newBody) { _body = newBody; }

const b2BodyDef *GroundElement::getBodyDef() { return &_bodyDef; }
