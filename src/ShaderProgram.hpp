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
#ifndef MIRAGE_SHADER_HPP__
#define MIRAGE_SHADER_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "nvVector.h"
#include "nvMath.h"

#include <list>

#include "Utils.hpp"

class ShaderProgram{
public:
	ShaderProgram();
	~ShaderProgram();

	void detachAllShaders();
	bool attachNewShader( GLenum shaderType, const char* filename );
	bool linkAndValidateProgram();

	GLuint getProgramId () const { return _programId; }
	bool isValid() const { return _valid; }

	void use();
	void unUse();
	void setUniform( const char* name, const nv::vec4f& value );
	void setUniform( const char* name, const nv::vec3f& value );
	void setUniform( const char* name, const nv::matrix4f& value );
	void setUniform( const char* name, int value );

private:
	DISALLOW_COPY_AND_ASSIGN(ShaderProgram);
	GLint getUniformLocation( const char* name );
	std::list<GLuint> _shaders;
	GLuint _programId;
	bool _valid;

	GLint _prevProgramId;
};

#endif // MIRAGE_SHADER_HPP__