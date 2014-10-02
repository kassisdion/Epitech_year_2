#include "graph3d/PlayerRender.hpp"

PlayerRender::PlayerRender(const Game &game)
	: _game(game){
}

PlayerRender::~PlayerRender(){}

void 			PlayerRender::drawAll(){
  int i = 0;
  for (Player *player: _game.players){
    draw(player->getPos().x(), player->getPos().y(), player->orientation, player->color.color);
  }
}

void			PlayerRender::draw(int posX, int posY, Player::Orientation ori, int color){
  switch (ori){
  case (Player::Orientation::SOUTH) :
    _sprite3D.draw((u32 *)Bomberman_bin, posX, 0.0f, -(posY + 1), 0.1f, 0.2f, 0.1f, 0.0f, 0.0f, 0.0f, BOMBERMAN, color);
    break;
  case (Player::Orientation::NORTH) :
    _sprite3D.draw((u32 *)Bomberman_bin, posX + 1, 0.0f, -(posY), 0.1f, 0.2f, 0.1f, 0.0f, 180.0f, 0.0f, BOMBERMAN, color);
    break;
  case (Player::Orientation::EAST) :
    _sprite3D.draw((u32 *)Bomberman_bin, posX + 1, 0.0f, -(posY + 1), 0.1f, 0.2f, 0.1f, 0.0f, -90.0f, 0.0f, BOMBERMAN, color);
    break;
  case (Player::Orientation::WEST) :
    _sprite3D.draw((u32 *)Bomberman_bin, posX, 0.0f, -(posY), 0.1f, 0.2f, 0.1f, 0.0f, 90.0f, 0.0f, BOMBERMAN, color);
    break;
  }
}
