#include "core/game/bomb.hpp"
#include "core/game/game.hpp"
#include "core/debug.hpp"
#include "core/game/map.hpp"
#include "stdlib.h"

Bomb::Bomb(Player &player, Vec2u pos, unsigned int size)
    : player(player)
    , pos(pos)
    , size(size)
    , state(Bomb::State::STANDING)
    , clock(Timer::get(1))
    , up_explosion(0)
    , down_explosion(0)
    , left_explosion(0)
    , right_explosion(0)
{
}

Bomb::~Bomb()
{
}

bool Bomb::destroyWall(const Vec2u &pos)
{
  if (!this->player.game.map->check(pos, false))
    return true;

  Map::Tile &tile = this->player.game.map->at(pos);
  if (tile == Map::Tile::IWALL || tile == Map::Tile::DWALL)
    {
      if (tile == Map::Tile::DWALL)
	{
          tile = Map::Tile::EMPTY;
	  int tmp = rand() % 100;
	  if (tmp < 20)
	    {
	      int randNumber = (rand() % 3);
	      switch (randNumber)
		{
		case 0 :
		  tile = Map::Tile::LIFE;
		  break;
		case 1 :
		  tile = Map::Tile::RANGE;
		  break;
		case 2 :
		  tile = Map::Tile::BOMB;
		  break;
		}
	    }
	  this->up_explosion++;
	  this->player.score++;
	}
      return (true);
    }
  return (false);
}

void Bomb::setExplosion()
{
    for (this->up_explosion = 0; this->up_explosion < this->size; ++this->up_explosion)
    {
        Vec2u pos = this->pos;
        pos.y() += this->up_explosion + 1;
        if (destroyWall(pos) == true)
            break;
    }

    for (this->down_explosion = 0; this->down_explosion < this->size; ++this->down_explosion)
    {
        Vec2u pos = this->pos;
        pos.y() -= this->down_explosion + 1;
        if (destroyWall(pos) == true)
            break;
    }

    for (this->left_explosion = 0; this->left_explosion < this->size; ++this->left_explosion)
    {
        Vec2u pos = this->pos;
        pos.x() -= this->left_explosion + 1;
        if (destroyWall(pos) == true)
            break;
    }

    for (this->right_explosion = 0; this->right_explosion < this->size; ++this->right_explosion)
    {
        Vec2u pos = this->pos;
        pos.x() += this->right_explosion + 1;
        if (destroyWall(pos) == true)
            break;
    }
}

void Bomb::checkPlayer()
{
    std::list<Player *> players = this->player.game.players;

    for (Player *player: players)
    {
        const Vec2u &pos = player->getPos();
        if (this->inExplosion(pos))
        {
            player->die();
        }
    }
}

void Bomb::update()
{
  Timer::time_t current = this->clock.current(false);

  switch (this->state)
    {
    case Bomb::State::STANDING:
      if (current > 24000)
        {
          this->state = Bomb::State::PRE_EXPLODE;
          this->clock.reset(false);
        }
      break;
    case Bomb::State::PRE_EXPLODE:
      if (current > 10000)
	{
	  this->state = Bomb::State::EXPLODING;
          this->setExplosion();
          this->clock.reset(false);
	}
      break;
    case Bomb::State::EXPLODING:
      if (current > 10000)
        {
          this->checkPlayer();
          this->remove();
        }
      break;
    }
}

void Bomb::remove()
{
  this->player.game.bombs.remove(this);
  this->player.nbBombs++;
}

bool Bomb::inExplosion(const Vec2u &pos)
{
    auto test = [&](int dx, int dy) {
        Vec2u tmp(this->pos.x() + dx, this->pos.y() + dy);
        return tmp == pos;
    };

    if (test(0, 0))
        return true;

    for (unsigned int i = 0; i < this->left_explosion; ++i)
    {
        if (test(-(i + 1), 0))
            return true;
    }

    for (unsigned int i = 0; i < this->right_explosion; ++i)
    {
        if (test(i + 1, 0))
            return true;
    }

    for (unsigned int i = 0; i < this->up_explosion; ++i)
    {
        if (test(0, i + 1))
            return true;
    }

    for (unsigned int i = 0; i < this->down_explosion; ++i)
    {
        if (test(0, -(i + 1)))
            return true;
    }

    return false;
}

void Bomb::goBack()
{
  this->player.nbBombs++;
}
