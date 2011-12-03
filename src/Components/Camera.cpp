#include "Camera.hpp"

#include <iostream>

Camera::Camera()
: up(0, 1, 0),
_lastMouseX(-1),
_lastMouseY(-1)
{
}

void Camera::onMouseMoved(int x, int y, bool buttonPressed /* = true */){
	if (buttonPressed){
		int deltaX = x - _lastMouseX;
		int deltaY = y - _lastMouseY;

		_rotationX += deltaY;
		_rotationY += deltaX;
	}
	_lastMouseX = x;
	_lastMouseY = y;
}

void Camera::onKeyPressed(char key, int mouseX, int mouseY, bool special){
	if (!special){
		switch( key ) {
			case 'w':
				position.z -= MOVEMENT_UNIT;
				break;
			case 'a':
				position.x -= MOVEMENT_UNIT;
				target.x -= MOVEMENT_UNIT;
				break;
			case 's':
				position.z += MOVEMENT_UNIT;
				break;
			case 'd':
				position.x += MOVEMENT_UNIT;
				target.x += MOVEMENT_UNIT;
				break;
		}
	}
}

void Camera::draw(){
	glMatrixMode(GL_MODELVIEW);
	glRotatef(_rotationX, 1, 0, 0);
	glRotatef(_rotationY, 0, 1, 0);

	gluLookAt(position.x, position.y, position.z, 
		target.x, target.y, target.z,
		up.x, up.y, up.z);
}

void Camera::onMousePressed( int button, int state, int x, int y )
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		_lastMouseX = x;
		_lastMouseY = y;
	}
}
