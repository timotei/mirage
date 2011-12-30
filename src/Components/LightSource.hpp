#ifndef MIRAGE_LIGHTSOURCE_HPP__
#define MIRAGE_LIGHTSOURCE_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "nvVector.h"
#include "nvMath.h"

#include "GameComponent.hpp"
#include "../Utils.hpp"

class LightSource :	public GameComponent
{
public:
	LightSource();
	~LightSource();

	void update() {}
	void draw();

	nv::vec4f position;
	nv::vec4f diffuse;
	nv::vec4f ambient;
	nv::vec4f specular;
	nv::vec4f emission;
	GLfloat shininess;
private:
	GLenum _lightNum;

	DISALLOW_COPY_AND_ASSIGN(LightSource);
};

#endif // MIRAGE_LIGHTSOURCE_HPP__