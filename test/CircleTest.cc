#include <gtest/gtest.h>

#include "../src/Circle.h"
#include "../src/World.h"
#include "../config/FigureCategories.h"

/*
Autor: Radosław Kostrzewski
Cel: Implementacja testów do klasy Circle
*/

typedef std::shared_ptr<Circle> TestCircle;
typedef std::shared_ptr<World> TestWorld;

TEST(CircleTest, OnlyRadiusConstructorTest) {
    const float radius = 8;
    TestCircle circle = std::make_unique<Circle>(radius);
    EXPECT_TRUE(circle != nullptr);
    auto origin = circle->getShape().getOrigin();
    EXPECT_EQ(origin.x, radius);
    EXPECT_EQ(origin.y, radius);
    EXPECT_EQ(circle->getRadius(), radius);

}

TEST(CircleTest, FullConstructorTest) {
    const float radius = 8;
    const float posX = 10;
    const float posY = 20;
    TestCircle circle = std::make_unique<Circle>(radius, posX, posY);
    EXPECT_TRUE(circle != nullptr);
    auto origin = circle->getShape().getOrigin();
    EXPECT_EQ(origin.x, radius);
    EXPECT_EQ(origin.y, radius);
    EXPECT_EQ(circle->getRadius(), radius);

}

TEST(CircleTest, CreateBodyTest) {
    TestCircle circle = std::make_unique<Circle>(8);
    TestWorld world = std::make_unique<World>();
    world->createBody(circle, false);
    EXPECT_TRUE(circle->getBody() != nullptr);
    EXPECT_TRUE(circle->getBody()->GetFixtureList() != nullptr);
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetShape() != nullptr);
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetShape()->GetType() == b2Shape::e_circle);
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetShape()->m_radius == circle->getRadius());
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetDensity() == EnvironmentConfig::FIGURE_DENSITY);
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetFriction() == EnvironmentConfig::FIGURE_FRICTION);
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetRestitution() == EnvironmentConfig::FIGURE_RESTITUTION);
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetFilterData().categoryBits == FigureCategories(circleCategory));
    EXPECT_TRUE(circle->getBody()->GetFixtureList()->GetFilterData().maskBits == FigureCategories(groundCategory));
}

TEST(CircleTest, isAliveTest) {
    TestCircle circle = std::make_unique<Circle>(8);
    TestWorld world = std::make_unique<World>();
    world->createBody(circle, false);
    EXPECT_TRUE(circle->isAlive());
    circle->setIsAlive(false);
    EXPECT_TRUE(!circle->isAlive());
}

