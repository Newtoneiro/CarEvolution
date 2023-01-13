#include <gtest/gtest.h>
#include <vector>

#include "../src/Car.h"
/*
Author: Bartosz Latosek
Purpose: This is the file with tests for Car class
*/

TEST(CarTest, ContructorTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    
    Car* car = new Car(bodyRadiuses, wheelRadiuses);
    EXPECT_TRUE(car->getCarBody() != nullptr);
    EXPECT_TRUE(car->getLeftCircle() != nullptr);
    EXPECT_TRUE(car->getRightCircle() != nullptr);
    delete car;
}