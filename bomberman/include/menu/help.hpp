#ifndef MENU_HELP_H_
#define MENU_HELP_H_

#include "core/menu.hpp"

class MenuHelp: public Menu
{
public:
    MenuHelp(MenuView *view = nullptr);
    virtual ~MenuHelp();

public:
    virtual void onClick(unsigned int index, MenuItem &item);
};

#endif /* MENU_HELP_H_ */
