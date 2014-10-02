#ifndef __BOMBRENDER_H__
#define __BOMBRENDER_H__

#include <nds.h>
#include "graph3d/Texture.hpp"
#include "graph3d/Cube.hpp"
#include "core/game/game.hpp"
#include "data/Bomb.h"
#include "graph3d/Sprite3D.hpp"

class BombRender {
private:
	Sprite3D 	_sprite3D;
	const Game 	&_game;

public:
	BombRender(const Game &g);
	~BombRender();

	void 		drawAll();
	void 		draw(float x, float y, Bomb::State explose, char up, char down, char left, char right);
};

#endif