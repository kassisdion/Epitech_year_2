#ifndef CORE_GAME_BOMBE_H_
#define CORE_GAME_BOMBE_H_

#include "utils/time.hpp"
#include "utils/geom/vec.hpp"

class Game;
class Player;

class Bomb
{
public:
    enum class State
    {
        STANDING,
        PRE_EXPLODE,
        EXPLODING,
    };

public:
    Bomb(Player &player, Vec2u pos = Vec2u(), unsigned int size = 3);
    ~Bomb();

public:
    bool destroyWall(const Vec2u &pos);
    void setExplosion();
    void checkPlayer();
    void update();
    void remove();

public:
    bool inExplosion(const Vec2u &pos);
    void goBack();

public:
    Vec2u pos;
    unsigned int size;
    State state;
    Clock clock;

public:
    Player &player;

public:
    unsigned char up_explosion;
    unsigned char down_explosion;
    unsigned char left_explosion;
    unsigned char right_explosion;
};

#endif /* CORE_GAME_BOMBE_H_ */
