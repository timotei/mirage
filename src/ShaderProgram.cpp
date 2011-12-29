#include "ShaderProgram.hpp"

#include <sstream>
#include <iostream>
#include <fstream>
#include <boost/foreach.hpp>

#define BUFFER_SIZE 2048
#define foreach BOOST_FOREACH

ShaderProgram::ShaderProgram() :
_shaders( 0 )
{
	_programId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	foreach( GLuint shaderId, _shaders ) {
		glDetachShader( _programId, shaderId );
		glDeleteShader( shaderId );
	}

	glDeleteProgram( _programId );
}

bool ShaderProgram::attachNewShader( GLenum shaderType, const char* filename )
{
	GLuint shaderId = glCreateShader( shaderType );
	
	std::stringstream ss;
	std::ifstream reader( filename );
	if ( !reader ) {
		std::cerr << "Error! Can't finder shader file: " << filename << "\n";
		return false;
	}

	// read the file text
	char buffer[BUFFER_SIZE];
	while( ! reader.eof() ) {
		reader.getline( buffer, BUFFER_SIZE );
		ss << buffer << "\n";
	}

	std::string source = ss.str();
	const char* sourceArray[1] = { source.c_str() };

	glShaderSource( shaderId, 1, sourceArray, NULL );
	glCompileShader( shaderId );

	// check status
	GLint success;
	glGetShaderiv( shaderId, GL_COMPILE_STATUS, &success );
	if ( !success ) {
		GLchar infoLog[BUFFER_SIZE];
		glGetShaderInfoLog( shaderId, BUFFER_SIZE, NULL, infoLog );
		std::cerr << "Error compiling the shader: " << infoLog << "\n";

		glDeleteShader(shaderId);

		return false;
	}

	glAttachShader( _programId, shaderId );
	_shaders.push_back( shaderId );
	return true;
}

bool ShaderProgram::linkAndValidateProgram()
{
	glLinkProgram( _programId );

	GLint success;
	glGetProgramiv( _programId, GL_LINK_STATUS, &success );
	if (!success)
	{
		GLchar infoLog[BUFFER_SIZE];
		glGetProgramInfoLog( _programId, BUFFER_SIZE, NULL, infoLog );
		std::cerr << "Error linking the program: " << infoLog << "\n";
		return false;
	}

	glValidateProgram( _programId );
	glGetProgramiv( _programId, GL_VALIDATE_STATUS, &success );
	if (!success)
	{
		GLchar infoLog[BUFFER_SIZE];
		glGetProgramInfoLog( _programId, BUFFER_SIZE, NULL, infoLog );
		std::cerr << "Error validating the program: " << infoLog << "\n";
		return false;
	}

	return true;
}

void ShaderProgram::use()
{	
	glUseProgram( _programId );
}

