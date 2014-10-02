#ifndef __MAP_RENDER_H__
#define __MAP_RENDER_H__

#include <nds.h>
#include "core/game/game.hpp"
#include "graph3d/Cube.hpp"
#include "graph3d/Texture.hpp"
#include "utils/geom/vec.hpp"
#include "graph3d/Sprite3D.hpp"
#include "data/Bomb.h"

#define CUBE_VIEW_X 7
#define CUBE_VIEW_Y_UP 8
#define CUBE_VIEW_Y_DOWN 5

class MapRender {
private:
	Cube 		_cube;
    const Game  &_game;
    Sprite3D 	_sprite3D;

public:
	MapRender(const Game &game);
	~MapRender();

	void 		drawWall();
	void 		drawMap();
};

#endif
