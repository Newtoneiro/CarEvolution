#ifndef CAREVOLUTION_CARBODY_H
#define CAREVOLUTION_CARBODY_H

#include "../config/FigureCategories.h"
#include "../config/EnvironmentConfig.h"

#include "Figure.h"

/*
Author: Radosław Kostrzewski
Purpose: Header file of CarBody - class representing the polygon shape car body
*/
class CarBody : public Figure {
public:
    explicit CarBody(const std::vector<unsigned int> &bodyRadiuses);

    void createBody() override;

    void updateShape() override;

    sf::Shape &getShape() override;

    void setIsAlive(const bool val) noexcept { isAlive_ = val; };

    bool isBodyAlive() const noexcept { return isAlive_; };

    b2Vec2 getLeftWheel();

    b2Vec2 getRightWheel();

    std::vector<unsigned int> getGenome() const noexcept { return genome_; };


private:
    bool isAlive_ = true;
    sf::ConvexShape shape_;
    b2Vec2 points_[8];
    std::vector<unsigned int> genome_;
};

#endif //CAREVOLUTION_CARBODY_H
