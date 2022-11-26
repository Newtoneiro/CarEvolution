#ifndef CAREVOLUTION_WINDOW_H
#define CAREVOLUTION_WINDOW_H

#include <box2d/box2d.h>
#include ""

class Window {
public:
    Window();

    ~Window();

    int getNextScreenIndex() const;

    int getPreviousScreenIndex() const;

    void build();

    void destroy();

    void onEntry();

    void onExit();

    void update();

private:
    int SCREEN_INDEX_NO_SCREEN;
};

#endif //CAREVOLUTION_WINDOW_H
