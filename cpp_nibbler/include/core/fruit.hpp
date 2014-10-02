//
// fruit.hpp for fruit.hpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Fri Apr  4 10:48:39 2014 florian faisant
// Last update Sat Apr  5 11:19:15 2014 florian faisant
//

#ifndef		FRUIT_H
# define	FRUIT_H

# include	"common/map.hpp"

class		Fruit
{
public:
  Fruit();
  ~Fruit();
public:
  void	init(Map &map);
  bool	pop(Map &map);
};

#endif
