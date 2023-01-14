#include <sstream>
#include "WindowHandle.h"

/*
Autor: Bartosz Latosek
Cel: Plik z implementacja WindowHandle - dekoratora do kontrolowania wyswietlania
     swiata.
*/
WindowHandle::WindowHandle() noexcept
        : sf::RenderWindow(sf::VideoMode({EnvironmentConfig::WINDOW_WIDTH, EnvironmentConfig::WINDOW_HEIGHT}),
                           "SFML window") {

    sf::View newView(sf::Vector2f(EnvironmentConfig::WINDOW_WIDTH / 2,
                               EnvironmentConfig::WINDOW_HEIGHT / 2),
                  sf::Vector2f(EnvironmentConfig::WINDOW_WIDTH,
                               EnvironmentConfig::WINDOW_HEIGHT));

    view = std::make_unique<sf::View>(newView);
    setView(*view);
}

void WindowHandle::step(const b2Vec2 view_pos, const std::vector<PFigure> elements, const unsigned int epoch) noexcept {
    view->setCenter(view_pos.x + 100, view_pos.y);
    setView(*view);
    clear();
    for (auto shape: elements) {
        draw(shape->getShape());
    }
    displayText(epoch, view_pos.x);
    display();
}

void WindowHandle::displayText(int epoch, float distance) {
    std::ostringstream oss;
    oss << "Current epoch: " << epoch << " Current distance: " << distance;
    std::string text = oss.str();
    setTitle(text);
}