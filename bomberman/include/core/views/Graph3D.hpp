#ifndef __GRAPH_3D_H__
#define __GRAPH_3D_H__

#include <nds.h>

#include "core/view.hpp"
#include "core/screen.hpp"
#include "core/game/game.hpp"
#include "graph3d/SkyBox.hpp"
#include "graph3d/PlayerRender.hpp"
#include "graph3d/Cam.hpp"
#include "graph3d/MapRender.hpp"
#include "graph3d/BombRender.hpp"

class Graph3D : public View {
private:
	const Game 		&_game;
	PlayerRender 	*_playerRender;
	Cam				*_cam;
	SkyBox 			*_skyBox;
	MapRender 		*_mapRender;
	BombRender 		*_bombRender;

	void 			moveCam();

public:
	Graph3D(const Game & map, Screen *screen = nullptr);
	~Graph3D();

	void 		init();
	void 		draw();
	void 		display();
	void 		render();
};

#endif