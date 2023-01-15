#ifndef CAREVOLUTION_CARCONFIG_H
#define CAREVOLUTION_CARCONFIG_H

/*
Author: Bartosz Latosek
Purpose: Configurational file with constants related to Cars
*/
class CarConfig {
public:
    static constexpr int MIN_BODY_RADIUS = 10;
    static constexpr int MAX_BODY_RADIUS = 100;
    static constexpr int MIN_WHEEL_RADIUS = 10;
    static constexpr int MAX_WHEEL_RADIUS = 40;
    static constexpr float CAR_VELOCITY = 5.0f;
};

#endif //CAREVOLUTION_CARCONFIG_H
