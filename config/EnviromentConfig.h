
#ifndef CAREVOLUTION_ENVIROMENTCONFIG_H
#define CAREVOLUTION_ENVIROMENTCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace srodowiska i fizyki
*/
class EnviromentConfig {
public:
    static constexpr unsigned int FPS = 1;
    static constexpr unsigned int VELOCITY_ITERATIONS = 6;
    static constexpr unsigned int POSITION_ITERATIONS = 2;
    static constexpr unsigned int GRAVITY = 1;
    static constexpr unsigned int FONT_SIZE = 20;

    static constexpr unsigned int MAX_TIME_ALIVE = 1000;

    static constexpr unsigned int WINDOW_WIDTH = 800;
    static constexpr unsigned int WINDOW_HEIGHT = 600;

    static constexpr float MINIMAL_SPEED = 2;
};

#endif //CAREVOLUTION_ENVIROMENTCONFIG_H
