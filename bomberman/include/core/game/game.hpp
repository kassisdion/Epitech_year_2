#ifndef CORE_GAME_GAME_H_
#define CORE_GAME_GAME_H_

#include <list>
#include <iostream>
#include "core/game/map.hpp"
#include "core/game/player.hpp"
#include "core/game/bomb.hpp"
#include "utils/encodable.hpp"

class Game: public Encodable
{
public:
    Game(Map *map = nullptr);
    ~Game();

public:
    Player &getPlayer();
    const Player &getPlayer() const;

public:
    bool hasBomb(const Vec2u &pos) const;

public:
    virtual void encode(cpacker_buf_t *buf) const;
    static Game *decode(cpacker_buf_t *buf);

    static Game *decodeStream(std::istream &in);

public:
    /**
     * The game map.
     * Feel free to modify it as you like. :)
     */
    Map *map;

    /**
     * List of actual players in this game.
     */
    std::list<Player *> players;

    /**
     * Main player.
     */
    Player *player;

    /**
     * List of bombes.
     */
    std::list<Bomb *> bombs;

    /**
     * Is paused?
     */
    bool pause;
};

#endif /* CORE_GAME_GAME_H_ */
