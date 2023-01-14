#ifndef CAREVOLUTION_GROUNDCONFIG_H
#define CAREVOLUTION_GROUNDCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace Podlogi
*/
class GroundConfig {
public:
    static constexpr float GROUND_ELEMENT_WIDTH = 100.0f;
    static constexpr float GROUND_ELEMENT_HEIGHT = 10.0f;

    static constexpr float GROUND_STARTING_X = -100.0f;
    static constexpr float GROUND_STARTING_Y = 400.0f;

    static constexpr int GROUND_MARGIN = 10;

    static constexpr float MAX_STOPE = 80.0f;
    static constexpr int GROUND_ELEMENTS_NUMBER = 200;
};

#endif //CAREVOLUTION_GROUNDCONFIG_H
