
#ifndef CAREVOLUTION_ENVIRONMENTCONFIG_H
#define CAREVOLUTION_ENVIRONMENTCONFIG_H

/*
Author: Bartosz Latosek
Purpose: Configurational file with constants related to enviroment and physics
*/
class EnvironmentConfig {
public:
    static const int FPS = 90;
    static const int VELOCITY_ITERATIONS = 1;
    static const int POSITION_ITERATIONS = 1;
    static const int GRAVITY = 2;
    static const int SEED = 0;

    static const int MAX_TIME_ALIVE = 1000;

    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;

    static constexpr float MINIMAL_SPEED = 1.0f;
    static constexpr float FIGURE_DENSITY = 1.0f;
    static constexpr float FIGURE_FRICTION = 0.3f;
    static constexpr float FIGURE_RESTITUTION = 0.5f;
};

#endif //CAREVOLUTION_ENVIRONMENTCONFIG_H
