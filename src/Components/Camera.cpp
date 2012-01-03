#include "Camera.hpp"
#include "../Utils.hpp"

#include <iostream>
#include <math.h>

#include "tolua++.h"
#include "../Lua/LuaScript.hpp"

Camera::Camera() : 
_lastMouseX(-1),
_lastMouseY(-1)
{
}

void Camera::onMouseMoved(int x, int y, bool isButtonPressed /* = true */){
	if ( isButtonPressed && _leftMousePressed ){
		int deltaX = x - _lastMouseX;
		int deltaY = y - _lastMouseY;

		rotation.x = clampDegree( rotation.x + deltaY / 3 );
		rotation.y = clampDegree( rotation.y + deltaX / 3 );
	}
	_lastMouseX = x;
	_lastMouseY = y;
}

void Camera::onKeyPressed(int key, int mouseX, int mouseY, bool special){
	if (!special){
		nv::vec4f delta;
		switch( key ) {
			case 'w':
				delta.z = -1;
				break;
			case 's':
				delta.z = 1;
				break;
			case 'a':
				delta.x = -1;
				break;
			case 'd':
				delta.x = 1;
				break;
			case 'u':
				useAnimation = !useAnimation;
				break;
		}

		delta = nv::matrix4f().set_rotate_degrees( - rotation ) * delta;
		position += normalize( delta._xyz );
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
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);

	glTranslatef(-position.x, -position.y, -position.z);
}

void Camera::onMousePressed( int button, int state, int x, int y )
{
	_leftMousePressed = false;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		_lastMouseX = x;
		_lastMouseY = y;
		_leftMousePressed = true;
	}
}

void Camera::loadScript(std::string path) 
{
	script = boost::shared_ptr<LuaScript>(new LuaScript);

	tolua_pushusertype(*script, (void*)this, "Camera");
	lua_setglobal(*script, "CurrentCamera");

	script->executeScript(path);
}

void Camera::update()
{
	if ( useAnimation && script != NULL )
		script->callVoidFunction( "update" );
}

nv::matrix4f Camera::getViewMatrix()
{
	return
		nv::matrix4f().set_rotate_degrees( rotation ) *
		nv::matrix4f().set_translate( - position );
}
