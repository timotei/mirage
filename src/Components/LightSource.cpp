#include "LightSource.hpp"

#include <sstream>

#include "Camera.hpp"

static int LIGHTS_COUNTER = 0;

LightSource::LightSource() : 
_index( LIGHTS_COUNTER ),
color( 1.0f, 1.0f, 1.0f, 1.0f )
{
	LIGHTS_COUNTER ++ ;
}

LightSource::~LightSource()
{
}

void LightSource::draw( Camera& cam)
{
	glPushMatrix();

	glTranslatef(translationPostRotation.x, translationPostRotation.y, translationPostRotation.z);

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glTranslatef(translation.x, translation.y, translation.z);
	glutSolidSphere(1, 10, 10);

	glPopMatrix();
}

void LightSource::sendToShaderProgram( ShaderProgram& program, Camera& cam )
{
	std::ostringstream name;
	name << "u_Lights[" << _index << "].position";

	nv::vec4f res = cam.getViewMatrix() *  getModelMatrix() * nv::vec4f( 0, 0, 0, 1.0f );
	program.setUniform( name.str().c_str(), res._xyz );

	name.str( "" );

	name << "u_Lights[" << _index << "].color";
	program.setUniform( name.str().c_str(), color );
}
