#ifndef	MENUSOLO_HPP_
#define MENUSOLO_HPP_

#include    "graphics/menuSolo.h"
#include	"core/menu.hpp"

class MenuSolo : public Menu
{
public:
	MenuSolo(MenuView *view = nullptr);
	virtual ~MenuSolo();

	virtual void	onClick(unsigned int index, MenuItem &item);
};

#endif