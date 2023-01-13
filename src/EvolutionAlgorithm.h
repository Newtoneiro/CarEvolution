#ifndef CAREVOLUTION_EVOLUTIONALGORITHM_H
#define CAREVOLUTION_EVOLUTIONALGORITHM_H

#include "World.h"
#include "../config/EvolutionAlgorithmConfig.h"
#include "../config/CarConfig.h"

/*
Author: Bartosz Latosek
Purpose: This is a header file for representation of Evolution Algorithm,
         allowing us to control the parameters and steps
*/
class EvolutionAlgorithm {
public:
    void init() noexcept;

    b2Vec2 updateWorld() noexcept;

    std::vector<PFigure> getWorldElements() noexcept;

    bool isDone() const noexcept { return _done; };
    
    unsigned int epoch() const noexcept { return _curEpoch; };

private:
    void worldStep() noexcept;

    void generateNewEpoch(const PCar eliteCar) noexcept;

    void selection(std::vector<Genome> &newPopulationGenome, const std::vector<PCar> &oldPopulation) noexcept;

    void crossover(std::vector<Genome> &newPopulationGenome) const noexcept;

    void mutation(std::vector<Genome> &newPopulationGenome) const noexcept;

    std::shared_ptr<World> _world;
    unsigned int _curEpoch = 0;
    bool _done = false;
};

#endif // CAREVOLUTION_EVOLUTIONALGORITHM_H