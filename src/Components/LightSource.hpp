#ifndef MIRAGE_LIGHTSOURCE_HPP__
#define MIRAGE_LIGHTSOURCE_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include "GameComponent.hpp"
#include "../Vector3.hpp"
#include "../Vector4.hpp"
#include "../Utils.hpp"

class LightSource :	public GameComponent
{
public:
	LightSource(GLenum lightNum);
	~LightSource();

	void update() {}
	void draw();

	Vector4 position;
	Vector4 diffuse;
	Vector4 ambient;
	Vector4 specular;
	Vector4 emission;
	GLfloat shininess;
private:
	GLenum _lightNum;

	DISALLOW_COPY_AND_ASSIGN(LightSource);
};

#endif // MIRAGE_LIGHTSOURCE_HPP__