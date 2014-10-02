//
// opengl.hpp for nibbler in /home/dusterherz/Epitech/C++/cpp_nibbler
// 
// Made by aude lejuez
// Login   <lejuez_a@epitech.net>
// 
// Started on  Tue Apr  1 09:56:07 2014 aude lejuez
// Last update Sat Apr  5 18:03:25 2014 aude lejuez
//

#ifndef				OPENGL_H_
# define			OPENGL_H_

# include			<SDL/SDL.h>
# include			<GL/gl.h>
# include			"common/ilib.hpp"

extern "C"
ILib				*createLib();

class				OpenglLib : public ILib
{
public:
  OpenglLib();
  ~OpenglLib();
public:
  virtual bool			init(int height, int width);
  virtual bool			drawMap(Map &map);
  virtual bool			endGame(int score);
  virtual std::list<EventType>	pollEvent();

private:
  SDL_Surface			*window;
};

#endif
