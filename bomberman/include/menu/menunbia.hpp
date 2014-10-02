#ifndef MENUNBIA_HPP_
#define MENUNBIA_HPP_

#include    "core/menu.hpp"
#include    "graphics/menuMain.h"

class MenuNbIa : public Menu
{
public:
    MenuNbIa(MenuView *view = nullptr);
    virtual ~MenuNbIa();

    virtual void    onClick(unsigned int index, MenuItem &item);
};

#endif