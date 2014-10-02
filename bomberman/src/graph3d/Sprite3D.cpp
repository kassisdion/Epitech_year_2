#include "graph3d/Sprite3D.hpp"
#include "core/debug.hpp"

Sprite3D::Sprite3D(){}

Sprite3D::~Sprite3D(){}

void 		Sprite3D::draw(u32 * quadric_bin, float posX, float posY, float posZ,
										float sizeX, float sizeY, float sizeZ,
										float rotX, float rotY, float rotZ, int texture, char argb[4]){
	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);
		glColor3f(argb[0], argb[1], argb[2]);
		glBindTexture(GL_TEXTURE_2D, g_texture[texture]);
		glScalef(sizeX, sizeY, sizeZ);
		glCallList((u32*)quadric_bin);
	glPopMatrix(1);
	glColor3f(1.0f, 1.0f, 1.0f);
}

void 		Sprite3D::draw(u32 * quadric_bin, float posX, float posY, float posZ,
										float sizeX, float sizeY, float sizeZ,
										float rotX, float rotY, float rotZ, int texture, int clr){
	union Color color;

	color.color = clr;
	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);
		glColor3f(color.argb[1] / 255, color.argb[2] / 255, color.argb[3] / 255);
		glBindTexture(GL_TEXTURE_2D, g_texture[texture]);
		glScalef(sizeX, sizeY, sizeZ);
		glCallList((u32*)quadric_bin);
	glPopMatrix(1);
	glColor3f(1.0f, 1.0f, 1.0f);
}

void 		Sprite3D::draw(u32 * quadric_bin, float posX, float posY, float posZ,
										float sizeX, float sizeY, float sizeZ,
										float rotX, float rotY, float rotZ, int texture){
	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);
		glScalef(sizeX, sizeY, sizeZ);
		glBindTexture(GL_TEXTURE_2D, g_texture[texture]);
		glCallList((u32*)quadric_bin);
	glPopMatrix(1);
	glColor3f(1.0f, 1.0f, 1.0f);
}

