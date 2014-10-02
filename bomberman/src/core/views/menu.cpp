#include "core/bomberman.hpp"
#include "core/menu.hpp"
#include "core/screens.hpp"
#include "core/view.hpp"
#include "core/views/menu.hpp"

MenuView::MenuView(Screen *screen, Menu *menu)
    : View(screen)
    , menu(menu)
    , clock(Timer::get(2))
{
}

MenuView::~MenuView()
{
    delete this->menu;
}

void MenuView::update(const Events &events)
{
    Vec2u pos(events.touch.x, events.touch.y);

    if (events.touch.isTouch && this->clock.current() > 10000)
    {
        this->clock.reset();
        this->menu->onClick(pos);
    }
}

void MenuView::render()
{
    swiWaitForVBlank();
    dmaCopy(this->menu->bgSrc, bgGetGfxPtr(this->getScreen().bg), this->menu->bgSize);
}

void MenuView::setMenu(Menu *menu)
{
    if (menu != nullptr)
    {
        menu->setView(this);
    }

    Menu *old = this->menu;
    Bomberman::getInstance().nextTick([old]() {
        delete old;
    });
    this->menu = menu;
}

Menu &MenuView::getMenu()
{
    return *this->menu;
}

const Menu &MenuView::getMenu() const
{
    return *this->menu;
}
