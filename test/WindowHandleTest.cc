#include <gtest/gtest.h>
#include <vector>

#include "../src/WindowHandle.h"
#include "../src/Circle.h"
#include "../config/EnvironmentConfig.h"

/*
Author: Radoslaw Kostrzewski
Purpose: Unit tests for WindowHandle class
*/
typedef std::unique_ptr<WindowHandle> PWindowHandle;

TEST(WindowHandleTest, ContructorTest) {
    PWindowHandle windowHandle = std::make_unique<WindowHandle>();

    sf::Vector2u windowsize = sf::Vector2u(EnvironmentConfig::WINDOW_WIDTH,
                               EnvironmentConfig::WINDOW_HEIGHT);
    sf::View expectedView(sf::Vector2f(EnvironmentConfig::WINDOW_WIDTH / 2,
                               EnvironmentConfig::WINDOW_HEIGHT / 2),
                  sf::Vector2f(EnvironmentConfig::WINDOW_WIDTH,
                               EnvironmentConfig::WINDOW_HEIGHT));
    
    EXPECT_TRUE(windowHandle->isOpen());
    ASSERT_EQ(windowHandle->getSize(), windowsize);
    ASSERT_EQ(windowHandle->getView().getCenter(), expectedView.getCenter());
    ASSERT_EQ(windowHandle->getView().getSize(), expectedView.getSize());
}

TEST(WindowHandleTest, StepTest) {
    PWindowHandle windowHandle = std::make_unique<WindowHandle>();

    const PFigure testCircle = std::make_shared<Circle>(5.0f);
    const std::vector<PFigure> testElements {testCircle};
    const unsigned int testEpoch = 1.0f;

    b2Vec2 testViewPos = b2Vec2(100.0f, 100.0f);
    
    windowHandle->step(testViewPos, testElements, testEpoch);

    ASSERT_EQ(windowHandle->getView().getCenter(), sf::Vector2f(testViewPos.x + 100, testViewPos.y));
}