#include "WorldType/SnowWorld.hpp"

SnowWorld::SnowWorld(){}

SnowWorld::~SnowWorld(){}

void 		SnowWorld::load(){
	g_texture[WALL] = Texture::genTexture((u8 *)snowwall_pcx);
	g_texture[FLOOR] = Texture::genTexture((u8 *)snowfloor_pcx);
	g_texture[EXTREMWALL] = Texture::genTexture((u8 *)snowewall_pcx);
	g_texture[BACKWALL] = Texture::genTexture((u8 *)snowfont_pcx);
	g_texture[BOMBERMAN] = Texture::genTexture((u8 *)bomberman_pcx);
	g_texture[EXPLOSE] = Texture::genTexture((u8 *)explose_pcx);
	g_texture[BOMBE] = Texture::genTexture((u8 *)bombe_pcx);
}