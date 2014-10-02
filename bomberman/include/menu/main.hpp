#ifndef MENUMAIN_HPP_
#define MENUMAIN_HPP_

#include	"core/menu.hpp"
#include    "graphics/menuMain.h"

class MenuMain : public Menu
{
public:
	MenuMain(MenuView *view = nullptr);
	virtual ~MenuMain();

	virtual void	onClick(unsigned int index, MenuItem &item);
};

#endif