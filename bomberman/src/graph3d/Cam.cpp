#include "graph3d/Cam.hpp"

Cam::Cam(float posX, float posZ, float up)
	: _lookUpDown(50.0f)
	, _yRot(0.0f)
	, _xPos(posX)
	, _zPos(posZ) 
	, _walkBiasAngle(0.0f)
	, _walkBias(0.0)
	, _up(up){}

Cam::~Cam(){}

/*
// private methode
*/

float 		Cam::sin(float angle)
{
	int32 s = sinLerp((short)(angle * DEGREES_IN_CIRCLE / 360));
	return f32tofloat(s);
}

float 		Cam::cos(float angle)
{
	int32 c = cosLerp((short)(angle * DEGREES_IN_CIRCLE / 360));
	return f32tofloat(c);
}

/*
// public methode
*/

float 		Cam::getLook() const {
	return _lookUpDown;
}

float 		Cam::getYRot() const {
	return _yRot;
}

float 		Cam::getXPos() const {
	return _xPos;
}

float 		Cam::getZPos() const {
	return _zPos;
}

void 		Cam::lookAt(){
	glLoadIdentity();
	//glLight(10.0, RGB15(35, 35, 35) , -_xPos, floattov10(-_walkBias - 2.0f), -_zPos);
	glRotatef(_lookUpDown, 1.0f, 0, 0);
	glRotatef((360.0 - _yRot), 0, 1.0f, 0);
	glTranslatef(-_xPos, (-_walkBias - _up), -_zPos);
}

void 		Cam::lookUpDown(float val){
	_lookUpDown += val;
}

void 		Cam::rotate(float val){
	_heading += val;
	_yRot = _heading;
}

void 		Cam::move(float valX, float valZ){
	_xPos = valX;
	_zPos = -valZ + 4;
}

void 		Cam::moveDown(float valX, float valZ, float angle){

	_xPos += (float)sin(_heading) * valX;
	_zPos += (float)cos(_heading) * valZ;
	if (_walkBiasAngle >= 359.0f)
		_walkBiasAngle = 0.0f;
	else
		_walkBiasAngle += angle;
	_walkBias = (float)sin(_walkBiasAngle) / 20.0f;
}

void 		Cam::moveUp(float valX, float valZ, float angle){

	_xPos -= (float)sin(_heading) * valX;
	_zPos -= (float)cos(_heading) * valZ;
	if (_walkBiasAngle <= 1.0f)
		_walkBiasAngle = 359.0f;
	else
		_walkBiasAngle -= angle;
	_walkBias = (float)sin(_walkBiasAngle) / 20.0f;
}

void 		Cam::setCam(float valX, float valZ, float valUp){
	_xPos = valX;
	_zPos = valZ;
	_up = valUp;
}

