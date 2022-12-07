#ifndef CAREVOLUTION_GROUNDELEMENT_HPP
#define CAREVOLUTION_GROUNDELEMENT_HPP

#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include "SFML/Graphics/Shape.hpp"

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

#endif //CAREVOLUTION_GROUNDELEMENT_HPP
