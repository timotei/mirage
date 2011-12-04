#include "Camera.hpp"
#include "../Utils.hpp"

#include <iostream>
#include <math.h>

Camera::Camera()
: up(0, 1, 0),
_lastMouseX(-1),
_lastMouseY(-1)
{
}

void Camera::onMouseMoved(int x, int y, bool isButtonPressed /* = true */){
	if (isButtonPressed){
		int deltaX = x - _lastMouseX;
		int deltaY = y - _lastMouseY;

		_rotationX += deltaY / 3;
		if (_rotationX >= 360) _rotationX -= 360;

		_rotationY += deltaX / 3;
		if (_rotationY >= 360) _rotationY -= 360;
	}
	_lastMouseX = x;
	_lastMouseY = y;
}

void Camera::onKeyPressed(int key, int mouseX, int mouseY, bool special){
	if (!special){
		float sinX = float(sin(toRadians(_rotationX)));
		float sinY = float(sin(toRadians(_rotationY)));
		float cosX = float(cos(toRadians(_rotationX)));
		float cosY = float(cos(toRadians(_rotationY)));

		switch( key ) {
			case 'w':
				position.x += sinY;
				position.y -= sinX;
				position.z -= cosY;
				break;
			case 'a':
				position.x -= cosY;
				position.z -= sinY;
				break;
			case 's':
				position.x -= sinY;
				position.y += sinX;
				position.z += cosY;
				break;
			case 'd':
				position.x += cosY;
				position.z += sinY;
				break;
		}
	}else{
		if (key == GLUT_KEY_PAGE_UP) {
			position.y += 1;
		} else if (key == GLUT_KEY_PAGE_DOWN){
			position.y -= 1;
		}
	}
}

void Camera::draw(){
	glLoadIdentity();
	glRotatef(_rotationX, 1, 0, 0);
	glRotatef(_rotationY, 0, 1, 0);

	glTranslatef(-position.x, -position.y, -position.z);
}

void Camera::onMousePressed( int button, int state, int x, int y )
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		_lastMouseX = x;
		_lastMouseY = y;
	}
}
