#ifndef __PLAYER_RENDER_3D_H__
#define __PLAYER_RENDER_3D_H__

#include <nds.h>
#include "Cube.hpp"
#include "Sprite3D.hpp"
#include "data/Bomberman.h"
#include "core/game/game.hpp"
#include "core/debug.hpp"

class PlayerRender {
private:
	Cube 		_cube;
	Sprite3D 	_sprite3D;
	const Game 	&_game;

public:
	PlayerRender(const Game &game);
	~PlayerRender();
	
	void			drawAll();

	void 			draw(int posX, int posZ, Player::Orientation ori, int color);
};

#endif