//
// mapEditorSize.hpp for bomberman in /home/alice/Epitech/2017/Teck2/C++/BomberMan/BomberManLocal/MapEditor/EditorMap
// 
// Made by alice groux
// Login   <groux_a@epitech.net>
// 
// Started on  Mon Jun  2 17:56:21 2014 alice groux
// Last update Sun Jun  8 18:38:04 2014 alice groux
//

#ifndef		_MAPEDITORSIZE_HPP_
# define	_MAPEDITORSIZE_HPP_

# include	<string>
# include	<iostream>
# include	<nds.h>

# include	"../../include/core/menu.hpp"

class		MapEditorSize : public Menu
{
public:

  MapEditorSize(MenuView *view);
  ~MapEditorSize();
  void onClick(unsigned int index, MenuItem &item);
  
protected:

};

#endif
