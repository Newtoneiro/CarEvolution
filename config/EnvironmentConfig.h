
#ifndef CAREVOLUTION_ENVIRONMENTCONFIG_H
#define CAREVOLUTION_ENVIRONMENTCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace srodowiska i fizyki
*/
class EnvironmentConfig {
public:
    static const unsigned int FPS = 120;
    static const unsigned int VELOCITY_ITERATIONS = 1;
    static const unsigned int POSITION_ITERATIONS = 1;
    static const unsigned int GRAVITY = 2;

    static const unsigned int MAX_TIME_ALIVE = 1000;

    static const unsigned int WINDOW_WIDTH = 800;
    static const unsigned int WINDOW_HEIGHT = 600;

    static constexpr float MINIMAL_SPEED = 1.0f;
    static constexpr float FIGURE_DENSITY = 1.0f;
    static constexpr float FIGURE_FRICTION = 0.3f;
    static constexpr float FIGURE_RESTITUTION = 0.5f;
};

#endif //CAREVOLUTION_ENVIRONMENTCONFIG_H
