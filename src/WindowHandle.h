#ifndef CAREVOLUTION_WINDOWHANDLE_H
#define CAREVOLUTION_WINDOWHANDLE_H

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include <memory>
#include <string>

#include "../config/EnvironmentConfig.h"
#include "../src/Figure.h"

/*
Author: Bartosz Latosek
Purpose: Header file for WindowHandle - decorator that makes it easier to manage window
*/
typedef std::shared_ptr<Figure> PFigure;

class WindowHandle : public sf::RenderWindow {
public:
    WindowHandle() noexcept;

    void step(const b2Vec2 view_pos, const std::vector<PFigure> elements, const unsigned int epoch) noexcept;

private:
    void displayText(int epoch, float distance);

    std::unique_ptr<sf::View> view;
    std::unique_ptr<sf::Text> textTemplate;
};


#endif //CAREVOLUTION_WINDOWHANDLE_H
