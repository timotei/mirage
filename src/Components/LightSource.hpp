#ifndef MIRAGE_LIGHTSOURCE_HPP__
#define MIRAGE_LIGHTSOURCE_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "nvMath.h"

#include "GameComponent.hpp"
#include "../Utils.hpp"

class Camera;

class LightSource :	public GameComponent
{
public:
	LightSource();
	~LightSource();

	void update() { GameComponent::update(); }
	void draw();
	void sendToShaderProgram( ShaderProgram& program, Camera& cam );

	nv::vec4f color;

private:
	int _index;

	DISALLOW_COPY_AND_ASSIGN(LightSource);
};

#endif // MIRAGE_LIGHTSOURCE_HPP__