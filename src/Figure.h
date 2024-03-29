#ifndef CAREVOLUTION_FIGURE_H
#define CAREVOLUTION_FIGURE_H

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

/*
Author: Bartosz Latosek
Purpose: This is header file for base class for all figures - dynamic objects
         that can interact with eachothers using rules of physics
*/


class Figure {
public:
    Figure();

    virtual ~Figure();

    virtual void createBody() = 0;

    virtual void updateShape() = 0;

    virtual sf::Shape &getShape() = 0;

    void setBody(b2Body *newBody);

    b2Vec2 getPosition();

    b2Body *getBody();

    b2BodyDef getBodyDef();

protected:
    b2BodyDef bodyDef_;
    b2Body *body_;
};

#endif // CAREVOLUTION_FIGURE_H
