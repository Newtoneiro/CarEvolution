#ifndef CAREVOLUTION_GROUNDELEMENT_HPP
#define CAREVOLUTION_GROUNDELEMENT_HPP

#include "../config/GroundConfig.h"
#include "../config/FigureCategories.h"
#include "../config/EnvironmentConfig.h"


#include "SFML/Graphics.hpp"
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>
#include "Figure.h"


/*
Author: Radoslaw Kostrzewski
Purpose: This is the header file of single ground block - a static rectangle
         that serves as a wall stoping dynamic objects from moving and interacting with them
*/
class GroundElement : public Figure {
public:
    GroundElement(float posX, float posY, float rotation);

    void createBody() override;

    void updateShape() override;

    sf::Shape &getShape() override;

private:
    sf::RectangleShape shape;
};

#endif // CAREVOLUTION_GROUNDELEMENT_HPP