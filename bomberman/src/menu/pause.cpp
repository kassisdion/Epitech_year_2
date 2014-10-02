#include "menu/pause.hpp"
#include "graphics/pause.h"
#include "core/debug.hpp"
#include "utils/encoder.hpp"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(0, 160, 80, 30)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(90, 160, 80, 30)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(175, 160, 80, 30)),
    };
    return items;
}


MenuPause::MenuPause(GameController &game, MenuView *view)
    : Menu(createItems(), 3, view, pauseBitmap, pauseBitmapLen)
    , game(game)
{
}

MenuPause::~MenuPause()
{
}

void MenuPause::onClick(unsigned int index, Menu::MenuItem &item)
{
  switch (index)
    {
    case 0:
      GameController::stop(false);
      break;
    case 1 :
      Encoder::save("game.sav", this->game.game);
      break;
    case 2 :
      this->game.resume();
      break;
    default :
      break;
    }
}
