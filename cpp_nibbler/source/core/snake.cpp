//
// snake.cpp for snake in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Thu Apr  3 05:39:34 2014 florian faisant
// Last update Sat Apr  5 11:47:43 2014 florian faisant
//

#include	<stdio.h>
#include	"core/snake.hpp"
#include	"utils/utils.hpp"
#include	"common/map.hpp"

Snake::Snake(int size)
{
  this->size = size;
  this->direction = RIGHT;
}

Snake::~Snake()
{
}

void		Snake::init(Map &pmap)
{
  CaseType **map = pmap.get_map();
  int midle_x = pmap.get_width() / 2;
  int midle_y = pmap.get_height() / 2;

  map[midle_y][midle_x - 1] = SNAKE;
  map[midle_y][midle_x] = SNAKE;
  map[midle_y][midle_x + 1] = SNAKE;

  this->list.push_front(Coord(midle_x - 1, midle_y));
  this->list.push_front(Coord(midle_x, midle_y));
  this->list.push_front(Coord(midle_x + 1, midle_y));
}

void		Snake::set_direction(EventType direction)
{
  if (direction == LEFT && this->direction == RIGHT)
    return;
  else if (direction == RIGHT && this->direction == LEFT)
    return;
  else if (direction == UP && this->direction == DOWN)
    return;
  else if (direction == DOWN  && this->direction == UP)
    return;
  else
    this->direction = direction;
}

bool		Snake::move(Map &pmap, Fruit &fruit, int *score)
{
  CaseType **map = pmap.get_map();
  Coord current_head = list.front();
  Coord end = list.back();
  unsigned int current_x = current_head.get_x();
  unsigned int current_y = current_head.get_y();
  unsigned int new_x = current_x;
  unsigned int new_y = current_y;

  switch (this->direction)
    {
    case LEFT:
      new_x = current_x - 1;
      break;
    case RIGHT:
      new_x = current_x + 1;
      break;
    case DOWN:
      new_y = current_y + 1;
      break;
    case UP:
      new_y = current_y - 1;
      break;
    default:
      break;
    }
  if (new_y >= pmap.get_height() || new_x >= pmap.get_width())
    return (false);

  switch (map[new_y][new_x])
    {
    case SNAKE:
      return (false);
      break;
    case FRUIT:
      if (fruit.pop(pmap) == false)
        return (false);
      *score += 1;
      break;
    case EMPTY:
      list.pop_back();
      map[end.get_y()][end.get_x()] = EMPTY;
      break;
    }
  list.push_front(Coord(new_x, new_y));
  map[new_y][new_x] = SNAKE;
  return (true);
}
