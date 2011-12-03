#include "Skybox.hpp"

#include <GL/freeglut.h>
#include <tga/tga.h>

static const int FRONT = 0, BACK = 1, LEFT = 2, RIGHT = 3, UP = 4, DOWN = 5;

Skybox::Skybox(int width, int height, int thickness) :
	_width(width),
	_height(height),
	_thickness(thickness)
{
	glGenTextures(6, _textures);
}

void Skybox::loadTextures(std::string texturePrefix)
{
	loadTGA(const_cast<char*>((texturePrefix + "_left.tga").c_str()), _textures[LEFT]);	
	loadTGA(const_cast<char*>((texturePrefix + "_down.tga").c_str()), _textures[DOWN]);	
	loadTGA(const_cast<char*>((texturePrefix + "_front.tga").c_str()), _textures[FRONT]);	
	loadTGA(const_cast<char*>((texturePrefix + "_right.tga").c_str()), _textures[RIGHT]);	
	loadTGA(const_cast<char*>((texturePrefix + "_up.tga").c_str()), _textures[UP]);	
	loadTGA(const_cast<char*>((texturePrefix + "_back.tga").c_str()), _textures[BACK]);	
}

void Skybox::draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, _textures[LEFT]);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);glVertex3f(-_width+0.1, _height, -_thickness);
		glTexCoord2f(0, 1);glVertex3f(-_width+0.1, _height, _thickness);
		glTexCoord2f(0, 0);glVertex3f(-_width+0.1, -_height, _thickness);
		glTexCoord2f(1, 0);glVertex3f(-_width+0.1, -_height, -_thickness);
	glEnd();

	//negative y plane
	glBindTexture(GL_TEXTURE_2D, _textures[DOWN]);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);glVertex3f(_width, -_height, -_thickness);
		glTexCoord2f(0, 1);glVertex3f(-_width, -_height, -_thickness);
		glTexCoord2f(0, 0);glVertex3f(-_width, -_height, _thickness);
		glTexCoord2f(1, 0);glVertex3f(_width, -_height, _thickness);
		glEnd();

	//negative z plane
	glBindTexture(GL_TEXTURE_2D, _textures[BACK]);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);glVertex3f(-_width, _height, _thickness -0.1);
		glTexCoord2f(0, 1);glVertex3f(_width, _height, _thickness -0.1);
		glTexCoord2f(0, 0);glVertex3f(_width, -_height, _thickness -0.1);
		glTexCoord2f(1, 0);glVertex3f(-_width, -_height, _thickness -0.1);
	glEnd();

	//positive x plane
	glBindTexture(GL_TEXTURE_2D, _textures[RIGHT]);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);glVertex3f(_width-0.1, _height, _thickness);
		glTexCoord2f(0, 1);glVertex3f(_width-0.1, _height, -_thickness);
		glTexCoord2f(0, 0);glVertex3f(_width-0.1, -_height, -_thickness);
		glTexCoord2f(1, 0);glVertex3f(_width-0.1, -_height, _thickness);
	glEnd();

	//positive y plane
	glBindTexture(GL_TEXTURE_2D, _textures[UP]);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);glVertex3f(_width, _height, _thickness);
		glTexCoord2f(0, 1);glVertex3f(-_width, _height, _thickness);
		glTexCoord2f(0, 0);glVertex3f(-_width, _height, -_thickness);
		glTexCoord2f(1, 0);glVertex3f(_width, _height, -_thickness);
	glEnd();

	//positive z plane
	glBindTexture(GL_TEXTURE_2D, _textures[FRONT]);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);glVertex3f(_width, _height, -_thickness+0.1);
		glTexCoord2f(0, 1);glVertex3f(-_width, _height, -_thickness+0.1);
		glTexCoord2f(0, 0);glVertex3f(-_width, -_height, -_thickness+0.1);
		glTexCoord2f(1, 0);glVertex3f(_width, -_height, -_thickness+0.1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}