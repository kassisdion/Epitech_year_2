#include "WorldType/SandWorld.hpp"

SandWorld::SandWorld(){}

SandWorld::~SandWorld(){}

void 		SandWorld::load(){
	g_texture[WALL] = Texture::genTexture((u8 *)sandwall_pcx);
	g_texture[FLOOR] = Texture::genTexture((u8 *)sandfloor_pcx);
	g_texture[EXTREMWALL] = Texture::genTexture((u8 *)sandewall_pcx);
	g_texture[BACKWALL] = Texture::genTexture((u8 *)sandfont_pcx);
	g_texture[BOMBERMAN] = Texture::genTexture((u8 *)bomberman_pcx);
	g_texture[EXPLOSE] = Texture::genTexture((u8 *)explose_pcx);
	g_texture[BOMBE] = Texture::genTexture((u8 *)bombe_pcx);
}