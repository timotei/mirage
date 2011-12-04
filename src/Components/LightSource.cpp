#include "LightSource.hpp"

LightSource::LightSource(GLenum lightNum) :
_lightNum(lightNum)
{
	glEnable(lightNum);
}

LightSource::~LightSource()
{
}

void LightSource::draw()
{
	glLightfv(_lightNum, GL_DIFFUSE, diffuse.toArray().get());
	glLightfv(_lightNum, GL_POSITION, position.toArray().get());
	glLightfv(_lightNum, GL_AMBIENT, ambient.toArray().get());
	glLightfv(_lightNum, GL_EMISSION, emission.toArray().get());
	glLightfv(_lightNum, GL_SPECULAR, specular.toArray().get());

	GLfloat shine[] = { shininess };
	glLightfv(_lightNum, GL_SHININESS, shine);
	
	/*glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glutSolidSphere(1, 10, 10);
	glPopMatrix()*/;
}
