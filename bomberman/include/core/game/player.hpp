#ifndef CORE_GAME_PLAYER_H_
#define CORE_GAME_PLAYER_H_

#include "core/game/map.hpp"
#include "utils/geom/vec.hpp"
#include "utils/color.hpp"
#include "utils/encodable.hpp"

class Game;

class Player: public Encodable
{
public:
    enum class Orientation
    {
        NORTH,
        SOUTH,
        EAST,
        WEST,
    };

public:
    enum class State
    {
        ALIVE,
        DEAD,
    };

public:
    Player(Game &game, Vec2u pos = Vec2u(1, 1), Orientation orientation = Orientation::NORTH, unsigned int nbBombs = 1);
    virtual ~Player();

public:
    const Vec2u &getPos() const;
    const Vec2u &getOldPos() const;

    /**
     * Change the player's position.
     *
     * @warning This method modify player's orientation too.
     *
     * @param pos New position.
     */
    void move(Vec2u &pos);
    void move(unsigned int x, unsigned int y);

    /**
     * Change the player's position.
     *
     * @warning This method modify player's orientation too.
     *
     * @param pos Position diff.
     */
    void moveDiff(Vec2i &diff);
    void moveDiff(int dx, int dy);

public:
    void putBomb();

public:
    void remove();

public:
    const void setColor();

public:
    bool isAlive();
    bool isDead();

    void die();

public:
    void obtain(Map::Tile &tile);

    virtual void update();

public:
    virtual void encode(cpacker_buf_t *buf) const;
    static Player *decode(cpacker_buf_t *buf, Game &game);

protected:
    Vec2u pos;
    Vec2u oldPos;

public:
    unsigned int nbBombs;
    unsigned int score;
    unsigned int life;
    unsigned int bombSize;
    union Color color;
    Game &game;

public:
    Orientation orientation;
    State state;
};

#endif /* CORE_GAME_PLAYER_H_ */
