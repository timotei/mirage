#ifndef MIRAGE_MODEL_HPP__
#define MIRAGE_MODEL_HPP__

#include "glm.h"

#include "GameComponent.hpp"
#include "../Utils.hpp"


class Model : public GameComponent{
public:
	enum ModelType {
		NONE = 0,
		SPHERE = 1,
		FILE = 2,
		PLANE = 4
	};

	void update() { GameComponent::update(); }
	void draw();

	bool loadFromFile(const char* fileName, GLuint mode = GLM_NONE, bool unitize = true, bool force = false);
	void loadTexture(const char* fileName);
	void loadScript(std::string path);
	void loadSphere( GLdouble radius, GLint slices, GLint stacks, nv::vec4f color );
	void loadPlane( float width, float length, nv::vec4f color );

	Model();
	~Model();
private:
	GLMmodel* _model;
	GLuint _drawMode;
	GLuint _texture;

	bool _textureLoaded;

	ModelType _type;

	GLdouble _sphereRadius;
	GLint _sphereSlices;
	GLint _sphereStacks;
	nv::vec4f _sphereColor;
	
	nv::vec4f _planeColor;
	float _planeLength;
	float _planeWidth;

	void cleanupCurrentModel();
	DISALLOW_COPY_AND_ASSIGN(Model);
};

#endif // MIRAGE_MODEL_HPP__
