#include <gtest/gtest.h>
#include <vector>

#include "../src/Car.h"
#include "../src/World.h"

/*
Author: Bartosz Latosek
Purpose: Unit tests for Car class
*/
typedef std::shared_ptr<World> PWorld;

TEST(CarTest, ContructorTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};

    PCar car = std::make_unique<Car>(bodyRadiuses, wheelRadiuses);
    EXPECT_TRUE(car->getCarBody() != nullptr);
    EXPECT_TRUE(car->getLeftCircle() != nullptr);
    EXPECT_TRUE(car->getRightCircle() != nullptr);
}

TEST(CarTest, WorldCreateBodyTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};

    PWorld world = std::make_shared<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);

    EXPECT_TRUE(testCar != nullptr);
    EXPECT_TRUE(testCar->getCarBody() != nullptr);
    EXPECT_TRUE(testCar->getLeftCircle() != nullptr);
    EXPECT_TRUE(testCar->getRightCircle() != nullptr);
    world->createCar(testCar);
    ASSERT_EQ(testCar->getCarBody()->getBody()->GetPosition().x, 0);
    ASSERT_EQ(testCar->getCarBody()->getBody()->GetPosition().y, 0);
    ASSERT_EQ(testCar->getCarBody()->getBody()->GetAngle(), 0);
}

TEST(CarTest, SetIsCarAliveTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};

    PCar car = std::make_unique<Car>(bodyRadiuses, wheelRadiuses);
    EXPECT_TRUE(car->isCarAlive());
    ASSERT_EQ(car->getCarBody()->getShape().getFillColor(), sf::Color::White);

    car->setIsCarAlive(false);
    EXPECT_TRUE(car->isCarAlive() == false);
    ASSERT_EQ(car->getCarBody()->getShape().getFillColor(), sf::Color::Blue);
}

TEST(CarTest, CreateBodyTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};

    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    PWorld world = std::make_shared<World>();
    world->createCar(testCar);

    auto genome = testCar->getGenome();
    ASSERT_EQ(genome.first, bodyRadiuses);
    ASSERT_EQ(genome.second, wheelRadiuses);
}

TEST(CarTest, CreateCarsTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};

    PWorld world = std::make_shared<World>();
    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);

    world->createBody(testCar->getCarBody(), false);
    world->createBody(testCar->getCarBody(), false);
    world->createBody(testCar->getCarBody(), false);

    EXPECT_TRUE(testCar->getCarBody()->getBody() != nullptr);
    EXPECT_TRUE(testCar->getRightCircle()->getBody() != nullptr);
    EXPECT_TRUE(testCar->getLeftCircle()->getBody() != nullptr);
}

TEST(CarTest, UpdateShapeTest) {
    std::vector<unsigned int> bodyRadiuses = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<float> wheelRadiuses = {1, 1};

    PCar testCar = std::make_shared<Car>(bodyRadiuses, wheelRadiuses);
    PWorld world = std::make_shared<World>();
    world->createCar(testCar);

    testCar->updateShape();
    ASSERT_EQ(testCar->getCarBody()->getShape().getPosition().x, 0);
    ASSERT_EQ(testCar->getCarBody()->getShape().getPosition().y, 0);

    testCar->getCarBody()->getBody()->SetTransform(b2Vec2(1, 1), 0);
    testCar->updateShape();
    ASSERT_EQ(testCar->getCarBody()->getShape().getPosition().x, 1);
    ASSERT_EQ(testCar->getCarBody()->getShape().getPosition().y, 1);

    testCar->setIsCarAlive(false);
    testCar->getCarBody()->getBody()->SetTransform(b2Vec2(10, 10), 0);
    testCar->updateShape();
    ASSERT_EQ(testCar->getCarBody()->getShape().getPosition().x, 1);
    ASSERT_EQ(testCar->getCarBody()->getShape().getPosition().y, 1);
}
