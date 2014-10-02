#include "graph3d/Texture.hpp"

int g_texture[NBR_TEXTURE];

int Texture::genTexture(u8 *image_pcx){
	sImage pcx;
	int 	textureId;

	if (loadPCX((u8*)image_pcx, &pcx) == 0)
        return -1;
	image8to16(&pcx);
	glGenTextures(1, &textureId);
	glBindTexture(0, textureId);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_128 , TEXTURE_SIZE_128, 0, TEXGEN_TEXCOORD, pcx.image.data8);
	imageDestroy(&pcx);
	return textureId;
}
