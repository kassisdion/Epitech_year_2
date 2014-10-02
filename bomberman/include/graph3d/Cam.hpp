#ifndef __CAM_H__
#define __CAM_H__

#include <nds.h>


class Cam {
private:
	float 		_lookUpDown;
	float 		_heading;
	float 		_yRot;
	float 		_xPos;
	float 		_zPos;
	float 		_walkBiasAngle;
	float 		_walkBias;
	float 		_up;

	float 		sin(float angle);
	float 		cos(float angle);
	
public:
	Cam(float posX, float posZ, float up);
	~Cam();

	void 		lookAt();
	void 		lookUpDown(float val);
	void 		rotate(float val);
	void 		moveDown(float valX, float valZ, float angle);
	void 		moveUp(float valX, float valZ, float angle);
	void 		move(float valX, float valZ);
	void 		setCam(float valX, float valZ, float valUp);
	
	float 		getLook() const;
	float 		getYRot() const;
	float 		getXPos() const;
	float 		getZPos() const;	
};

#endif