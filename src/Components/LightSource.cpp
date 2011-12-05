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
	glPushMatrix();

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glLightfv(_lightNum, GL_POSITION, position.toArray().get());

	glLightfv(_lightNum, GL_DIFFUSE, diffuse.toArray().get());
	glLightfv(_lightNum, GL_AMBIENT, ambient.toArray().get());
	glLightfv(_lightNum, GL_EMISSION, emission.toArray().get());
	glLightfv(_lightNum, GL_SPECULAR, specular.toArray().get());

	GLfloat shine[1] = { shininess };
	glLightfv(_lightNum, GL_SHININESS, shine);
	
	glDisable(GL_LIGHTING);
	glTranslatef(modelPosition.x, modelPosition.y, modelPosition.z);
	glutSolidSphere(1, 10, 10);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}
