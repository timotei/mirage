#include "LightSource.hpp"

#include <sstream>

static int LIGHTS_COUNTER = 0;

LightSource::LightSource() : 
_index( LIGHTS_COUNTER )
{
	LIGHTS_COUNTER ++ ;
}

LightSource::~LightSource()
{
}

void LightSource::draw()
{
	glPushMatrix();

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(1, 10, 10);

	glPopMatrix();
}

void LightSource::sendToShaderProgram( ShaderProgram& program )
{
	std::ostringstream name;

	name << "lights[" << _index << "].position";

	program.setUniform( name.str().c_str() , position );
}