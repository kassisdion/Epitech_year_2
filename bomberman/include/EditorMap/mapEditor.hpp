//
// mapEditor.hpp for bomberman in /home/alice/Epitech/2017/Teck2/C++/BomberMan/BomberManLocal/MapEditor
// 
// Made by alice groux
// Login   <groux_a@epitech.net>
// 
// Started on  Fri May 23 10:03:40 2014 alice groux
// Last update Sat Jun 14 19:41:55 2014 alice groux
//

#ifndef		_MAPEDITOR_HPP_
# define	_MAPEDITOR_HPP_

# include	<string>
# include	<iostream>
# include	<nds.h>

# include	"menu/main.hpp"
# include	"core/game/map.hpp"

class		MapEditor
{
public:

  MapEditor(const unsigned int height, const unsigned int width);
  ~MapEditor();

  void		putDWall(unsigned int x, unsigned int y, Map::Tile tile);
  void		putIWall(unsigned int x, unsigned int y, Map::Tile tile);
  void		putWall(unsigned int x, unsigned int y);
  void		takeDestrWall();
  void		takeIndestrWall();
  void		playWithMap();
  void		backMenu();
  void		eraseMap();
  void		saveMap();

  unsigned int	getHeight() const;
  unsigned int	getWidth() const;
  void		setHeight(const unsigned int height);
  void		setWidth(const unsigned int width);

protected:

  unsigned int	_height;
  unsigned int	_width;
  bool		_isDestr;

public:

  Map		*_map;
};

#endif
