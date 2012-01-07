#include "Model.hpp"

#include <iostream>
#include <fstream>
#include <tga.h>
#include <boost/shared_ptr.hpp>

#include "tolua++.h"
#include "../ShaderProgram.hpp"

bool Model::loadFromFile(const char* fileName, GLuint mode /* = GLM_SMOOTH */, 
						 bool unitize /* = true */, bool force /* = false */)
{
	cleanupCurrentModel();
	std::cout << "Loading model from file: " << fileName << " ... ";

	if (_model == NULL || force){
		std::ifstream fin(fileName);
		if (!fin) {
			std::cerr << "The file path [" << fileName << "] does not exist!\n";
			return false;
		}

		_model = glmReadOBJ(const_cast<char*>(fileName));

		if (_model == NULL) return false;

		if (unitize){
			glmUnitize(_model);
		}

		glmFacetNormals(_model);
		glmVertexNormals(_model, 90.0, GL_TRUE);
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

void Model::cleanupCurrentModel()
{
	if (_model != NULL) {
		glmDelete(_model);
		_model = NULL;
	}
}

void Model::draw( Camera& cam )
{
	glPushMatrix();
	GLfloat prevColor[4]; 
	glGetFloatv( GL_CURRENT_COLOR, prevColor );

	if (_textureLoaded) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _texture);
	}

	glTranslatef( translationPostRotation.x, translationPostRotation.y, translationPostRotation.z );

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glTranslatef(translation.x, translation.y, translation.z);

	if ( shader != NULL ) {
		shader->setUniform( "u_UseTexture", (int)_textureLoaded | (_drawMode & GLM_TEXTURE ) );
	}

	switch( _type ) {
	case NONE:
		std::cerr << "WARN! Drawing a none model... \n";
		break;
	case FILE:
		if (_model != NULL){
			glmDraw(_model, _drawMode);
		}
		break;
	case SPHERE:
		glColor4fv( _color._array );
		glutSolidSphere( _sphereRadius, _sphereSlices, _sphereStacks );
		break;
	case CUBE:
		glColor4fv( _color._array );
		glutSolidCube( _size );
		break;
	case TEAPOT:
		glColor4fv( _color._array );
		glutSolidTeapot( _size );
		break;
	case PLANE:
		glColor4fv( _color._array );
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
}

Model::~Model()
{
	cleanupCurrentModel();
}

Model::Model() :
_model( NULL ),
_drawMode( GLM_NONE ),
_type( NONE ),
_textureLoaded( false )
{
	glGenTextures(1, &_texture);
}

void Model::loadScript(std::string path)
{
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