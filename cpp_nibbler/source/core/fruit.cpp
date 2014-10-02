//
// fruit.cpp for fruit.cpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Thu Apr  3 21:24:15 2014 florian faisant
// Last update Sat Apr  5 11:25:53 2014 florian faisant
//

#include	<cstdlib>
#include	"core/fruit.hpp"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void	Fruit::init(Map &pmap)
{
  pop(pmap);
}


static bool	pop_rdm(Map &map)
{
  int	new_x = rand() % map.get_width();
  int	new_y = rand() %map.get_height();

  if (map.get_map()[new_y][new_x] == EMPTY)
    {
      map.get_map()[new_y][new_x] = FRUIT;
      return (true);
    }
  return (false);
}

static bool	pop_first_case(Map &pmap)
{
  CaseType **map = pmap.get_map();
  unsigned int x = 0;
  unsigned int y = 0;

  while (y < pmap.get_height())
    {
      x = 0;
      while (x < pmap.get_width())
	{
	  if (map[y][x] == EMPTY)
	    {
	      map[y][x] = FRUIT;
	      return (true);
	    }
	  x++;
	}
      y++;
    }
  return (false);
}

bool	Fruit::pop(Map &map)
{
  int	i = 0;

  while (i < 10)
    {
      if (pop_rdm(map) == true)
	return (true);
      i++;
    }
  return (pop_first_case(map));
}
