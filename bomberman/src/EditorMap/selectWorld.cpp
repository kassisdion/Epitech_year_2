//
// selectWorld.cpp for bomberman in /home/alice/Epitech/2017/Teck2/C++/BomberMan/BBM/src/EditorMap
// 
// Made by alice groux
// Login   <groux_a@epitech.net>
// 
// Started on  Sat Jun  7 17:12:24 2014 alice groux
// Last update Sun Jun 15 15:32:46 2014 alice groux
//

#include		<string>
#include		<iostream>

#include		"EditorMap/selectWorld.hpp"
#include        "graphics/editeurType.h"
# include		"WorldType/WorldType.hpp"
# include		"WorldType/ForestWorld.hpp"
# include		"WorldType/MarioWorld.hpp"
# include		"WorldType/SandWorld.hpp"
# include		"WorldType/SnowWorld.hpp"
# include		"WorldType/UrbanWorld.hpp"
# include		"core/menu.hpp"
# include		"core/controllers/game.hpp"

static Menu::MenuItem	*createItem()
{
  static Menu::MenuItem	item[] = {
    Menu::MenuItem(Menu::MenuItem::ItemRect(5, 40, 120, 40)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(130, 40, 120, 40)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(5, 90, 120, 40)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(130, 90, 120, 40)),
    Menu::MenuItem(Menu::MenuItem::ItemRect(70, 140, 120, 40)),
  };
  return item;
}

void			SelectWorld::onClick(unsigned int index, Menu::MenuItem &item)
{
  switch (index)
    {
    case 0 :
      {
        this->_worldType = new UrbanWorld();
        this->_map->type = Map::Type::URBAN;
        GameController::setup(this->_map, *this->_worldType);
      }
      break;
    case 1 :
      {
       this->_worldType = new ForestWorld();
        this->_map->type = Map::Type::FOREST;
       GameController::setup(this->_map, *this->_worldType);
      }
      break;
    case 2 :
      {
        this->_worldType = new SnowWorld();
        this->_map->type = Map::Type::SNOW;
        GameController::setup(this->_map, *this->_worldType);
      }
      break;
    case 3 :
      {
	this->_worldType = new SandWorld();
        this->_map->type = Map::Type::SAND;
	GameController::setup(this->_map, *this->_worldType);
      }
      break;
    case 4 :
      {
	this->_worldType = new MarioWorld();
        this->_map->type = Map::Type::MARIO;
	GameController::setup(this->_map, *this->_worldType);
      }
      break;
    default :
      {
	// BUG BUG BUG !!
      }
      break;
    }
}

SelectWorld::SelectWorld(MenuView *view, Map * map) :
  Menu(createItem(), 5, view, editeurTypeBitmap, editeurTypeBitmapLen)
{
  this->_map = map;
}

SelectWorld::~SelectWorld()
{ }

WorldType	&SelectWorld::getWorldType() const
{
  return (*this->_worldType);
}

void		SelectWorld::setWorldType(WorldType *wt)
{
  this->_worldType = wt;
}
