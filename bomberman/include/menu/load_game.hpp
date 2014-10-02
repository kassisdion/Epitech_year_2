#ifndef MENULOADGAME_HPP_
#define MENULOADGAME_HPP_

#include	"core/menu.hpp"

class MenuLoadGame : public Menu
{
public:
	MenuLoadGame(MenuView *view = nullptr);
	virtual ~MenuLoadGame();

	virtual void	onClick(unsigned int index, MenuItem &item);

};

#endif