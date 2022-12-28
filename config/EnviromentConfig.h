
#ifndef CAREVOLUTION_ENVIROMENTCONFIG_H
#define CAREVOLUTION_ENVIROMENTCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace srodowiska i fizyki
*/
class EnviromentConfig {
public:
    static constexpr int FPS = 120;
    static constexpr int VELOCITY_ITERATIONS = 6;
    static constexpr int POSITION_ITERATIONS = 2;
    static constexpr int GRAVITY = 1;

    static constexpr unsigned int WINDOW_WIDTH = 800;
    static constexpr unsigned int WINDOW_HEIGHT = 600;
};

#endif //CAREVOLUTION_ENVIROMENTCONFIG_H
