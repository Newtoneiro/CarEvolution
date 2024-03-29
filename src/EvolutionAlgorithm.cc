#include "EvolutionAlgorithm.h"

/*
Author: Bartosz Latosek
Purpose: This is a implementation file for representation of Evolution Algorithm,
         allowing us to control the parameters and steps
*/

void EvolutionAlgorithm::init() noexcept {
    World newWorld;
    world_ = std::make_shared<World>(newWorld);
    world_->createCars(EvolutionAlgorithmConfig::INITIAL_POPULATION_SIZE);
    world_->generateFloor();
}

b2Vec2 EvolutionAlgorithm::updateWorld() noexcept {
    worldStep();
    PCar eliteCar = world_->updateCars();
    if (world_->isEndOfEpoch()) {
        ++curEpoch_;
        if (curEpoch_ == EvolutionAlgorithmConfig::NO_EPOCHS) {
            done_ = true;
            printf("Best found genome:\n");
            printf("Body radiuses: ");
            for (auto gene: eliteCar->getGenome().first) {
                printf("%d, ", gene);
            }
            printf("\nWheel radiuses: ");
            for (auto gene: eliteCar->getGenome().second) {
                printf("%f, ", gene);
            }
            printf("\nBest distance: %f\n", eliteCar->getCarBody()->getPosition().x);
        }
        generateNewEpoch(eliteCar);
    }
    return world_->getCameraPosition();
}

std::vector<PFigure> EvolutionAlgorithm::getWorldElements() noexcept {
    return world_->getElements();
}

void EvolutionAlgorithm::worldStep() noexcept {
    world_->step();
    world_->updateElements();
}

void EvolutionAlgorithm::generateNewEpoch(const PCar eliteCar) noexcept {
    std::vector<Genome> newPopulationGenome;

    selection(newPopulationGenome, world_->getCurrentPopulation());
    crossover(newPopulationGenome);
    mutation(newPopulationGenome);

    newPopulationGenome.push_back(eliteCar->getGenome());

    world_->respawnCars(newPopulationGenome);
    world_->setEndOfEpoch(false);
}

void EvolutionAlgorithm::selection(std::vector<Genome> &newPopulationGenome,
                                   const std::vector<PCar> &oldPopulation) noexcept {
    while (newPopulationGenome.size() != EvolutionAlgorithmConfig::POPULATION_SIZE - 1) {
        const unsigned int firstCarIndex = rand() % (oldPopulation.size() - 1);
        const unsigned int secondCarIndex = rand() % (oldPopulation.size() - 1);

        const b2Vec2 firstCarPos = oldPopulation[firstCarIndex]->getCarBody()->getBody()->GetPosition();
        const b2Vec2 secondCarPos = oldPopulation[secondCarIndex]->getCarBody()->getBody()->GetPosition();

        unsigned int winnerIndex;
        if (firstCarPos.x > secondCarPos.x) {
            winnerIndex = firstCarIndex;
        } else {
            winnerIndex = secondCarIndex;
        }

        newPopulationGenome.push_back(oldPopulation[winnerIndex]->getGenome());
    }
}

void EvolutionAlgorithm::crossover(std::vector<Genome> &newPopulationGenome) const noexcept {
    for (auto &subject: newPopulationGenome) {
        float crossoverProb = (float) rand() / (float) RAND_MAX;
        if (crossoverProb < EvolutionAlgorithmConfig::CROSSOVER_PROB) {
            const unsigned int parentIndex = rand() % (newPopulationGenome.size() - 1);
            Genome parentGenome = newPopulationGenome[parentIndex];
            // Crossover bodyRadiuses
            std::vector<unsigned int> newBodyRadiuses;
            for (int i = 0; i < 8; ++i) {
                newBodyRadiuses.push_back(int((subject.first[i] + parentGenome.first[i]) / 2));
            }
            // Crossover wheelRadiuses
            std::vector<float> newWheelRadiuses;
            for (int i = 0; i < 2; ++i) {
                newWheelRadiuses.push_back((subject.second[i] + parentGenome.second[i]) / 2);
            }
            Genome ancestorGenome = std::make_pair(newBodyRadiuses, newWheelRadiuses);
            subject = ancestorGenome;
        }
    }
}

void EvolutionAlgorithm::mutation(std::vector<Genome> &newPopulationGenome) const noexcept {
    for (auto &subject: newPopulationGenome) {
        // Mutate bodyRadiuses
        std::vector<unsigned int> newBodyRadiuses;
        for (int i = 0; i < 8; ++i) {
            float mutationProb = (float) rand() / (float) RAND_MAX;
            int oldBodyRadius = subject.first[i];
            if (mutationProb < EvolutionAlgorithmConfig::MUTATION_PROB) {
                oldBodyRadius += (rand() %
                                  (2 * EvolutionAlgorithmConfig::MAX_BODY_RADIUS_MUTATION + 1) -
                                  EvolutionAlgorithmConfig::MAX_BODY_RADIUS_MUTATION);
                oldBodyRadius = std::min(oldBodyRadius, CarConfig::MAX_BODY_RADIUS);
                oldBodyRadius = std::max(oldBodyRadius, CarConfig::MIN_BODY_RADIUS);
            }
            newBodyRadiuses.push_back(oldBodyRadius);
        }
        // Mutate wheelRadiuses
        std::vector<float> newWheelRadiuses;
        for (int i = 0; i < 2; ++i) {
            float mutationProb = (float) rand() / (float) RAND_MAX;
            int oldWheelRadius = subject.second[i];
            if (mutationProb < EvolutionAlgorithmConfig::MUTATION_PROB) {
                oldWheelRadius += (rand() %
                                   (2 * EvolutionAlgorithmConfig::MAX_WHEEL_RADIUS_MUTATION + 1) -
                                   EvolutionAlgorithmConfig::MAX_BODY_RADIUS_MUTATION);
                oldWheelRadius = std::min(oldWheelRadius, CarConfig::MAX_WHEEL_RADIUS);
                oldWheelRadius = std::max(oldWheelRadius, CarConfig::MIN_WHEEL_RADIUS);
            }
            newWheelRadiuses.push_back(oldWheelRadius);
        }
        Genome ancestorGenome = std::make_pair(newBodyRadiuses, newWheelRadiuses);
        subject = ancestorGenome;
    }
}
