#ifndef MENUPAUSE_HPP_
#define MENUPAUSE_HPP_

#include    "core/menu.hpp"
#include    "core/controllers/game.hpp"

class MenuPause : public Menu
{
public:
    MenuPause(GameController &game, MenuView *view = nullptr);
    virtual ~MenuPause();

    virtual void    onClick(unsigned int index, MenuItem &item);

private:
    GameController &game;
};

#endif