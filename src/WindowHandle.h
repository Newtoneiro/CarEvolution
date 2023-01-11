#ifndef CAREVOLUTION_WINDOWHANDLE_H
#define CAREVOLUTION_WINDOWHANDLE_H

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include <memory>

#include "../config/EnviromentConfig.h"
#include "../src/Figure.h"

/*
Autor: Bartosz Latosek
Cel: Plik naglowkowy WindowHandle - dekoratora do kontrolowania wyswietlania
     swiata.
*/
typedef std::shared_ptr<Figure> PFigure;

class WindowHandle: public sf::RenderWindow {
public:
    WindowHandle() noexcept;
    
    void step(const b2Vec2 view_pos, const std::vector<PFigure> elements) noexcept;
private:
    std::unique_ptr<sf::View> _view;
};


#endif //CAREVOLUTION_WINDOWHANDLE_H
