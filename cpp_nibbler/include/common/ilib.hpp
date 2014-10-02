/*
** ilib.h for ilib.h in /home/faisant/Bureau/projet/cpp_nibbler/include/lib
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 24 17:38:16 2014 florian faisant
// Last update Sat Apr  5 11:16:38 2014 florian faisant
*/

#ifndef		ILIB_H_
# define	ILIB_H_

#include	<list>
#include	"common/map.hpp"
#include	"common/event.hpp"

class		ILib
{
public:
  virtual ~ILib() {}
public:
  virtual bool			init(int height, int width) = 0;
  virtual bool			drawMap(Map &map) = 0;
  virtual bool			endGame(int score) = 0;
  virtual std::list<EventType>	pollEvent() = 0;
};

#endif
