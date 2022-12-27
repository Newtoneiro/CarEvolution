#ifndef CAREVOLUTION_CAR_H
#define CAREVOLUTION_CAR_H

#include "Figure.h"
#include "Circle.h"
#include "CarBody.h"

/*
Autor: Bartosz Latosek
Cel: Plik naglowkowy samochodu - obiektu reprezentującego
    samochod
*/
class Car : public Figure {
public:
    Car(const std::vector<unsigned int> &bodyRadiuses,
        const std::vector<float> &wheelRadiuses);

    void createBody() override;

    void updateShape() override;

    CarBody *getCarBody();

    Circle *getLeftCircle();

    Circle *getRightCircle();

    sf::Shape &getShape() override;

    int getTime() const;

    void timerStep();

    void timerReset();

private:
    CarBody *_carBody;
    Circle *_leftCircle;
    Circle *_rightCircle;

    int _timer = 0;
};


#endif //CAREVOLUTION_CAR_H
