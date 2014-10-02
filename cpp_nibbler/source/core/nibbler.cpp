//
// core.cpp for core in /home/faisant/Bureau/projet/cpp_nibbler/source/core
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 31 18:38:45 2014 florian faisant
// Last update Sat Apr  5 18:03:28 2014 florian faisant
//

#include	<unistd.h>
#include	<stdio.h>
#include	"core/nibbler.hpp"
#include	"core/exception.hpp"

Nibbler::Nibbler(int width, int height, const std::string &path)
  : map(width, height),
    dl_lib(path),
    snake(4),
    fruit()
{
  this->speed = 100000;
  this->score = 0;
  run(width, height);
}

Nibbler::~Nibbler()
{
  delete (this->lib);
}

bool		Nibbler::check_event()
{
  std::list<EventType> list = lib->pollEvent();
  while (!list.empty())
    {
      EventType event = list.front();
      if (event == EXIT)
	{
	  if (this->lib->endGame(this->score) == true)
	    return (false);
	}
      else
	this->snake.set_direction(event);
      list.pop_front();
    }
  return (true);
}

bool		Nibbler::action()
{
  if (this->snake.move(this->map, this->fruit, &(this->score)) == false)
    return (false);
  else
    this->lib->drawMap(this->map);
  return (true);
}

void		Nibbler::run(int width, int height)
{
  bool	run;

  run = true;
  this->lib = this->dl_lib.get_lib();
  this->snake.init(this->map);
  this->fruit.init(this->map);
  if(this->lib->init(width, height) == false)
    throw core_exception("Impossible d'initialiser la lib");
  while (run)
    {
      if (check_event() == false)
	run = false;
      else if (action() == false)
	{
	  run = false;
	  this->lib->endGame(this->score);
	}
      usleep(this->speed);
    }
}
