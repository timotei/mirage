#include "Model.hpp"

#include <iostream>
#include <fstream>
#include <tga/tga.h>

bool Model::loadFromFile(const char* fileName, GLuint mode /* = GLM_SMOOTH */, 
						 bool unitize /* = true */, bool force /* = false */)
{
	cleanupCurrentModel();
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

	_drawMode = mode;
	return true;
}

void Model::loadTexture(char *fileName)
{
	loadTGA(fileName, _texture);
	_textureLoaded = true;
}

void Model::cleanupCurrentModel()
{
	if (_model != NULL) {
		_model = NULL;
	}
}

void Model::draw()
{
	if (_model != NULL){
		if (_textureLoaded) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _texture);
		}

		glmDraw(_model, _drawMode);

		if (_textureLoaded) {
			glDisable(GL_TEXTURE_2D);
		}
	}
	else{
		std::cerr << "Error! The model is NULL\n";
	}
}

Model::~Model()
{
	cleanupCurrentModel();
}

Model::Model() :
_model(NULL),
_drawMode(GLM_SMOOTH)
{
	glGenTextures(1, &_texture);
}