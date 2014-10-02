#ifndef MENULOOSE_HPP_
#define MENULOOSE_HPP_

#include    "core/menu.hpp"
#include    "graphics/menuMain.h"

class MenuLoose : public Menu
{
public:
    MenuLoose(MenuView *view = nullptr);
    virtual ~MenuLoose();

    virtual void    onClick(unsigned int index, MenuItem &item);
};

#endif