#ifndef CAREVOLUTION_GROUNDELEMENT_HPP
#define CAREVOLUTION_GROUNDELEMENT_HPP

#include "SFML/Graphics/Shape.hpp"
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>
/*
Author: Radoslaw Kostrzewski
Purpose: This is the header file of single ground block - a static rectangle
         that serves as a wall stoping dynamic objects from moving and interacting with them
*/
class GroundElement {

public:
  explicit GroundElement(float xPos);

  ~GroundElement();

  void setBody(b2Body *newBody);

  const b2BodyDef *getBodyDef();

protected:
  b2BodyDef _bodyDef;
  b2Body *_body{};
};

#endif // CAREVOLUTION_GROUNDELEMENT_H