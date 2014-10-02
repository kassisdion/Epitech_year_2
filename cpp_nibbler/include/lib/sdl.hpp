//
// sdl.hpp for nibbler in /home/dusterherz/Epitech/C++/cpp_nibbler/include/lib
// 
// Made by aude lejuez
// Login   <lejuez_a@epitech.net>
// 
// Started on  Mon Mar 31 10:43:22 2014 aude lejuez
// Last update Sat Apr  5 11:13:06 2014 florian faisant
//

#ifndef				SDL_H_
# define			SDL_H_

# include			<SDL/SDL.h>
# include			"common/ilib.hpp"

extern "C"
ILib				*createLib();

class				SdlLib : public ILib
{
public:
  SdlLib();
  virtual ~SdlLib();
public:
  virtual bool			init(int width, int height);
  virtual bool			drawMap(Map &map);
  virtual bool			endGame(int score);
  virtual std::list<EventType>	pollEvent();

private:
  SDL_Surface			*window;
  SDL_Surface			*snake;
  SDL_Surface			*fruit;
  SDL_Surface			*background;
};

#endif
