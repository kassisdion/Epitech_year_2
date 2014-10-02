#include "core/game/player.hpp"
#include "core/game/bomb.hpp"
#include "core/game/game.hpp"
#include "core/debug.hpp"
#include "stdlib.h"

Player::Player(Game &game, Vec2u pos,
                Orientation orientation, unsigned int nbBombs)
    : game(game)
    , pos(pos)
    , oldPos(pos)
    , orientation(orientation)
    , state(Player::State::ALIVE)
    , nbBombs(nbBombs)
    , score(0)
    , life(3)
    , bombSize(3)
{
  this->setColor();
}

Player::~Player()
{
}

const void Player::setColor()
{
  static Color colors[] ={
    { .color = 0x5900A5 },
    { .color = 0xFFFFFF },
    { .color = 0xFF0000 },
    { .color = 0x13F200 },
    { .color = 0x0000FF },
    { .color = 0xEFF200 },
    { .color = 0xF200B5 },
    { .color = 0x13F2FA },
    { .color = 0xFA9613 },
    { .color = 0xBB13FA }
  };
  static unsigned int index = 0;

  this->color = colors[index++];
  if (index >= (sizeof(colors) / sizeof(*colors)))
    index = 0;
}

const Vec2u &Player::getPos() const
{
    return this->pos;
}

const Vec2u &Player::getOldPos() const
{
    return this->oldPos;
}

void Player::move(Vec2u &pos)
{
    int dx = pos.x() - this->pos.x();
    int dy = pos.y() - this->pos.y();
    this->moveDiff(dx, dy);
}

void Player::move(unsigned int x, unsigned int y)
{
    Vec2u newPos(x, y);
    this->move(newPos);
}

void Player::moveDiff(Vec2i &diff)
{
  Vec2u newPos(this->pos.x() + diff.x(), this->pos.y() + diff.y());
  if (!this->game.map->check(newPos))
    return;

  Map::Tile &tile = this->game.map->at(newPos);

  this->obtain(tile);
  this->oldPos = this->pos;
  this->pos.x() += diff.x();
  this->pos.y() += diff.y();

  if (diff.x() == 1 && diff.y() == 0)
    this->orientation = Player::Orientation::EAST;
  else if (diff.x() == 0 && diff.y() == 1)
    this->orientation = Player::Orientation::SOUTH;
  else if (diff.x() == -1 && diff.y() == 0)
    this->orientation = Player::Orientation::WEST;
  else if (diff.x() == 0 && diff.y() == -1)
    this->orientation = Player::Orientation::NORTH;
}

void Player::moveDiff(int dx, int dy)
{
    Vec2i diff(dx, dy);
    this->moveDiff(diff);
}

void Player::putBomb()
{
    if (this->nbBombs > 0 && !this->game.hasBomb(this->pos))
    {
        Bomb *bomb = new Bomb(*this, this->pos, this->bombSize);
        this->game.bombs.push_back(bomb);
        this->nbBombs--;
    }
}

void Player::remove()
{
    this->game.players.remove(this);
}

bool Player::isAlive()
{
    return this->state == State::ALIVE;
}

bool Player::isDead()
{
    return this->state == State::DEAD;
}

void Player::die()
{
  if (this->life == 0)
    {
      this->state = State::DEAD;
      this->remove();
      return;
    }
  this->life--;
}

void Player::obtain(Map::Tile &tile)
{
  switch (tile)
    {
    case Map::Tile::LIFE:
      if (this->life < 3)
	this->life++;
      break;
    case Map::Tile::RANGE:
      this->bombSize++;
      break;
    case Map::Tile::BOMB :
      if (this->nbBombs < 3)
	this->nbBombs++;
      break;
    }
  tile = Map::Tile::EMPTY;
}

void Player::update()
{
}

void Player::encode(cpacker_buf_t *buf) const
{
  cpacker_buf_put_uint32(buf, this->color.color);
  cpacker_buf_put_uint32(buf, this->life);
  cpacker_buf_put_uint32(buf, this->bombSize);
  cpacker_buf_put_uint32(buf, this->nbBombs);
  cpacker_buf_put_uint32(buf, this->score);
  cpacker_buf_put_uint32(buf, this->pos.x());
  cpacker_buf_put_uint32(buf, this->pos.y());
}

Player *Player::decode(cpacker_buf_t *buf, Game &game)
{
  Player *player = new Player(game);

  player->color.color = cpacker_buf_read_uint32(buf);
  player->life = cpacker_buf_read_uint32(buf);
  player->bombSize = cpacker_buf_read_uint32(buf);
  player->nbBombs = cpacker_buf_read_uint32(buf);
  player->score = cpacker_buf_read_uint32(buf);
  player->pos.x() = cpacker_buf_read_uint32(buf);
  player->pos.y() = cpacker_buf_read_uint32(buf);
  return player;
}
