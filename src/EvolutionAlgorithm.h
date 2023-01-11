#ifndef CAREVOLUTION_EVOLUTIONALGORITHM_H
#define CAREVOLUTION_EVOLUTIONALGORITHM_H

#include "World.h"
#include "../config/EvolutionAlgorithmConfig.h"

/*
Author: Bartosz Latosek
Purpose: This is a header file for representation of Evolution Algorithm,
         allowing us to control the parameters and steps
*/
class EvolutionAlgorithm {
public:
    void init() noexcept;

    b2Vec2 step() noexcept;

    std::vector<PFigure> getWorldElements() noexcept;

private:
    void worldStep() noexcept;

    std::shared_ptr<World> _world;
};

#endif // CAREVOLUTION_EVOLUTIONALGORITHM_H