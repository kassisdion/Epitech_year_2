#include "core/events.hpp"
#include "core/view.hpp"

View::View(Screen *screen)
    : screen(screen)
{
}

View::~View()
{
}

void View::setScreen(Screen *screen)
{
    this->screen = screen;
}

Screen &View::getScreen()
{
    return *this->screen;
}

const Screen &View::getScreen() const
{
    return *this->screen;
}
