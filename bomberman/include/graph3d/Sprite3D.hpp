#ifndef __SPRITE_3D_H__
#define __SPRITE_3D_H__

#include <nds.h>
#include "graph3d/Texture.hpp"
#include "utils/color.hpp"

class Sprite3D {
public:
	Sprite3D();
	~Sprite3D();

	void 		draw(u32 * quadric_bin, float posX, float posY, float posZ,
										float sizeX, float sizeY, float sizeZ,
										float rotX, float rotY, float rotZ, int texture);
	void 		draw(u32 * quadric_bin, float posX, float posY, float posZ,
										float sizeX, float sizeY, float sizeZ,
										float rotX, float rotY, float rotZ, int texture, char argb[4]);

	void 		draw(u32 * quadric_bin, float posX, float posY, float posZ,
										float sizeX, float sizeY, float sizeZ,
										float rotX, float rotY, float rotZ, int texture, int color);
	
};

#endif