#include "WorldType/MarioWorld.hpp"

MarioWorld::MarioWorld(){}

MarioWorld::~MarioWorld(){}

void 		MarioWorld::load(){
	g_texture[WALL] = Texture::genTexture((u8 *)mariowall_pcx);
	g_texture[FLOOR] = Texture::genTexture((u8 *)mariofloor_pcx);
	g_texture[EXTREMWALL] = Texture::genTexture((u8 *)marioewall_pcx);
	g_texture[BACKWALL] = Texture::genTexture((u8 *)mariofont_pcx);
	g_texture[BOMBERMAN] = Texture::genTexture((u8 *)bomberman_pcx);
	g_texture[EXPLOSE] = Texture::genTexture((u8 *)explose_pcx);
	g_texture[BOMBE] = Texture::genTexture((u8 *)bombe_pcx);
}