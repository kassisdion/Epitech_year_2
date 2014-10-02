#ifndef MENUNEWGAME_HPP_
#define MENUNEWGAME_HPP_

#include    "core/menu.hpp"
#include    "graphics/menuWorld.h"

class MenuNewGame : public Menu
{
public:
    MenuNewGame(MenuView *view = nullptr);
    virtual ~MenuNewGame();

    virtual void    onClick(unsigned int index, MenuItem &item);
};

#endif