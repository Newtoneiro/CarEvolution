#include <gtest/gtest.h>

#include "../src/World.h"

/*
Autor: Radosław Kostrzewski
Cel: Implementacja testów do klasy World
*/

typedef std::unique_ptr<World> PWorld;

TEST(WorldTest, Constructor) {
    PWorld world = std::make_unique<World>();
    EXPECT_TRUE(world != nullptr);
}

TEST(WorldTest, GenerateFloor) {
    PWorld world = std::make_unique<World>();
    world->generateFloor();
    auto firstElemPosition = world->getElements()[0]->getPosition();
    EXPECT_TRUE(world->getElements().size() == GroundConfig::GROUND_ELEMENTS_NUMBER);
    EXPECT_TRUE(firstElemPosition.x == GroundConfig::GROUND_STARTING_X + GroundConfig::GROUND_ELEMENT_WIDTH / 2);
    EXPECT_TRUE(firstElemPosition.y == GroundConfig::GROUND_STARTING_Y);
    EXPECT_TRUE(world->getElements()[0]->getShape().getRotation() == 0);
    auto elementWithinMargin = world->getElements()[GroundConfig::GROUND_MARGIN - 1]->getPosition();
    EXPECT_TRUE(elementWithinMargin.x == GroundConfig::GROUND_STARTING_X +
                                         GroundConfig::GROUND_ELEMENT_WIDTH * (GroundConfig::GROUND_MARGIN - 1) +
                                         GroundConfig::GROUND_ELEMENT_WIDTH / 2);
    EXPECT_TRUE(elementWithinMargin.y == GroundConfig::GROUND_STARTING_Y);
    EXPECT_TRUE(world->getElements()[GroundConfig::GROUND_MARGIN - 1]->getShape().getRotation() == 0);
    auto elementOutsideMargin = world->getElements()[GroundConfig::GROUND_MARGIN]->getPosition();
    EXPECT_TRUE(elementOutsideMargin.x != GroundConfig::GROUND_STARTING_X +
                                          GroundConfig::GROUND_ELEMENT_WIDTH * (GroundConfig::GROUND_MARGIN) +
                                          GroundConfig::GROUND_ELEMENT_WIDTH / 2);
    EXPECT_TRUE(elementOutsideMargin.y != GroundConfig::GROUND_STARTING_Y);
    EXPECT_TRUE(world->getElements()[GroundConfig::GROUND_MARGIN]->getShape().getRotation() != 0);
}

TEST(WorldTest, GenerateCar) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    EXPECT_TRUE(testCar != nullptr);
    EXPECT_TRUE(testCar->getCarBody() != nullptr);
    EXPECT_TRUE(testCar->getLeftCircle() != nullptr);
    EXPECT_TRUE(testCar->getRightCircle() != nullptr);
    world->createCar(testCar);
    EXPECT_TRUE(testCar->getCarBody()->getBody()->GetPosition().x == 0);
    EXPECT_TRUE(testCar->getCarBody()->getBody()->GetPosition().y == 0);
    EXPECT_TRUE(testCar->getCarBody()->getBody()->GetAngle() == 0);
    EXPECT_TRUE(world->getElements().size() == 3);
}

TEST(WorldTest, GenerateCars) {
    const int carCount = 10;
    PWorld world = std::make_unique<World>();
    world->createCars(carCount);
    auto elements = world->getElements();
    EXPECT_TRUE(elements.size() == 3 * carCount);
}


TEST(WorldTest, UpdateCar) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    world->createCar(testCar);
    world->generateFloor();
    auto oldBodyPosition = testCar->getCarBody()->getBody()->GetPosition();
    auto oldAngle = testCar->getCarBody()->getBody()->GetAngle();
    b2Vec2 oldCameraPosition = b2Vec2_zero;
    for (int i = 0; i < 100; ++i) {
        if (i == 10) {
            oldCameraPosition = world->getCameraPosition();
        }
        world->step();
        world->updateCars();
    }
    auto newBodyPosition = testCar->getCarBody()->getBody()->GetPosition();
    auto newRightWheelPosition = testCar->getRightCircle()->getBody()->GetPosition();
    auto newAngle = testCar->getCarBody()->getBody()->GetAngle();
    auto newCameraPosition = world->getCameraPosition();
    EXPECT_TRUE(oldBodyPosition != newBodyPosition);
    EXPECT_TRUE(oldAngle != newAngle);
    EXPECT_TRUE(oldCameraPosition != newCameraPosition);
    EXPECT_TRUE(newCameraPosition == newRightWheelPosition);
}

TEST(WorldTest, RespawnCars) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    std::vector<Genome> testGenome = {{bodyRadiuses, wheelRadiuses}};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    world->createCar(testCar);
    world->generateFloor();
    for (int i = 0; i < 100; ++i) {
        world->step();
    }
    world->updateCars();
    auto beforeRespawnPosition = testCar->getCarBody()->getBody()->GetPosition();
    world->respawnCars(testGenome);
    auto afterRespawnPosition = testCar->getCarBody()->getBody()->GetPosition();
    EXPECT_TRUE(beforeRespawnPosition != afterRespawnPosition);
}
