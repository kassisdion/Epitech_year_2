#ifndef __URBAN_WORLD_H__
#define __URBAN_WORLD_H__

#include <nds.h>
#include "WorldType.hpp"
#include "data/urbanwall.h"
#include "data/urbanewall.h"
#include "data/urbanfloor.h"
#include "data/urbanfont.h"
#include "data/urbansky.h"

class UrbanWorld : public WorldType {
public:
	UrbanWorld();
	virtual ~UrbanWorld();

	virtual void		load();

};

#endif