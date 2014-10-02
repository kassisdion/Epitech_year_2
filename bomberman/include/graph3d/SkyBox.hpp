#ifndef __SKYBOX_H__
#define __SKYBOX_H__

#include <nds.h>
#include "Texture.hpp"
#include "Cube.hpp"

class SkyBox {
private:
	Cube 		_cube;
	float 		_sizeX;
	float 		_sizeZ;
public:
	SkyBox(float sizeX, float sizeZ);
	~SkyBox();
	
	void 			draw();
};
#endif