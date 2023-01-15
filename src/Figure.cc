#include "Figure.h"

/*
Author: Bartosz Latosek
Purpose: This is implementation for base class for all figures - dynamic objects
         that can interact with eachothers using rules of physic
*/
Figure::Figure() = default;

Figure::~Figure() = default;

b2Body *Figure::getBody() { return body_; }

b2Vec2 Figure::getPosition() { return body_->GetPosition(); }

void Figure::setBody(b2Body *newBody) { body_ = newBody; }

b2BodyDef Figure::getBodyDef() { return bodyDef_; }
