#include "utils/encoder.hpp"
#include "core/controllers/game.hpp"
#include "WorldType/SandWorld.hpp"
#include "core/game/map.hpp"
#include "menu/load_game.hpp"
#include "menu/solo.hpp"
#include "core/screen.hpp"
#include "core/views/menu.hpp"
#include "graphics/menuSave.h"

static Menu::MenuItem *createItems()
{
  static Menu::MenuItem items[] = {
    Menu::MenuItem(Menu::MenuItem::ItemRect(14, 25, 180, 60)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(14, 105, 180, 60)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(210, 3, 40, 35)),
  };
  return items;
}

MenuLoadGame::MenuLoadGame(MenuView *view) :
    Menu(createItems(), 3, view, menuSaveBitmap, menuSaveBitmapLen)
{
}

MenuLoadGame::~MenuLoadGame()
{
}

void MenuLoadGame::onClick(unsigned int index, MenuItem &item)
{
  switch (index)
    {
    case 0 :
      {
	if (!Encoder::fileExists("map_editor.sav"))
	  return;
	Map *map = Encoder::load<Map>("map_editor.sav");
	//SandWorld world;
	//GameController::setup(map, world);
      }
      break;
    case 1 :
      {
	//chargement de game
      }
      break;
    case 2 :
      {
        view->setMenu(new MenuSolo());
      }
    default :
      {
      }
      break;
    }
}
