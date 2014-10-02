#include	"menu/solo.hpp"
#include    "menu/new_game.hpp"
#include    "menu/main.hpp"
#include    "menu/load_game.hpp"
#include    "EditorMap/mapEditorSize.hpp"
#include    "core/screen.hpp"
#include    "core/views/menu.hpp"
#include    "graphics/menuSolo.h"
#include    "core/debug.hpp"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(23, 15, 157, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(23, 80, 157, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(23, 140, 157, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(210, 10, 30, 40)),
    };
    return items;
}

MenuSolo::MenuSolo(MenuView *view) :
    Menu(createItems(), 4, view, menuSoloBitmap, menuSoloBitmapLen)
{
}

MenuSolo::~MenuSolo()
{
}

void	MenuSolo::onClick(unsigned int index, MenuItem &item)
{
	switch (index)
		{
			case 0 :
			{
                view->setMenu(new MenuNewGame(view));
				//nouvelle partie
			}
			break;
			case 1 :
			{
                view->setMenu(new MenuLoadGame(view));
				//charger partie
			}
			break;
			case 2 :
			{
                view->setMenu(new MapEditorSize(view));
				//editeur de map
			}
			break;
			case 3 :
			{
                view->setMenu(new MenuMain(view));
				//retour à MenuMain
			}
			break;
			default :
			{
				//BUG BUG BUG !!!
			}
			break;
		}
}