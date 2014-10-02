#include "menu/settings.hpp"
#include "core/views/menu.hpp"
#include "graphics/menuSolo.h"

static Menu::MenuItem *createItems()
{
  static Menu::MenuItem items[] = {
    Menu::MenuItem(Menu::MenuItem::ItemRect(9, 30, 66, 64)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(94, 30, 66, 64)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(180, 30, 66, 64)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(10, 114, 66, 64)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(212, 156, 38, 34)),
  };
  return items;
}

MenuSettings::MenuSettings(MenuView *view) :
  Menu(createItems(), 4, view, menuSoloBitmap, menuSoloBitmapLen)
{
}

MenuSettings::~MenuSettings()
{
}

void    MenuSettings::onClick(unsigned int index, MenuItem &item)
{
  switch (index)
    {
    case 0 :
      {
	//0 ia
      }
      break;
    case 1 :
      {
	//1 ia
      }
      break;
    case 2 :
      {
	//2 ia
      }
      break;
    case 3 :
      {
	//3 ia
      }
      break;
    default :
      {
      }
      break;
    }
}
