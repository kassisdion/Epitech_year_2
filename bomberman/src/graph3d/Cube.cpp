#include "graph3d/Cube.hpp"

Cube::Cube(){}

Cube::~Cube(){}

void 		Cube::draw(float posX, float posY,
						float posZ, float sizeX,
						float sizeY, float sizeZ,
						int textureUp, int textureDown, int textureFace){
	if (textureFace >= 0 && textureDown >= 0 && textureUp >= 0){
		glPushMatrix();
		glTranslatef(posX, posY, posZ);
			glScalef(sizeX, sizeY, sizeZ);
			glBegin(GL_QUADS);
			glBindTexture(GL_TEXTURE_2D, g_texture[textureFace]);
			//front face
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
			//back face
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, -1.0f);
			//left face
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
			//right face
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);		
			glBindTexture(GL_TEXTURE_2D, g_texture[textureUp]);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, -1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
			glBindTexture(GL_TEXTURE_2D, g_texture[textureDown]);		
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.0f, -1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, -1.0f);
		glEnd();
		glPopMatrix(1);
	}
}