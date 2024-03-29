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
#include "Model.hpp"

#include <iostream>
#include <fstream>
#include <tga.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "tolua++.h"
#include "../ShaderProgram.hpp"
#include "../Game.hpp"
#include "../Camera.hpp"
#include "LightSource.hpp"

bool Model::loadFromFile(const char* fileName, GLuint mode /* = GLM_SMOOTH */, 
						 bool unitize /* = true */, bool force /* = false */)
{
	std::cout << "Loading model from file: " << fileName << " ... ";

	if (_model == NULL || force){
		std::ifstream fin(fileName);
		if (!fin) {
			std::cerr << "The file path [" << fileName << "] does not exist!\n";
			return false;
		}

		_model = boost::shared_ptr<GLMmodel>( glmReadOBJ( const_cast<char*>( fileName ) ) );

		if (_model == NULL) return false;

		if (unitize){
			glmUnitize( _model.get() );
		}

		glmFacetNormals( _model.get() );
		glmVertexNormals( _model.get(), 90.0, GL_TRUE );

		// create a display list
		_modelDrawList = glmList(_model.get(), mode );
	}

	std::cout << "done\n";

	_drawMode = mode;
	_type = FILE;

	return true;
}

void Model::loadTexture(const char *fileName)
{
	std::cout << "Loading texture from file: " << fileName << " ... ";
	loadTGA(fileName, _texture);
	_textureLoaded = true;

	std::cout << "done\n";
}

void Model::draw( bool shadow /*= false */  )
{
	if ( shader != NULL && shader->isValid() && !shadow ) {
		Camera const * camera = parent->getCamera();
		std::list<LightSourcePtr> lights = parent->getLights();

		shader->use();
		shader->setUniform( "u_PMatrix", camera->getProjectionMatrix() );
		shader->setUniform( "u_VMatrix", camera->getViewMatrix() );
		shader->setUniform( "u_MMatrix", getModelMatrix() );
		shader->setUniform( "u_LightsCount", lights.size() );

		foreach( LightSourcePtr light, lights ) {
			light->sendToShaderProgram( *shader, *camera );
		}
	}

	glPushMatrix();
	GLfloat prevColor[4]; 
	glGetFloatv( GL_CURRENT_COLOR, prevColor );

	nv::vec4f color = _color;
	if ( shadow ) {
		color = nv::vec4f( 0, 0, 0, 1 );
	}

	if (_textureLoaded) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _texture);
	}

	glTranslatef( translationPostRotation.x, translationPostRotation.y, translationPostRotation.z );

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glTranslatef(translation.x, translation.y, translation.z);

	glScalef( scale.x, scale.y, scale.z );

	if ( shader != NULL ) {
		shader->setUniform( "u_UseTexture", (int)_textureLoaded | (_drawMode & GLM_TEXTURE ) );
	}

	switch( _type ) {
	case NONE:
		std::cerr << "WARN! Drawing a none model... \n";
		break;
	case FILE:
		if (_model != NULL){
			if ( shadow ) glColor3f( 0, 0, 0 );
			glCallList( _modelDrawList );
		}
		break;
	case SPHERE:
		glColor4fv( color._array );
		glutSolidSphere( _sphereRadius, _sphereSlices, _sphereStacks );
		break;
	case CUBE:
		glColor4fv( color._array );
		glutSolidCube( _size );
		break;
	case TEAPOT:
		glColor4fv( color._array );
		glutSolidTeapot( _size );
		break;
	case PLANE:
		glColor4fv( color._array );
		glBegin( GL_QUADS );
			glNormal3f(0,1,0);
			glVertex3f( _planeWidth, 0, -_planeLength );
			glVertex3f(-_planeWidth, 0, -_planeLength );
			glVertex3f(-_planeWidth, 0,  _planeLength );
			glVertex3f( _planeWidth, 0,  _planeLength );
		glEnd();
		break;
	}

	if (_textureLoaded) {
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}

	// restore color
	glColor4fv( prevColor );
	glPopMatrix();

	if ( shader != NULL )
		shader->unUse();
}

Model::~Model()
{
}

Model::Model( Game* parent ) :
GameComponent( parent ),
_drawMode( GLM_NONE ),
_type( NONE ),
_textureLoaded( false )
{
	glGenTextures(1, &_texture);
}

void Model::loadScript(std::string path)
{
	GameComponent::loadScript( path );
	if ( script == NULL )
	script = boost::shared_ptr<LuaScript>(new LuaScript);

	tolua_pushusertype(*script, (void*)this, "Model");
	lua_setglobal(*script, "CurrentModel");

	script->executeScript(path);
}

void Model::loadSphere( double radius, int slices, int stacks, nv::vec4f color )
{
	_type = SPHERE;
	_sphereRadius = radius;
	_sphereSlices = slices;
	_sphereStacks = stacks;
	_color = color;
}

void Model::loadPlane( float width, float length, nv::vec4f color )
{
	_type = PLANE;
	_planeLength = length;
	_planeWidth = width;
	_color = color;
}

void Model::loadCube( double size, nv::vec4f color )
{
	_type = CUBE;
	_size = size;
	_color = color;
}

void Model::loadTeapot( double size, nv::vec4f color )
{
	_type = TEAPOT;
	_size = size;
	_color = color;
}

void Model::getPlanePoints( nv::vec4f& p1, nv::vec4f& p2, nv::vec4f& p3 )
{
	nv::vec4f tmp1( _planeWidth, 0, -_planeLength, 1.0f );
	nv::vec4f tmp2( -_planeWidth, 0, -_planeLength, 1.0f );
	nv::vec4f tmp3( -_planeWidth, 0,  _planeLength, 1.0f );

	nv::matrix4f model = getModelMatrix();
	p1 = model * tmp1;
	p2 = model * tmp2;
	p3 = model * tmp3;
}