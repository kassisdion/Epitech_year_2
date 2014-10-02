#ifndef __MARIO_WORLD_H__
#define __MARIO_WORLD_H__

#include <nds.h>
#include "WorldType.hpp"
#include "data/mariowall.h"
#include "data/marioewall.h"
#include "data/mariofloor.h"
#include "data/mariofont.h"
#include "data/sandsky.h"


class MarioWorld : public WorldType{
public:
	MarioWorld();
	virtual ~MarioWorld();

	virtual void 		load();
};


#endif