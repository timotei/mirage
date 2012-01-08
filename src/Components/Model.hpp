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
		PLANE = 4,
		CUBE = 8,
		TEAPOT = 16
	};

	void update() 
	{ 
		GameComponent::update(); 
	}
	void draw( Camera& cam, bool shadow = false );

	bool loadFromFile(const char* fileName, GLuint mode = GLM_NONE, bool unitize = true, bool force = false);
	void loadTexture(const char* fileName);
	void loadScript(std::string path);
	void loadSphere( double radius, int slices, int stacks, nv::vec4f color );
	void loadPlane( float width, float length, nv::vec4f color );
	void loadCube( double size, nv::vec4f color );
	void loadTeapot( double size, nv::vec4f color );
	void getPlanePoints( nv::vec4f& p1, nv::vec4f& p2, nv::vec4f& p3 );

	Model();
	~Model();
private:
	GLMmodel* _model;
	GLuint _drawMode;
	GLuint _texture;

	bool _textureLoaded;

	ModelType _type;
	nv::vec4f _color;

	double _sphereRadius;
	int _sphereSlices;
	int _sphereStacks;
	
	float _planeLength;
	float _planeWidth;

	bool _size;

	void cleanupCurrentModel();
	DISALLOW_COPY_AND_ASSIGN(Model);
};

#endif // MIRAGE_MODEL_HPP__
