#ifndef CAREVOLUTION_CAR_H
#define CAREVOLUTION_CAR_H

#include <memory>

#include "Figure.h"
#include "Circle.h"
#include "CarBody.h"

#include "../config/EnvironmentConfig.h"

/*
Autor: Bartosz Latosek
Cel: Plik naglowkowy samochodu - obiektu reprezentującego
    samochod
*/

typedef std::shared_ptr<Figure> PFigure;
typedef std::shared_ptr<CarBody> PCarBody;
typedef std::shared_ptr<Circle> PCircle;
typedef std::pair<std::vector<unsigned int>, std::vector<float>> Genome;

class Car{
public:
    Car(const std::vector<unsigned int> &bodyRadiuses,
        const std::vector<float> &wheelRadiuses);

    ~Car() = default;

    void updateShape() noexcept;

    PCarBody getCarBody() const noexcept;

    PCircle getLeftCircle() const noexcept;

    PCircle getRightCircle() const noexcept;

    void timerStep() noexcept { ++timer; };

    void timerReset() noexcept { timer = 0; };

    void setIsCarAlive(bool alive) noexcept;

    int getTime() const noexcept { return timer; };

    bool isCarAlive() const noexcept { return isAlive; };

    Genome getGenome() const noexcept;

    std::vector<float> getWheelsGenome() const noexcept;

private:
    PCarBody carBody;
    PCircle leftCircle;
    PCircle rightCircle;

    int timer = 0;
    bool isAlive = true;
};


#endif //CAREVOLUTION_CAR_H
