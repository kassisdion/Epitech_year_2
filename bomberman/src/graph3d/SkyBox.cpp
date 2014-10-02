#include "graph3d/SkyBox.hpp"

SkyBox::SkyBox(float sizeX, float sizeZ) 
	: _sizeX(sizeX)
	, _sizeZ(sizeZ){}

SkyBox::~SkyBox(){}

void 		SkyBox::draw(){
	_cube.draw(-5, 0, 5, _sizeX + 10.0, 10.0f, _sizeZ + 10.0, FLOOR, FLOOR, BACKWALL);
}