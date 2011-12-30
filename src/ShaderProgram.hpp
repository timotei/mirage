#ifndef MIRAGE_SHADER_HPP__
#define MIRAGE_SHADER_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "nvVector.h"
#include "nvMath.h"

#include <list>

class ShaderProgram{
public:
	ShaderProgram();
	~ShaderProgram();
	
	bool attachNewShader( GLenum shaderType, const char* filename );
	bool linkAndValidateProgram();

	GLuint getProgramId () const { return _programId; }
	bool isValid() const { return _valid; }

	void use();
	void unUse();
	void setUniform( const char* name, const nv::vec4f& value );
	void setUniform( const char* name, const nv::vec3f& value );

private:
	GLint getUniformLocation( const char* name );
	std::list<GLuint> _shaders;
	GLuint _programId;
	bool _valid;

	GLint _prevProgramId;
};

#endif // MIRAGE_SHADER_HPP__