//
// mapEditor.cpp for bomberman in /home/alice/Epitech/2017/Teck2/C++/BomberMan/BomberManLocal/MapEditor
// 
// Made by alice groux
// Login   <groux_a@epitech.net>
// 
// Started on  Fri May 23 10:03:15 2014 alice groux
// Last update Sun Jun 15 20:01:00 2014 florian faisant
//

#include		<string>
#include		<iostream>
#include		<nds.h>

#include		"EditorMap/mapEditor.hpp"
#include		"core/views/menu.hpp"
#include		"core/screens.hpp"
#include		"core/controllers/game.hpp"
#include		"graphics/menuWorld.h"
#include		"WorldType/WorldType.hpp"
#include		"WorldType/SandWorld.hpp"
#include		"EditorMap/mapEditorSize.hpp"
#include		"EditorMap/selectWorld.hpp"
#include		"utils/encoder.hpp"
#include		"utils/encodable.hpp"

void			MapEditor::putDWall(unsigned int x, unsigned int y, Map::Tile tile)
{
  if (tile != Map::Tile::DWALL)
    {
      this->_map->at(x, y) = Map::Tile::DWALL;
    }
  else
    {
      this->_map->at(x, y) = Map::Tile::EMPTY;
    }
}

void			MapEditor::putIWall(unsigned int x, unsigned int y, Map::Tile tile)
{
  if (tile != Map::Tile::IWALL)
    {
         this->_map->at(x, y) = Map::Tile::IWALL;
    }
  else
    {
      this->_map->at(x, y) = Map::Tile::EMPTY;
    }
}

void			MapEditor::putWall(unsigned int x, unsigned int y)
{
  if (this->_isDestr == true)
    {
      putDWall(x, y, this->_map->at(x, y));
    }
  else
    {
      putIWall(x, y, this->_map->at(x, y));
    }
}

void			MapEditor::takeDestrWall()
{
  this->_isDestr = true;
}

void			MapEditor::takeIndestrWall()
{
  this->_isDestr = false;
}

void			MapEditor::playWithMap()
{
  Screens::upper().setMode(Screen::Mode::TwoD);
  Screens::lower().setMode(Screen::Mode::TwoD);
  Screens::lower().refresh();

  MenuView		*view = new MenuView();
  Screens::lower().setView(view);
  view->setMenu(new SelectWorld(view, this->_map));
}

void			MapEditor::backMenu()
{
    Screens::upper().setMode(Screen::Mode::TwoD);
    Screens::lower().setMode(Screen::Mode::TwoD);
    Screens::lower().refresh();
    
  MenuView		*view = new MenuView();
  Screens::lower().setView(view);
  view->setMenu(new MenuMain());
}

void			MapEditor::eraseMap()
{
        Screens::upper().setMode(Screen::Mode::TwoD);
    Screens::lower().setMode(Screen::Mode::TwoD);
    Screens::lower().refresh();

  MenuView		*view = new MenuView();
  Screens::lower().setView(view);
  view->setMenu(new MapEditorSize(view));
}

void			MapEditor::saveMap()
{
  Encoder::save("map_editor.sav", *this->_map);
}

unsigned int		MapEditor::getHeight() const
{
  return (this->_height);
}

unsigned int		MapEditor::getWidth() const
{
  return (this->_width);
}

void			MapEditor::setHeight(const unsigned int height)
{
  if (height >= 5)
    this->_height = height;
}

void			MapEditor::setWidth(const unsigned int width)
{
  if (width >= 5)
    this->_width = width;
}

MapEditor::MapEditor(const unsigned int height, const unsigned int width)
{
  this->_height = height;
  this->_width = width;
  this->_map = new Map(width, height, Map::Tile::EMPTY);
}

MapEditor::~MapEditor()
{ }
