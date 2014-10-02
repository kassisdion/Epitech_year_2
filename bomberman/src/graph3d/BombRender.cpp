#include "graph3d/MapRender.hpp"
#include "graph3d/BombRender.hpp"

BombRender::BombRender(const Game &g)
	: _game(g){
}

BombRender::~BombRender(){}

void 		BombRender::drawAll()
{
  for (Bomb *bomb: _game.bombs)
    {
      draw(bomb->pos.x(), bomb->pos.y() + 1,
	   bomb->state, bomb->up_explosion, bomb->down_explosion,
	   bomb->left_explosion, bomb->right_explosion);
    }
}

void 		BombRender::draw(float x, float y, Bomb::State explose, char up,
				 char down, char left, char right)
{
  unsigned int playerX = _game.getPlayer().getPos().x();
  unsigned int playerY = _game.getPlayer().getPos().y();

  if ((((int)x < playerX + CUBE_VIEW_X) && ((int)x > (int)playerX - CUBE_VIEW_X))
      && (((int)y < playerY + CUBE_VIEW_Y_UP) && ((int)y > (int)playerY - CUBE_VIEW_Y_DOWN)))
    {
      if (explose == Bomb::State::PRE_EXPLODE)
	_sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -y, 0.15f, 0.15f, 0.15f, 0.0f, 0.0f, 0.0f, BOMBE);
      else if (explose == Bomb::State::STANDING)
	{
	  _sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -y, 0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, BOMBE);
	  return;
	}
      _sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -y, 0.15f, 0.15f, 0.15f, 0.0f, 0.0f, 0.0f, EXPLOSE);
      for (float i = x - left; i < x + right; i += 1.0f)
	_sprite3D.draw((u32 *)Bomb_bin, i, 0.0f, -(y + 0.2), 0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, EXPLOSE);
      for (float i = y - down; i < y + up; i += 1.0f)
	_sprite3D.draw((u32 *)Bomb_bin, x, 0.0f, -(i + 0.2), 0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, EXPLOSE);
    }
}
