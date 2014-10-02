#include <tuple>
#include "core/game/game.hpp"
#include "core/game/bomb.hpp"
#include "core/game/ia.hpp"
#include "stdlib.h"

IA::IA(Game &game, Vec2u pos,
                Orientation orientation, unsigned int nbBombs)
    : Player(game, pos, orientation, nbBombs)
    , clock(Timer::get(3))
{
}

IA::~IA()
{
}

bool IA::isSafe(Vec2i &diff, bool debug)
{
  int x = this->pos.x() + diff.x();
  int y = this->pos.y() + diff.y();

  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;

  Vec2u tmp_pos((unsigned int)x, (unsigned int)y);

  for (Bomb *bomb: this->game.bombs)
    {
      if (bomb->inExplosion(tmp_pos) == true)
	{
	  return (false);
	}
    }
  return (true);
}


bool IA::checkPosition(Vec2i &diff)
{
  Map::Tile tmp = this->game.map->at(this->pos.x() + diff.x(), this->pos.y() + diff.y());

  if ((tmp != Map::Tile::IWALL) && (tmp != Map::Tile::DWALL))
    return (true);
  return (false);
}

bool IA::checkUp(bool unSafe)
{
  Vec2i tmp;

  tmp.y() = 1;
  tmp.x() = 0;
  if (checkPosition(tmp))
    if (isSafe(tmp) || unSafe)
      return (true);
  return (false);
}

bool IA::checkDown(bool unSafe)
{
  Vec2i tmp;

  tmp.y() = -1;
  tmp.x() = 0;
  if (checkPosition(tmp))
    if (isSafe(tmp) || unSafe)
      return (true);
  return (false);
}

bool IA::checkLeft(bool unSafe)
{
  Vec2i tmp;

  tmp.y() = 0;
  tmp.x() = -1;
  if (checkPosition(tmp))
    if (isSafe(tmp) || unSafe)
      return (true);
  return (false);
}

bool IA::checkRight(bool unSafe)
{
  Vec2i tmp;

  tmp.y() = 0;
  tmp.x() = 1;
  if (checkPosition(tmp))
    if (isSafe(tmp) || unSafe)
      return (true);
  return (false);
}

Vec2i IA::getPos(bool unSafe)
{
  Vec2i tmp(0, 0);

  if (unSafe == false)
    {
      if (checkUp(unSafe))
	return (tmp.x(0).y(1));
      if (checkDown(unSafe))
	return (tmp.x(0).y(-1));
      if (checkLeft(unSafe))
	return (tmp.x(-1).y(0));
      if (checkRight(unSafe))
	return (tmp.x(1).y(0));
    }
  else
    {
      int nb = rand() % 4;
      if ((nb == 0) && (checkPosition(tmp.x(0).y(1))))
	return (tmp);
      if ((nb == 1) && (checkPosition(tmp.x(0).y(-1))))
	return (tmp);
      if ((nb == 2) && (checkPosition(tmp.x(-1).y(0))))
	return (tmp);
      if ((nb == 3) && (checkPosition(tmp.x(1).y(0))))
	return (tmp);
    }
  return (getPos(true));
}

void IA::action()
{
  Vec2i tmp(0, 0);

  if (this->isSafe(tmp, true))
    this->putBomb();
  Vec2i diff(this->getPos(false));
  this->moveDiff(diff);
}

void IA::update()
{
  if (clock.current() > 10000)
    {
      this->action();
      clock.reset();
    }
}
