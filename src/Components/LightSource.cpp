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
	glLightfv(_lightNum, GL_POSITION, position.toArray().get());

	glLightfv(_lightNum, GL_DIFFUSE, diffuse.toArray().get());
	glLightfv(_lightNum, GL_AMBIENT, ambient.toArray().get());
	glLightfv(_lightNum, GL_EMISSION, emission.toArray().get());
	glLightfv(_lightNum, GL_SPECULAR, specular.toArray().get());

	GLfloat shine[1] = { shininess };
	glLightfv(_lightNum, GL_SHININESS, shine);
	
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(modelPosition.x, modelPosition.y, modelPosition.z);
		glutSolidSphere(1, 10, 10);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}
