#include "WindowHandle.h"

/*
Autor: Bartosz Latosek
Cel: Plik z implementacja WindowHandle - dekoratora do kontrolowania wyswietlania
     swiata.
*/
WindowHandle::WindowHandle() noexcept
    :sf::RenderWindow(sf::VideoMode({EnviromentConfig::WINDOW_WIDTH, EnviromentConfig::WINDOW_HEIGHT}), "SFML window") {

    sf::View view(sf::Vector2f(EnviromentConfig::WINDOW_WIDTH  / 2,
                               EnviromentConfig::WINDOW_HEIGHT / 2),
                  sf::Vector2f(EnviromentConfig::WINDOW_WIDTH,
                               EnviromentConfig::WINDOW_HEIGHT));

    _view = std::make_unique<sf::View>(view);
    setView(*_view);
}

void WindowHandle::step(const b2Vec2 view_pos, const std::vector<PFigure> elements) noexcept {
    _view->setCenter(view_pos.x + 100, view_pos.y + 100);
    setView(*_view);
    clear();
    for (auto shape: elements) {
        draw(shape->getShape());
    }
    display();
}