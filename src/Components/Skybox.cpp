#include "Skybox.hpp"

#include <tga.h>

static const int FRONT = 0, BACK = 1, LEFT = 2, RIGHT = 3, UP = 4, DOWN = 5;

Skybox::Skybox(float width, float height, float thickness) :
	_width(width),
	_height(height),
	_thickness(thickness)
{
	glGenTextures(6, _textures);
}

void Skybox::loadTextures(std::string texturePrefix)
{
	loadTGA((texturePrefix + "_left.tga").c_str(), _textures[LEFT]);	
	loadTGA((texturePrefix + "_down.tga").c_str(), _textures[DOWN]);	
	loadTGA((texturePrefix + "_front.tga").c_str(), _textures[FRONT]);	
	loadTGA((texturePrefix + "_right.tga").c_str(), _textures[RIGHT]);	
	loadTGA((texturePrefix + "_up.tga").c_str(), _textures[UP]);	
	loadTGA((texturePrefix + "_back.tga").c_str(), _textures[BACK]);	
}

void Skybox::draw()
{
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, _textures[LEFT]);
	glBegin(GL_QUADS);
		glNormal3f(1,0,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-_width+0.1f, _height, -_thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width+0.1f, _height, _thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width+0.1f, -_height, _thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-_width+0.1f, -_height, -_thickness);
	glEnd();

	//negative y plane
	glBindTexture(GL_TEXTURE_2D, _textures[DOWN]);
	glBegin(GL_QUADS);
		glNormal3f(0,1,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width, -_height, -_thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width, -_height, -_thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width, -_height, _thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width, -_height, _thickness);
		glEnd();

	//negative z plane
	glBindTexture(GL_TEXTURE_2D, _textures[BACK]);
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-_width, _height, _thickness -0.1f);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(_width, _height, _thickness -0.1f);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(_width, -_height, _thickness -0.1f);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-_width, -_height, _thickness -0.1f);
	glEnd();

	//positive x plane
	glBindTexture(GL_TEXTURE_2D, _textures[RIGHT]);
	glBegin(GL_QUADS);
		glNormal3f(-1,0,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width-0.1f, _height, _thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(_width-0.1f, _height, -_thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(_width-0.1f, -_height, -_thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width-0.1f, -_height, _thickness);
	glEnd();

	//positive y plane
	glBindTexture(GL_TEXTURE_2D, _textures[UP]);
	glBegin(GL_QUADS);
		glNormal3f(0,-1,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width, _height, _thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width, _height, _thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width, _height, -_thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width, _height, -_thickness);
	glEnd();

	//positive z plane
	glBindTexture(GL_TEXTURE_2D, _textures[FRONT]);
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width, _height, -_thickness+0.1f);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width, _height, -_thickness+0.1f);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width, -_height, -_thickness+0.1f);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width, -_height, -_thickness+0.1f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopAttrib();
}