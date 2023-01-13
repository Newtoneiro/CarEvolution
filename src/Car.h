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

class Car : public Figure {
public:
    Car(const std::vector<unsigned int> &bodyRadiuses,
        const std::vector<float> &wheelRadiuses);

    ~Car() = default;

    void createBody() noexcept override;

    void updateShape() noexcept override;

    PCarBody getCarBody() const noexcept;

    PCircle getLeftCircle() const noexcept;

    PCircle getRightCircle() const noexcept;

    sf::Shape &getShape() noexcept override;

    void timerStep() noexcept { ++_timer; };

    void timerReset() noexcept { _timer = 0; };

    void setIsCarAlive(bool alive) noexcept;

    int getTime() const noexcept { return _timer; };

    bool isCarAlive() const noexcept { return isAlive; };

    Genome getGenome() const noexcept;

    std::vector<float> getWheelsGenome() const noexcept;

private:
    PCarBody _carBody;
    PCircle _leftCircle;
    PCircle _rightCircle;

    int _timer = 0;
    bool isAlive = true;
};


#endif //CAREVOLUTION_CAR_H
