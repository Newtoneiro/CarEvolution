#ifndef CAREVOLUTION_FIGURE_H
#define CAREVOLUTION_FIGURE_H

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
/*
Autor: Bartosz Latosek
Cel: Plik naglowkowy domyslna figure
     sluzaca do prezentacji fizyki
*/
class Figure {
public:
  Figure();

  ~Figure();

  b2Vec2 getPosition();

  b2Body *getBody();

  void setBody(b2Body *newBody);

  b2BodyDef getBodyDef();

  virtual void createBody() = 0;

  virtual void updateShape() = 0;

  virtual sf::Shape &getShape() = 0;

protected:
  b2BodyDef _bodyDef;
  b2Body *_body{};
};

#endif // CAREVOLUTION_FIGURE_H