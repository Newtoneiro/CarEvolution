#ifndef CAREVOLUTION_CAR_H
#define CAREVOLUTION_CAR_H

#include <memory>
#include "Figure.h"
#include "Circle.h"
#include "CarBody.h"

#include "../config/EnviromentConfig.h"

/*
Autor: Bartosz Latosek
Cel: Plik naglowkowy samochodu - obiektu reprezentującego
    samochod
*/

typedef std::shared_ptr<Figure> PFigure;
typedef std::shared_ptr<CarBody> PCarBody;
typedef std::shared_ptr<Circle> PCircle;

class Car : public Figure {
public:
    Car(const std::vector<unsigned int> &bodyRadiuses,
        const std::vector<float> &wheelRadiuses);

    ~Car();

    void createBody() override;

    void updateShape() override;

    PCarBody getCarBody();

    PCircle getLeftCircle();

    PCircle getRightCircle();

    sf::Shape &getShape() override;

    int getTime() const;

    void timerStep();

    void timerReset();

    bool isCarAlive();

    void setIsCarAlive(bool alive);

    void inertiaTimerReset() noexcept { _inertiaTimer = 0; };

    void increaseInertiaTimer() noexcept { _inertiaTimer++; };

    bool isDeadFromInertia() noexcept { return _inertiaTimer > EnviromentConfig::MAX_TIME_ALIVE_INERTIA; };

private:
    PCarBody _carBody;
    PCircle _leftCircle;
    PCircle _rightCircle;

    int _timer = 0;
    int _inertiaTimer = 0;
    bool isAlive = true;
};


#endif //CAREVOLUTION_CAR_H
