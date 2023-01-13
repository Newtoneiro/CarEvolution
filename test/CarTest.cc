#include <gtest/gtest.h>
#include <vector>

#include "../src/Car.h"
#include "../src/World.h"
/*
Author: Bartosz Latosek
Purpose: This is the file with tests for Car class
*/

TEST(CarTest, ContructorTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    
    PCar car = std::make_unique<Car>(bodyRadiuses, wheelRadiuses);
    EXPECT_TRUE(car->getCarBody() != nullptr);
    EXPECT_TRUE(car->getLeftCircle() != nullptr);
    EXPECT_TRUE(car->getRightCircle() != nullptr);
}

TEST(CarTest, CreateBodyTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    
    World world;
    PCar car = std::make_unique<Car>(bodyRadiuses, wheelRadiuses);
    EXPECT_TRUE(car->getCarBody()->getBody() == nullptr);
    EXPECT_TRUE(car->getLeftCircle()->getBody() == nullptr);
    EXPECT_TRUE(car->getRightCircle()->getBody() == nullptr);
    
    car->createBody();

    // EXPECT_TRUE(car->getCarBody()->getBody() != nullptr);
    // EXPECT_TRUE(car->getLeftCircle()->getBody() != nullptr);
    // EXPECT_TRUE(car->getRightCircle()->getBody() != nullptr);
}