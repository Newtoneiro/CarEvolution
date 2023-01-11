#include "EvolutionAlgorithm.h"

/*
Author: Bartosz Latosek
Purpose: This is a implementation file for representation of Evolution Algorithm,
         allowing us to control the parameters and steps
*/

void EvolutionAlgorithm::init() noexcept {
    World world;
    _world = std::make_shared<World>(world);
    _world->createCars(EvolutionAlgorithmConfig::INITIAL_POPULATION_SIZE);
    _world->generateFloor();
}

b2Vec2 EvolutionAlgorithm::step() noexcept {
    worldStep();
    return _world->destroyCars();
}

void EvolutionAlgorithm::worldStep() noexcept {
    _world->step();
    _world->updateElements();
}

std::vector<PFigure> EvolutionAlgorithm::getWorldElements() noexcept {
    return _world->getElements();
}
