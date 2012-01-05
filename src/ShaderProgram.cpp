#include "ShaderProgram.hpp"

#include <sstream>
#include <iostream>
#include <fstream>
#include <boost/foreach.hpp>

#define BUFFER_SIZE 2048
#define foreach BOOST_FOREACH

ShaderProgram::ShaderProgram() :
_shaders( 0 ),
_valid( false ),
_prevProgramId( -1 )
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
		exit( 1 );
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

		exit( 1 );
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

		exit( 1 );
		return false;
	}

	glValidateProgram( _programId );
	glGetProgramiv( _programId, GL_VALIDATE_STATUS, &success );
	if (!success)
	{
		GLchar infoLog[BUFFER_SIZE];
		glGetProgramInfoLog( _programId, BUFFER_SIZE, NULL, infoLog );
		std::cerr << "Error validating the program: " << infoLog << "\n";

		exit( 1 );
		return false;
	}

	_valid = true;
	std::cout << "Program " << _programId << " validated.\n";

	return true;
}

void ShaderProgram::use()
{	
	if ( !_valid ) {
		std::cerr << "use: Program " << _programId << " not valid!";
		return;
	}

	glGetIntegerv( GL_CURRENT_PROGRAM, &_prevProgramId );

	glUseProgram( _programId );
}

void ShaderProgram::unUse()
{
	if ( _prevProgramId == -1 )
		return;

	glUseProgram( _prevProgramId );
	_prevProgramId = 0;
}

GLint ShaderProgram::getUniformLocation( const char* name ) 
{
	if ( !_valid ) {
		std::cerr << "getUniformLocation: Program " << _programId << " not valid!";
		return -1;
	}

	GLint locationId = glGetUniformLocation( _programId, name );
	if ( locationId == -1 ) {
		std::cerr << "Error! Couldn't get uniform location for: " << name << "\n";
	}

	return locationId;
}

void ShaderProgram::setUniform( const char* name, const nv::vec4f& value )
{
	GLint locationId = getUniformLocation( name );
	if ( locationId == -1 ) 
		return;
	
	glUniform4fv( locationId, 1, value.get_value() );
}

void ShaderProgram::setUniform( const char* name, const nv::vec3f& value )
{
	GLint locationId = getUniformLocation( name );
	if ( locationId == -1 ) 
		return;

	glUniform3fv( locationId, 1, value.get_value() );
}

void ShaderProgram::setUniform( const char* name, const nv::matrix4f& value )
{
	GLint locationId = getUniformLocation( name );
	if ( locationId == -1 ) 
		return;

	glUniformMatrix4fv( locationId, 1, GL_FALSE, value.get_value() );
}

void ShaderProgram::setUniform( const char* name, bool value )
{
	GLint locationId = getUniformLocation( name );
	if ( locationId == -1 ) 
		return;

	glUniform1i( locationId, value );
}

void ShaderProgram::detachAllShaders()
{
	foreach( GLint shader, _shaders ) {
		glDetachShader( _programId, shader );
		glDeleteShader( shader );
	}

	_shaders.clear();

	glDeleteProgram( _programId );
	_programId = glCreateProgram();
}
