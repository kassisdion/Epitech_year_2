#ifndef MENUWIN_HPP_
#define MENUWIN_HPP_

#include    "core/menu.hpp"

class MenuWin : public Menu
{
public:
    MenuWin(MenuView *view = nullptr);
    virtual ~MenuWin();

    virtual void    onClick(unsigned int index, MenuItem &item);
};

#endif