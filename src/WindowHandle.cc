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
    
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("./arial.ttf")) exit(-1);
    text.setCharacterSize(EnviromentConfig::FONT_SIZE);
    text.setFillColor(sf::Color::White);
    text.setFont(font);

    _fontTemplate = std::make_unique<sf::Font>(font);
    _textTemplate = std::make_unique<sf::Text>(text);
    _view = std::make_unique<sf::View>(view);
    setView(*_view);
}

void WindowHandle::step(const b2Vec2 view_pos, const std::vector<PFigure> elements) noexcept {
    _view->setCenter(view_pos.x + 100, view_pos.y);
    setView(*_view);
    clear();
    for (auto shape: elements) {
        draw(shape->getShape());
    }
    displayText(1, 1);
    display();
}

void WindowHandle::displayText(int epoch, float distance) {
    std::string text = "DUPA";
    _textTemplate->setString(text);
    draw(*_textTemplate.get());
}