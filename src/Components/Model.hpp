#ifndef MIRAGE_MODEL_HPP__
#define MIRAGE_MODEL_HPP__

#include "glm.h"

#include "GameComponent.hpp"
#include "../Utils.hpp"

class Model : public GameComponent{
public:
	void update() {}
	void draw();

	bool loadFromFile(const char* fileName, GLuint mode = GLM_SMOOTH, bool unitize = true, bool force = false);
	void loadTexture(const char* fileName);
	void loadScript(std::string path);

	Model();
	~Model();
private:
	GLMmodel* _model;
	GLuint _drawMode;
	GLuint _texture;

	bool _textureLoaded;

	void cleanupCurrentModel();
	DISALLOW_COPY_AND_ASSIGN(Model);
};

#endif // MIRAGE_MODEL_HPP__
