
#ifndef CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H
#define CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H

/*
Author: Bartosz Latosek
Purpose: Configurational file with constants related to Evolutional Algorithm and it's parameters
*/
class EvolutionAlgorithmConfig {
public:
    static const int INITIAL_POPULATION_SIZE = 5;
    static const int POPULATION_SIZE = 5;
    static const int NO_EPOCHS = 10;
    static constexpr float MUTATION_PROB = 0.9f;
    static constexpr float CROSSOVER_PROB = 0.5f;

    static const int MAX_BODY_RADIUS_MUTATION = 5;
    static const int MAX_WHEEL_RADIUS_MUTATION = 5;
};

#endif //CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H
