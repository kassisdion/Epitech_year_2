//
// selectWorld.hpp for bomberman in /home/alice/Epitech/2017/Teck2/C++/BomberMan/BBM/src/EditorMap
// 
// Made by alice groux
// Login   <groux_a@epitech.net>
// 
// Started on  Sat Jun  7 17:12:17 2014 alice groux
// Last update Sun Jun 15 15:30:38 2014 alice groux
//

#ifndef			_SELECT_WORLD_HPP_
# define		_SELECT_WORLD_HPP_

# include		<string>
# include		<iostream>

# include		"WorldType/WorldType.hpp"
# include		"core/menu.hpp"
# include		"core/game/map.hpp"

class			SelectWorld : public Menu
{
public:

  SelectWorld(MenuView *view, Map *map);
  virtual ~SelectWorld();

  virtual void		onClick(unsigned int index, Menu::MenuItem &item);

  WorldType		&getWorldType() const;
  void			setWorldType(WorldType *wt);

protected:

  WorldType		*_worldType;
  Map			*_map;
};

#endif
