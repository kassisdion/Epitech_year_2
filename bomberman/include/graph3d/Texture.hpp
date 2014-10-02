#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <nds.h>
#include <nds/arm9/image.h>

#define NBR_TEXTURE 8

enum e_texture{
	EXTREMWALL,
	WALL,
	BACKWALL,
	FLOOR,
	BOMBE,
	BOMBERMAN,
	EXPLOSE,
};

extern int g_texture[NBR_TEXTURE];

class Texture {
public:
	static int 	genTexture(u8 * image_pcx);
};

#endif