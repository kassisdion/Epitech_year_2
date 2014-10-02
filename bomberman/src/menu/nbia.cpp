#include "menu/main.hpp"
#include "menu/menunbia.hpp"
#include "core/screen.hpp"
#include "core/views/menu.hpp"
#include "graphics/menuIA.h"
#include "core/bomberman.hpp"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(15, 15, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(90, 15, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(150, 15, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(200, 40, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(15, 75, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(80, 75, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(150, 75, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(15, 135, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(80, 135, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(150, 135, 40, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(210, 115, 40, 35)),
    };
    return items;
}

MenuNbIa::MenuNbIa(MenuView *view) :
    Menu(createItems(), 11, view, menuIABitmap, menuIABitmapLen)
{
}

MenuNbIa::~MenuNbIa()
{
}

void MenuNbIa::onClick(unsigned int index, MenuItem &item)
{
    switch (index)
        {
            case 0 :
            Bomberman::getInstance().numIAs = 1;
            this->view->setMenu(new MenuMain());
            break;
            case 1 :
            Bomberman::getInstance().numIAs = 2;
            this->view->setMenu(new MenuMain());
            break;
            case 2 :
            Bomberman::getInstance().numIAs = 3;
            this->view->setMenu(new MenuMain());
            break;
            case 3 :
            Bomberman::getInstance().numIAs = 4;
            this->view->setMenu(new MenuMain());
            break;
            case 4 :
            Bomberman::getInstance().numIAs = 5;
            this->view->setMenu(new MenuMain());
            break;
            case 5 :
            Bomberman::getInstance().numIAs = 6;
            this->view->setMenu(new MenuMain());
            break;
            case 6 :
            Bomberman::getInstance().numIAs = 7;
            this->view->setMenu(new MenuMain());
            break;
            case 7 :
            Bomberman::getInstance().numIAs = 8;
            this->view->setMenu(new MenuMain());
            break;
            case 8 :
            Bomberman::getInstance().numIAs = 9;
            this->view->setMenu(new MenuMain());
            break;
            case 9 :
            Bomberman::getInstance().numIAs = 0;
            this->view->setMenu(new MenuMain());
            break;
            case 10 :
            this->view->setMenu(new MenuMain());
            break;
            default :
            break;
        }
}