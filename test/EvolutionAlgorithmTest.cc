#include <gtest/gtest.h>

#include "../src/EvolutionAlgorithm.h"

/*
Autor: Bartosz latosek
Cel: Implementacja testów do klasy EvolutionAlgorithm
*/


TEST(EvolutionAlgorithmTest, ConstructorTest) {
    EvolutionAlgorithm algorithm;
    algorithm.init();
    ASSERT_EQ(algorithm.getWorldElements().size(),
              (EvolutionAlgorithmConfig::INITIAL_POPULATION_SIZE * 3) + GroundConfig::GROUND_ELEMENTS_NUMBER);
    ASSERT_EQ(algorithm.epoch(), 0);
    EXPECT_TRUE(!algorithm.isDone());
}

TEST(EvolutionAlgorithmTest, UpdateWorldTest) {
    EvolutionAlgorithm algorithm;
    algorithm.init();
    b2Vec2 view_pos = algorithm.updateWorld();

    ASSERT_NEAR(view_pos.x, 150, 50);
    ASSERT_NEAR(view_pos.y, 150, 50);
}
