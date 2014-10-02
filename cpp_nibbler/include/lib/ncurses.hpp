//
// ncurses.hpp for nibbler in /home/dusterherz/Epitech/C++/cpp_nibbler/include/lib
// 
// Made by aude lejuez
// Login   <lejuez_a@epitech.net>
// 
// Started on  Mon Mar 31 10:43:22 2014 aude lejuez
// Last update Sat Apr  5 11:09:24 2014 florian faisant
//

#ifndef				NCURSES_H_
# define			NCURSES_H_

# include			<ncurses.h>
# include			"common/ilib.hpp"

extern "C"
ILib				*createLib();

class				NcursesLib : public ILib
{
public:
  NcursesLib();
  virtual ~NcursesLib();
public:
  virtual bool			init(int width, int height);
  virtual bool			drawMap(Map &map);
  virtual bool			endGame(int score);
  virtual std::list<EventType>	pollEvent();

private:
  WINDOW *win;
 };

#endif
