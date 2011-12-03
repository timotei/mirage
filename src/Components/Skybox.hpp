#ifndef MIRAGE_SKYBOX_HPP__
#define MIRAGE_SKYBOX_HPP__

#include <string>

#include "GL/freeglut.h"
#include "GameComponent.hpp"

class Skybox : public GameComponent{
public:
	Skybox(int width, int height, int thickness);
	void draw();

	void loadTextures(std::string texturePrefix);

private:
	int _height, _width, _thickness;
	GLuint _textures[6];
};

#endif // MIRAGE_SKYBOX_HPP__
