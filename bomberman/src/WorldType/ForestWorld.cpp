#include "WorldType/ForestWorld.hpp"

ForestWorld::ForestWorld(){}

ForestWorld::~ForestWorld(){}

void 		ForestWorld::load(){
	g_texture[WALL] = Texture::genTexture((u8 *)treewall_pcx);
	g_texture[FLOOR] = Texture::genTexture((u8 *)treefloor_pcx);
	g_texture[EXTREMWALL] = Texture::genTexture((u8 *)treeewall_pcx);
	g_texture[BACKWALL] = Texture::genTexture((u8 *)treefont_pcx);
	g_texture[BOMBERMAN] = Texture::genTexture((u8 *)bomberman_pcx);
	g_texture[EXPLOSE] = Texture::genTexture((u8 *)explose_pcx);
	g_texture[BOMBE] = Texture::genTexture((u8 *)bombe_pcx);
}
