#ifndef MIRAGE_SHADER_HPP__
#define MIRAGE_SHADER_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include <list>

class ShaderProgram{
public:
	ShaderProgram();
	~ShaderProgram();
	
	bool attachNewShader( GLenum shaderType, const char* filename );
	bool linkAndValidateProgram();

	GLuint getProgramId () const { return _programId; }
	void setActiveProgram();

private:
	std::list<GLuint> _shaders;
	GLuint _programId;
};

#endif // MIRAGE_SHADER_HPP__