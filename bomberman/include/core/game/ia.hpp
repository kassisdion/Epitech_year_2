#ifndef CORE_GAME_IA_H_
#define CORE_GAME_IA_H_

#include "core/game/player.hpp"
#include "utils/time.hpp"

class IA: public Player
{
public:
    IA(Game &game, Vec2u pos = Vec2u(1, 1), Orientation orientation = Orientation::NORTH, unsigned int nbBombs = 1);
    virtual ~IA();

public:
    virtual void update();

private:
  bool checkPosition(Vec2i &pos);
  Vec2i getPos(bool unSafe);
  void action();
  bool isSafe(Vec2i &diff, bool debug = false);
  bool checkUp(bool unSafe);
  bool checkDown(bool unSafe);
  bool checkLeft(bool unSafe);
  bool checkRight(bool unSafe);

private:
  Clock clock;
};

#endif /* CORE_GAME_IA_H_ */
