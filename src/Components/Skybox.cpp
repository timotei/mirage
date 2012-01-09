/*
   Copyright (C) 2011-2012 by Timotei Dolean <timotei21@gmail.com>

   Part of the Mirage Project https://github.com/timotei/mirage

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
#include "Skybox.hpp"

#include <tga.h>

#include "Camera.hpp"
#include "../Game.hpp"

static const int FRONT = 0, BACK = 1, LEFT = 2, RIGHT = 3, UP = 4, DOWN = 5;

Skybox::Skybox( Game* parent, float width, float height, float thickness ) :
GameComponent( parent ),
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

void Skybox::draw( bool )
{
	glPushAttrib(GL_ENABLE_BIT);
	glPushMatrix();

	glDisable( GL_LIGHTING );
	glDisable( GL_DEPTH_TEST );
	glDisable( GL_BLEND );
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();

	glRotatef( parent->getCamera()->rotation.x, 1, 0, 0 );
	glRotatef( parent->getCamera()->rotation.y, 0, 1, 0 );
	glRotatef( parent->getCamera()->rotation.z, 0, 0, 1 );

	glBindTexture(GL_TEXTURE_2D, _textures[LEFT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
		glNormal3f(1,0,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-_width+0.1f, _height, -_thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width+0.1f, _height, _thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width+0.1f, -_height, _thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-_width+0.1f, -_height, -_thickness);
	glEnd();

	//negative y plane
	glBindTexture(GL_TEXTURE_2D, _textures[DOWN]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
		glNormal3f(0,1,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width, -_height, -_thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width, -_height, -_thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width, -_height, _thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width, -_height, _thickness);
	glEnd();

	//negative z plane
	glBindTexture(GL_TEXTURE_2D, _textures[BACK]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-_width, _height, _thickness -0.1f);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(_width, _height, _thickness -0.1f);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(_width, -_height, _thickness -0.1f);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-_width, -_height, _thickness -0.1f);
	glEnd();

	//positive x plane
	glBindTexture(GL_TEXTURE_2D, _textures[RIGHT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
		glNormal3f(-1,0,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width-0.1f, _height, _thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(_width-0.1f, _height, -_thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(_width-0.1f, -_height, -_thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width-0.1f, -_height, _thickness);
	glEnd();

	//positive y plane
	glBindTexture(GL_TEXTURE_2D, _textures[UP]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
		glNormal3f(0,-1,0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(_width, _height, _thickness);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(-_width, _height, _thickness);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(-_width, _height, -_thickness);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(_width, _height, -_thickness);
	glEnd();

	//positive z plane
	glBindTexture(GL_TEXTURE_2D, _textures[FRONT]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
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