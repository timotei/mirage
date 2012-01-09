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
#ifndef MIRAGE_SKYBOX_HPP__
#define MIRAGE_SKYBOX_HPP__

#include <string>

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "GameComponent.hpp"

class Skybox : public GameComponent{
public:
	Skybox( Game* parent, float width, float height, float thickness );
	void draw( bool = false );
	void loadTextures( std::string texturePrefix );

private:
	float _height, _width, _thickness;
	GLuint _textures[6];
};

#endif // MIRAGE_SKYBOX_HPP__
