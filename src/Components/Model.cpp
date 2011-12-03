#include "Model.hpp"

#include <iostream>

bool Model::loadFromFile(const char* fileName, GLuint mode /* = GLM_SMOOTH */, 
						 bool unitize /* = true */, bool force /* = false */)
{
	cleanupCurrentModel();
	if (_model == NULL || force){
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

void Model::cleanupCurrentModel()
{
	if (_model != NULL) {
		_model = NULL;
	}
}

void Model::draw()
{
	if (_model != NULL)
		glmDraw(_model, _drawMode);
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

}