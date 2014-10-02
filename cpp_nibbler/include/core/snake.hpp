//
// snake.hpp for snake.hpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Thu Apr  3 05:37:36 2014 florian faisant
// Last update Sat Apr  5 11:47:03 2014 florian faisant
//

#ifndef		SNAKE_HPP
# define	SNAKE_HPP

# include	<list>
# include	"common/event.hpp"
# include	"common/map.hpp"
# include	"utils/utils.hpp"
# include	"core/fruit.hpp"

class		Snake
{
public:
  Snake(int size);
  ~Snake();
public:
  bool		move(Map &map, Fruit &fruit, int *score);
  void		set_direction(EventType direction);
  void		init(Map &map);
private:
  int			size;
  EventType		direction;
  std::list<Coord>	list;
};

#endif
