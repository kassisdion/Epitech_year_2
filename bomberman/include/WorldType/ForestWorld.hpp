#ifndef __FOREST_WORLD_H__
#define __FOREST_WORLD_H__

#include <nds.h>
#include "WorldType.hpp"

#include "data/treewall.h"
#include "data/treeewall.h"
#include "data/treefloor.h"
#include "data/treefont.h"
#include "data/treesky.h"

class ForestWorld : public WorldType {
public:
	ForestWorld();
	virtual ~ForestWorld();

	virtual void 			load();
};

#endif