#include "graph3d/MapRender.hpp"

MapRender::MapRender(const Game &game)
  : _game(game)
{
}

MapRender::~MapRender()
{
}

void 		MapRender::drawWall()
{
  int 		sizeX = _game.map->getSize().x();
  int 		sizeZ = _game.map->getSize().y();

  _cube.draw(0.0f, 0.0f, - sizeZ, sizeX + 1, 1.0f, 1.0f, EXTREMWALL, EXTREMWALL, EXTREMWALL);//haut
  _cube.draw(0.0f, 0.0f, + 1.0f, sizeX + 1, 1.0f, 1.0f, EXTREMWALL, EXTREMWALL, EXTREMWALL);//bas
  _cube.draw(-1.0f, 0.0f, 0.0f, 1.0f, 1.0f, sizeZ + 1, EXTREMWALL, EXTREMWALL, EXTREMWALL);//gauche
  _cube.draw(sizeX , 0.0f, 0.0f, 1.0f, 1.0f, sizeZ + 1, EXTREMWALL, EXTREMWALL, EXTREMWALL);//droite
}

void 		MapRender::drawMap()
{
  unsigned int playerX = _game.getPlayer().getPos().x();
  unsigned int playerY = _game.getPlayer().getPos().y();

  for (int x = 0; x < _game.map->getSize().x(); x++)
    {
      for (int z = 0; z < _game.map->getSize().y(); z++)
	{
	  if (((x < playerX + CUBE_VIEW_X) && ((int)x > (int)playerX - CUBE_VIEW_X))
	      && ((z < playerY + CUBE_VIEW_Y_UP) && ((int)z > (int)playerY - CUBE_VIEW_Y_DOWN)))
	    {
	      Map::Tile tile = _game.map->at(x, z);
	      switch (tile)
		{
		case (Map::Tile::IWALL) :
		  _cube.draw(x, 0, -z, 1, 1, 1, EXTREMWALL, EXTREMWALL, EXTREMWALL);
		  break;
		case (Map::Tile::DWALL) :
		  _cube.draw(x, 0, -z, 1, 1, 1, WALL, WALL, WALL);
		  break;
		case (Map::Tile::LIFE) :
		  _sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -(z + 1), 0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, BOMBE, 0xff2a2a2a);
		  break;
		case (Map::Tile::BOMB) :
		  _sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -(z + 1), 0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, BOMBE, 0xff42007b);
		  break;
		case (Map::Tile::RANGE) :
		  _sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -(z + 1), 0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, BOMBE, 0xff7b0000);
		  break;
		}
	    }
	}
    }
}
