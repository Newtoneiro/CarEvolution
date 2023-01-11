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

b2Vec2 EvolutionAlgorithm::updateWorld() noexcept {
    worldStep();
    PCar eliteCar = _world->updateCars();
    if (_world->isEndOfEpoch()) generateNewEpoch(eliteCar);
    return eliteCar->getCarBody()->getBody()->GetPosition();
}

std::vector<PFigure> EvolutionAlgorithm::getWorldElements() noexcept {
    return _world->getElements();
}

void EvolutionAlgorithm::worldStep() noexcept {
    _world->step();
    _world->updateElements();
}

void EvolutionAlgorithm::generateNewEpoch(const PCar eliteCar) noexcept {
    std::vector<Genome> newPopulationGenome;
    newPopulationGenome.push_back(eliteCar->getGenome());

    selection(newPopulationGenome, _world->getCurrentPopulation());

    _world->respawnCars(newPopulationGenome);
    _world->setEndOfEpoch(false);
}

void EvolutionAlgorithm::selection(std::vector<Genome> &newPopulationGenome, const std::vector<PCar> &oldPopulation) noexcept{
    while (newPopulationGenome.size() != EvolutionAlgorithmConfig::POPULATION_SIZE) {
        const unsigned int firstCarIndex = rand() % (oldPopulation.size() - 1);
        const unsigned int secondCarIndex = rand() % (oldPopulation.size() - 1);
        
        const b2Vec2 firstCarPos = oldPopulation[firstCarIndex]->getCarBody()->getBody()->GetPosition();
        const b2Vec2 secondCarPos = oldPopulation[secondCarIndex]->getCarBody()->getBody()->GetPosition();

        unsigned int winnerIndex;
        if (firstCarPos.x > secondCarPos.x) {
            winnerIndex = firstCarIndex;
        }
        else {
            winnerIndex = secondCarIndex;
        }

        newPopulationGenome.push_back(oldPopulation[winnerIndex]->getGenome());
    }
}
