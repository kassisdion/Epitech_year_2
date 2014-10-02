#include "nds.h"
#include "core/menu.hpp"
#include "core/debug.hpp"

Menu::Menu(MenuItem *items, size_t nitems, MenuView *view, const void *bgSrc, const uint32 bgSize)
    : items(items)
    , nitems(nitems)
    , view(view)
    , bgSrc(bgSrc)
    , bgSize(bgSize)
{
}

Menu::~Menu()
{
}

void Menu::onClick(Vec2u &pos)
{
    for (size_t index = 0; index < this->nitems; index++)
    {
        MenuItem &item = this->items[index];

        bool contains = item.rect.contains(pos);

        if (contains)
        {
            this->onClick(index, item);
        }
    }
}

void Menu::setView(MenuView *view)
{
    this->view = view;
}

MenuView &Menu::getView()
{
    return *this->view;
}

const MenuView &Menu::getView() const
{
    return *this->view;
}
