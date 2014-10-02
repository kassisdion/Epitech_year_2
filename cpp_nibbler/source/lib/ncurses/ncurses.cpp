//
// lib_ncurses.cpp for lib_ncurses.cpp in /home/faisant/Bureau/projet/cpp_nibbler/source/lib/lib_ncurses
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 15:36:08 2014 florian faisant
// Last update Sat Apr  5 19:02:02 2014 aude lejuez
//

#include		<ncurses.h>
#include		<list>
#include		<sstream>
#include		<iostream>
#include		<string>
#include		"lib/ncurses.hpp"
#include		"common/event.hpp"

static			bool error(const std::string &msg)
{
  std::cout << msg << std::endl;
  return (false);
}

extern "C"
ILib			*createLib()
{
  return new NcursesLib();

}

NcursesLib::~NcursesLib()
{
  delwin(this->win);
  endwin();
}

NcursesLib::NcursesLib()
{
}

bool			NcursesLib::init(int width, int height)
{
  initscr();
  if (start_color() == ERR)
    return (error("Can't init the color"));
  cbreak();
  noecho();
  this->win = newwin(height + 2, width + 2, 0, 0);
  keypad(this->win, true);
  nodelay(this->win, true); 
  init_pair(1, COLOR_WHITE, COLOR_GREEN);
  init_pair(2, COLOR_WHITE, COLOR_RED);
  return true;
}

bool			NcursesLib::drawMap(Map &map)
{
  int			i;
  int			j;
  int			height;
  int			width;
  CaseType		**tmpMap;

  i = 0;
  height = map.get_height();
  width = map.get_width();
  tmpMap = map.get_map();
  i = 0;
  while (i <= width + 1)
    {
      mvwprintw(this->win, 0, i, "=");
      mvwprintw(this->win, height + 1, i, "=");
      i++;
    }
  i = 1;
  while (i <= height)
    {
      mvwprintw(this->win, i, 0, "|");
      mvwprintw(this-> win, i, width + 1, "|"); 
      i++;
    }
  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  switch(tmpMap[i][j])
	    {
	    case FRUIT:
	      attron(COLOR_PAIR(2));
	      mvwprintw(this->win, i + 1, j + 1, "+");
	      attroff(COLOR_PAIR(2));
	      break;
	    case SNAKE:
	      attron(COLOR_PAIR(1));
	      mvwprintw(this->win, i + 1, j + 1, "-");
	      attroff(COLOR_PAIR(1));
	      break;
	    case EMPTY:
	      mvwprintw(this->win, i + 1, j + 1, " ");
	      break;
	    }
	  j++;
	}
      i++;
    }
  wrefresh(this->win);
  return true;
}

std::list<EventType>	NcursesLib::pollEvent()
{
  int			ch;
  std::list<EventType>	event;

  while ((ch = wgetch(this->win)) != ERR)
    {
      switch(ch)
	{
	case KEY_LEFT:
	  event.push_front(LEFT);
	  break;
	case KEY_RIGHT:
	  event.push_front(RIGHT);
	  break;
	case KEY_UP:
	  event.push_front(UP);
	  break;
	case KEY_DOWN:
	  event.push_front(DOWN);
	  break;
	case 27:
	  event.push_front(EXIT);
	}
    }
  return event;
}

bool		NcursesLib::endGame(int score)
{
  std::ostringstream    scoring;
  int			ch;


  mvwprintw(this->win, 0, 0, "Game Over\n Score : %d\n Continue ? (Y/n)", score);
  while ((ch = wgetch(this->win)))
    {
      switch(ch)
	{
	case 'y':
	  return true;
	  break;
	case 'n':
	  return false;
	  break;
	case KEY_ENTER:
	  return true;
	  break;
	case 27:
	  return false;
	  break;
	default:
	  break;
	}
    }
  return false;
}
