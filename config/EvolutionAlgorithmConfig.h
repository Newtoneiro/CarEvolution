
#ifndef CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H
#define CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace algorytmu ewolucyjnego
*/
class EvolutionAlgorithmConfig {
public:
    static constexpr unsigned int INITIAL_POPULATION_SIZE = 5;
    static constexpr unsigned int POPULATION_SIZE = 10;
    static constexpr unsigned int NO_EPOCHS = 10;
    static constexpr float MUTATION_PROB = 0.6f;
    static constexpr float CROSSOVER_PROB = 0.9f;

    static constexpr unsigned int MAX_BODY_RADIUS_MUTATION = 10;
    static constexpr unsigned int MAX_WHEEL_RADIUS_MUTATION = 10;
};

#endif //CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H
