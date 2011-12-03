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
	GLfloat diffuse[4] = { _diffuse.x, _diffuse.y, _diffuse.z, 1 };
	glLightfv(_lightNum, GL_DIFFUSE, diffuse);

	GLfloat position[4] = { _position.x, _position.y, _position.z };
	glLightfv(_lightNum, GL_POSITION, position);

	GLfloat ambient[4] = { _ambient.x, _ambient.y, _ambient.z, 1 };
	glLightfv(_lightNum, GL_AMBIENT, ambient);

	glTranslatef(_position.x, _position.y, _position.z);
	glutSolidSphere(1, 10, 10);
}
