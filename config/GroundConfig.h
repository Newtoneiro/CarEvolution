#ifndef CAREVOLUTION_GROUNDCONFIG_H
#define CAREVOLUTION_GROUNDCONFIG_H

/*
Author: Radosław Kostrzewski
Purpose: Configurational file with constants related to world's ground
*/
class GroundConfig {
public:
    static constexpr float GROUND_ELEMENT_WIDTH = 100.0f;
    static constexpr float GROUND_ELEMENT_HEIGHT = 10.0f;

    static constexpr float GROUND_STARTING_X = -500.0f;
    static constexpr float GROUND_STARTING_Y = 400.0f;

    static constexpr int GROUND_MARGIN = 20;

    static constexpr float MAX_STOPE = 60.0f;
    static constexpr int GROUND_ELEMENTS_NUMBER = 220;
};

#endif //CAREVOLUTION_GROUNDCONFIG_H
