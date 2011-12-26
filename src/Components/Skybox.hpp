#ifndef MIRAGE_SKYBOX_HPP__
#define MIRAGE_SKYBOX_HPP__

#include <string>

#ifdef __WIN32
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "GameComponent.hpp"

class Skybox : public GameComponent{
public:
	Skybox(float width, float height, float thickness);
	void draw();

	void loadTextures(std::string texturePrefix);

private:
	float _height, _width, _thickness;
	GLuint _textures[6];
};

#endif // MIRAGE_SKYBOX_HPP__
