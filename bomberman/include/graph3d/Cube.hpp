#ifndef __CUBE_H__
#define __CUBE_H__

#include <nds.h>
#include "Texture.hpp"

class Cube{
public:
	Cube();
	~Cube();
	
	void 		draw(float posX, float posY,
						float posZ, float sizeX,
						float sizeY, float sizeZ,
						int textureUp, int textureDown, int textureFace);
};

#endif