#include "WorldType/UrbanWorld.hpp"

UrbanWorld::UrbanWorld(){}

UrbanWorld::~UrbanWorld(){}

void 		UrbanWorld::load(){
	g_texture[WALL] = Texture::genTexture((u8 *)urbanwall_pcx);
	g_texture[FLOOR] = Texture::genTexture((u8 *)urbanfloor_pcx);
	g_texture[EXTREMWALL] = Texture::genTexture((u8 *)urbanewall_pcx);
	g_texture[BACKWALL] = Texture::genTexture((u8 *)urbanfont_pcx);
	g_texture[BOMBERMAN] = Texture::genTexture((u8 *)bomberman_pcx);
	g_texture[EXPLOSE] = Texture::genTexture((u8 *)explose_pcx);
	g_texture[BOMBE] = Texture::genTexture((u8 *)bombe_pcx);
}