#include "Model.hpp"

#include <iostream>
#include <fstream>
#include <tga.h>
#include <boost/shared_ptr.hpp>

#include "tolua++.h"

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
		glmVertexNormals(_model, 90.0);
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

	glTranslatef(translation.x, translation.y, translation.z);

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glTranslatef( translationPostRotation.x, translationPostRotation.y, translationPostRotation.z );

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
		glColor4fv( _sphereColor._array );
		glutSolidSphere( _sphereRadius, _sphereSlices, _sphereStacks );
		break;
	case PLANE:
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
_type( NONE )
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

void Model::loadSphere( GLdouble radius, GLint slices, GLint stacks, nv::vec4f color )
{
	_type = SPHERE;
	_sphereRadius = radius;
	_sphereSlices = slices;
	_sphereStacks = stacks;
	_sphereColor = color;
}

void Model::loadPlane( float width, float length, nv::vec4f color )
{
	_type = PLANE;
	_planeLength = length;
	_planeWidth = width;
	_planeColor = color;
}
