//
// map.cpp for map.cpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 18:44:12 2014 florian faisant
// Last update Sat Apr  5 11:51:10 2014 florian faisant
//

#include	"common/map.hpp"

Map::Map(unsigned int width, unsigned int height)
  : width(width),
    height(height)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  this->map = new CaseType*[height];
  while (i < height)
    {
      this->map[i] = new CaseType[width];
      j = 0;
      while (j < width)
	{
	  this->map[i][j] = EMPTY; 
	  j++;
	}
      i++;
    }
}

Map::~Map()
{
  unsigned int	i;

  i = 0;
  while (i < this->height)
    {
      delete[] (this->map[i]);
      i++;
    }
  delete[] this->map;
}

unsigned int	Map::get_width() const
{
  return (this->width);
}

unsigned int	Map::get_height() const
{
  return (this->height);
}

CaseType	**Map::get_map()
{
  return (this->map);
}
