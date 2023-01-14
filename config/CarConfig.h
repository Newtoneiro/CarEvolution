#ifndef CAREVOLUTION_CARCONFIG_H
#define CAREVOLUTION_CARCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace Samochodow
*/
class CarConfig {
public:
    static constexpr int MIN_BODY_RADIUS = 10;
    static constexpr int MAX_BODY_RADIUS = 100;
    static constexpr int MIN_WHEEL_RADIUS = 10;
    static constexpr int MAX_WHEEL_RADIUS = 40;
};

#endif //CAREVOLUTION_CARCONFIG_H
