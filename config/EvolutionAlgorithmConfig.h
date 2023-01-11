
#ifndef CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H
#define CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H

/*
Autor: Bartosz Latosek
Cel: Plik zawierajacy zmienne konfiguracyjne dotyczace algorytmu ewolucyjnego
*/
class EvolutionAlgorithmConfig {
public:
    static constexpr int INITIAL_POPULATION_SIZE = 5;
    static constexpr int NO_EPOCHS = 10;
    static constexpr float MUTATION_PROB = 0.6;
};

#endif //CAREVOLUTION_EVOLUTIONALGORITHMCONFIG_H
