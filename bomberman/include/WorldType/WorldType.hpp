#ifndef __WORLD_TYPE_H__
#define __WORLD_TYPE_H__

#include <nds.h>
#include "../graph3d/Texture.hpp"
#include "data/bomberman.h"
#include "data/bombeexplose.h"
#include "data/explose.h"
#include "data/bombe.h"


class WorldType {
public:
	WorldType();
	virtual ~WorldType(){}

	void 				unload();
	virtual void		load() = 0;
};

#endif