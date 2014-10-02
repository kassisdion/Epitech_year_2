#ifndef __SNOW_WORLD_H__
#define __SNOW_WORLD_H__

#include <nds.h>
#include "WorldType.hpp"
#include "data/snowwall.h"
#include "data/snowewall.h"
#include "data/snowfloor.h"
#include "data/snowfont.h"
#include "data/snowsky.h"

class SnowWorld : public WorldType{
public:
	SnowWorld();
	virtual ~SnowWorld();

	virtual void 		load();
};

#endif