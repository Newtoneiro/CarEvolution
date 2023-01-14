#include <gtest/gtest.h>

#include "../src/World.h"

/*
Autor: Radosław Kostrzewski
Cel: Implementacja testów do klasy World
*/

typedef std::unique_ptr<World> PWorld;

TEST(WorldTest, ConstructorTest) {
    PWorld world = std::make_unique<World>();
    EXPECT_TRUE(world != nullptr);
}

TEST(WorldTest, GenerateFloorNumberOfElementsTest) {
    PWorld world = std::make_unique<World>();
    world->generateFloor();
    ASSERT_EQ(world->getElements().size(), GroundConfig::GROUND_ELEMENTS_NUMBER);
}

TEST(WorldTest, GenerateFloorFirstElementTest) {
    PWorld world = std::make_unique<World>();
    world->generateFloor();
    auto firstElemPosition = world->getElements()[0]->getPosition();
    ASSERT_EQ(world->getElements().size(), GroundConfig::GROUND_ELEMENTS_NUMBER);
    ASSERT_EQ(firstElemPosition.x, GroundConfig::GROUND_STARTING_X + GroundConfig::GROUND_ELEMENT_WIDTH / 2);
    ASSERT_EQ(firstElemPosition.y, GroundConfig::GROUND_STARTING_Y);
    ASSERT_EQ(world->getElements()[0]->getShape().getRotation(), 0);
}

TEST(WorldTest, GenerateFloorElementWithinMarginTest) {
    PWorld world = std::make_unique<World>();
    world->generateFloor();
    auto elementWithinMargin = world->getElements()[GroundConfig::GROUND_MARGIN - 1]->getPosition();
    ASSERT_EQ(elementWithinMargin.x, GroundConfig::GROUND_STARTING_X +
                                     GroundConfig::GROUND_ELEMENT_WIDTH * (GroundConfig::GROUND_MARGIN - 1) +
                                     GroundConfig::GROUND_ELEMENT_WIDTH / 2);
    ASSERT_EQ(elementWithinMargin.y, GroundConfig::GROUND_STARTING_Y);
    ASSERT_EQ(world->getElements()[GroundConfig::GROUND_MARGIN - 1]->getShape().getRotation(), 0);
}

TEST(WorldTest, GenerateFloorElementOutsideMarginTest) {
    PWorld world = std::make_unique<World>();
    world->generateFloor();
    auto elementOutsideMargin = world->getElements()[GroundConfig::GROUND_MARGIN]->getPosition();
    EXPECT_TRUE(elementOutsideMargin.x != GroundConfig::GROUND_STARTING_X +
                                          GroundConfig::GROUND_ELEMENT_WIDTH * (GroundConfig::GROUND_MARGIN) +
                                          GroundConfig::GROUND_ELEMENT_WIDTH / 2);
    EXPECT_TRUE(elementOutsideMargin.y != GroundConfig::GROUND_STARTING_Y);
    EXPECT_TRUE(world->getElements()[GroundConfig::GROUND_MARGIN]->getShape().getRotation() != 0);
}

TEST(WorldTest, GenerateCarTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    world->createCar(testCar);
    ASSERT_EQ(world->getElements().size(), 3);
}

TEST(WorldTest, GenerateCarsTest) {
    const int carCount = 10;
    PWorld world = std::make_unique<World>();
    world->createCars(carCount);
    auto elements = world->getElements();
    ASSERT_EQ(elements.size(), 3 * carCount);
}

TEST(WorldTest, UpdateCarTest) {
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
            world->updateCars();
            oldCameraPosition = world->getCameraPosition();
        }
        world->step();
    }
    world->updateCars();
    auto bestCar = world->updateCars();
    auto newBodyPosition = testCar->getCarBody()->getBody()->GetPosition();
    auto newRightWheelPosition = testCar->getRightCircle()->getBody()->GetPosition();
    auto newAngle = testCar->getCarBody()->getBody()->GetAngle();
    auto newCameraPosition = world->getCameraPosition();
    EXPECT_TRUE(oldBodyPosition != newBodyPosition);
    EXPECT_TRUE(oldAngle != newAngle);
    EXPECT_TRUE(oldCameraPosition != newCameraPosition);
    EXPECT_TRUE(newCameraPosition == newRightWheelPosition);
    EXPECT_TRUE(bestCar == testCar);
}

TEST(WorldTest, RespawnCarsTest) {
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

TEST(WorldTest, UpdateShapeTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    world->createCar(testCar);
    world->generateFloor();
    auto oldCarBodyShapePos = testCar->getCarBody()->getShape().getPosition();
    auto oldRightWheelShapePos = testCar->getRightCircle()->getShape().getPosition();
    auto oldLeftWheelShapePos = testCar->getLeftCircle()->getShape().getPosition();
    for (int i = 0; i < 100; ++i) {
        world->step();
    }
    world->updateElements();
    auto newCarBodyShapePos = testCar->getCarBody()->getShape().getPosition();
    auto newRightWheelShapePos = testCar->getRightCircle()->getShape().getPosition();
    auto newLeftWheelShapePos = testCar->getLeftCircle()->getShape().getPosition();
    EXPECT_TRUE(oldCarBodyShapePos != newCarBodyShapePos);
    EXPECT_TRUE(oldRightWheelShapePos != newRightWheelShapePos);
    EXPECT_TRUE(oldLeftWheelShapePos != newLeftWheelShapePos);
}

TEST(WorldTest, CarTimeoutTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    world->createCar(testCar);
    EXPECT_TRUE(testCar->isCarAlive());
    EXPECT_TRUE(!world->isEndOfEpoch());
    for (unsigned int i = 0; i < EnvironmentConfig::MAX_TIME_ALIVE + 20; ++i) {
        testCar->timerStep();
    }
    testCar->getCarBody()->getBody()->SetLinearVelocity(b2Vec2_zero);
    world->updateCars();
    EXPECT_TRUE(!testCar->isCarAlive());
    EXPECT_TRUE(world->isEndOfEpoch());
}

TEST(WorldTest, WorldCurrentPopulationTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};
    PWorld world = std::make_unique<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    world->createCar(testCar);
    auto population = world->getCurrentPopulation();
    ASSERT_EQ(population.size(), 1);
    ASSERT_EQ(population[0], testCar);
    world->createCars(10);
    ASSERT_EQ(world->getCurrentPopulation().size(), 11);
}