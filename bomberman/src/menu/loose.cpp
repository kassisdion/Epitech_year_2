#include "menu/loose.hpp"
#include "menu/main.hpp"
#include "core/screen.hpp"
#include "core/views/menu.hpp"
#include "graphics/defaite.h"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(0, 0, 256, 192)),
    };
    return items;
}

MenuLoose::MenuLoose(MenuView *view) :
    Menu(createItems(), 1, view, defaiteBitmap, defaiteBitmapLen)
{
}

MenuLoose::~MenuLoose()
{
}

void MenuLoose::onClick(unsigned int index, MenuItem &item)
{
    switch (index)
        {
            case 0:
                view->setMenu(new MenuMain());
            break;
            default:
            //bug
            break;
        }
}