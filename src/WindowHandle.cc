#include <sstream>
#include "WindowHandle.h"

/*
Autor: Bartosz Latosek
Cel: Plik z implementacja WindowHandle - dekoratora do kontrolowania wyswietlania
     swiata.
*/
WindowHandle::WindowHandle() noexcept
        : sf::RenderWindow(sf::VideoMode({EnviromentConfig::WINDOW_WIDTH, EnviromentConfig::WINDOW_HEIGHT}),
                           "SFML window") {

    sf::View view(sf::Vector2f(EnviromentConfig::WINDOW_WIDTH / 2,
                               EnviromentConfig::WINDOW_HEIGHT / 2),
                  sf::Vector2f(EnviromentConfig::WINDOW_WIDTH,
                               EnviromentConfig::WINDOW_HEIGHT));

    _view = std::make_unique<sf::View>(view);
    setView(*_view);
}

void WindowHandle::step(const b2Vec2 view_pos, const std::vector<PFigure> elements, const unsigned int epoch) noexcept {
    _view->setCenter(view_pos.x + 100, view_pos.y);
    setView(*_view);
    clear();
    for (auto shape: elements) {
        draw(shape->getShape());
    }
    displayText(epoch, view_pos.x);
    display();
}

void WindowHandle::displayText(int epoch, float distance) {
    std::ostringstream oss;
    oss << "Current epoch: " << epoch << " Current distacne: " << distance;
    std::string text = oss.str();
    setTitle(text);
}