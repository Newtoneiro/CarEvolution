#include "Figure.h"

/*
Author: Bartosz Latosek
Purpose: This is implementation for base class for all figures - dynamic objects
         that can interact with eachothers using rules of physic
*/
Figure::Figure() = default;

Figure::~Figure() = default;

b2Body *Figure::getBody() { return body; }

b2Vec2 Figure::getPosition() { return body->GetPosition(); }

void Figure::setBody(b2Body *newBody) { body = newBody; }

b2BodyDef Figure::getBodyDef() { return bodyDef; }
