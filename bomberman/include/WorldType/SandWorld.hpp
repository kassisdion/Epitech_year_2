#ifndef __SAND_WORLD_H__
#define __SAND_WORLD_H__

#include <nds.h>
#include "WorldType.hpp"
#include "data/sandwall.h"
#include "data/sandewall.h"
#include "data/sandfloor.h"
#include "data/sandfont.h"
#include "data/sandsky.h"

class SandWorld : public WorldType{
public:
	SandWorld();
	virtual ~SandWorld();

	virtual void 		load();
};

#endif