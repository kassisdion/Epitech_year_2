#include "WorldType/WorldType.hpp"

WorldType::WorldType()
{}

void 		WorldType::unload(){
	glDeleteTextures(1, &g_texture[WALL]);
	glDeleteTextures(1, &g_texture[FLOOR]);
	glDeleteTextures(1, &g_texture[EXTREMWALL]);
	glDeleteTextures(1, &g_texture[BACKWALL]);
	glDeleteTextures(1, &g_texture[BOMBE]);
	glDeleteTextures(1, &g_texture[EXPLOSE]);
	glDeleteTextures(1, &g_texture[BOMBERMAN]);
}