#include "core/game/game.hpp"

Game::Game(Map *map)
    : map(map)
    , pause(false)
{
    this->player = new Player(*this);
    this->players.push_back(this->player);
}

Game::~Game()
{
}

Player &Game::getPlayer()
{
    return *this->player;
}

const Player &Game::getPlayer() const
{
    return *this->player;
}

bool Game::hasBomb(const Vec2u &pos) const
{
    for (Bomb *bomb: this->bombs)
    {
        if (bomb->pos == pos)
            return true;
    }

    return false;
}

void Game::encode(cpacker_buf_t *buf) const
{
  this->map->encode(buf);

  cpacker_buf_put_size(buf, this->players.size());
  for (Player *player: this->players)
    player->encode(buf);
  for (Bomb *bomb: this->bombs)
    bomb->goBack();
}

Game *Game::decode(cpacker_buf_t *buf)
{
    Map *map = Map::decode(buf);
    Game *game = new Game(map);
    game->players.clear();

    unsigned int numPlayers = cpacker_buf_read_size(buf);
    for (unsigned int i = 0; i < numPlayers; ++i)
    {
        Player *player = Player::decode(buf, *game);
        game->players.push_back(player);
    }

    return game;
}

Game *Game::decodeStream(std::istream &in)
{
    cpacker_buf_t buf;

    cpacker_buf_init(&buf);

    in.seekg(0, in.end);
    unsigned int length = in.tellg();
    in.seekg(0, in.beg);

    cpacker_buf_ensure_size(&buf, length);
    in.read(cpacker_buf_data(&buf), length);

    Game *game = Game::decode(&buf);

    cpacker_buf_destroy(&buf);

    return game;
}
