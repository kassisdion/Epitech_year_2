//
// coord.cpp for coord.cpp in /home/faisant/Bureau/projet/cpp_nibbler/source/utils
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Thu Apr  3 06:56:02 2014 florian faisant
// Last update Thu Apr  3 07:48:24 2014 florian faisant
//

#include	"utils/utils.hpp"

Coord::Coord(unsigned int x, unsigned int y)
{
  this->x = x;
  this->y = y;
}

void		Coord::set_coord(unsigned int x, unsigned int y)
{
  this->x = x;
  this->y = y;
}

unsigned int	Coord::get_x()
{
  return (this->x);
}

unsigned int	Coord::get_y()
{
  return (this->y);
}
