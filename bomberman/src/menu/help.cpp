#include "menu/help.hpp"

static Menu::MenuItem items[] = {
    Menu::MenuItem(Menu::MenuItem::ItemRect(23, 15, 157, 40)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(23, 80, 157, 40)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(23, 140, 157, 40)),
};

MenuHelp::MenuHelp(MenuView *view)
    : Menu(items, 3, view)
{
}

MenuHelp::~MenuHelp()
{
}

void MenuHelp::onClick(unsigned int index, Menu::MenuItem &item)
{
}
