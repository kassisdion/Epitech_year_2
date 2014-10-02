#include "menu/main.hpp"
#include "menu/solo.hpp"
#include "menu/menunbia.hpp"
#include "core/screen.hpp"
#include "core/views/menu.hpp"
#include "graphics/menuMain.h"
#include "core/debug.hpp"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(23, 15, 157, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(23, 80, 157, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(23, 140, 157, 40)),
    };
    return items;
}

MenuMain::MenuMain(MenuView *view) :
    Menu(createItems(), 3, view, menuMainBitmap, menuMainBitmapLen)
{
}

MenuMain::~MenuMain()
{
}

void MenuMain::onClick(unsigned int index, MenuItem &item)
{
    switch (index)
        {
            case 0 :
            {
                //jouer en solo
                view->setMenu(new MenuSolo());
                // Screens::upper().setView(new TotoView())
            }
            break;
            case 1 :
            {
                //jouer en multi
            }
            break;
            case 2 :
            {
                view->setMenu(new MenuNbIa());
            }
            break;
            default :
            {
                //BUG BUG BUG !!!
            }
            break;
        }
}