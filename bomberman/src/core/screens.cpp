#include <nds.h>
#include "core/screen.hpp"
#include "core/screens.hpp"
#include "core/debug.hpp"

static Screen *_upper;
static Screen *_lower;

void Screens::init()
{
    _upper = new Screen(nullptr, Screen::Mode::TwoD, Screen::Priority::Primary);
    _lower = new Screen(nullptr, Screen::Mode::TwoD, Screen::Priority::Secondary);

    // Debug::init();
}

Screen &Screens::upper()
{
    return *_upper;
}

Screen &Screens::lower()
{
    return *_lower;
}

void Screens::update(const Events &events)
{
    Screens::upper().update(events);
    Screens::lower().update(events);
}

void Screens::render()
{
    Screens::upper().render();
    Screens::lower().render();
}
