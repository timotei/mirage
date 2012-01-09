/*
   Copyright (C) 2011-2012 by Timotei Dolean <timotei21@gmail.com>

   Part of the Mirage Project https://github.com/timotei/mirage

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
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
		float sinX = float(sin(toRadians(rotation.x))) / 2;
		float sinY = float(sin(toRadians(rotation.y))) / 2;
		// float cosX = float(cos(toRadians(rotation.x))) / 2;
		float cosY = float(cos(toRadians(rotation.y))) / 2;

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
		case 'u':
			useAnimation = !useAnimation;
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

nv::matrix4f Camera::getViewMatrix() const
{
	return
		nv::matrix4f().set_rotate_degrees( rotation ) *
		nv::matrix4f().set_translate( - position );
}

void Camera::setProjectionMatrix( nv::matrix4f newMat )
{
	_projectionMatrix = newMat;
}

const nv::matrix4f& Camera::getProjectionMatrix() const
{
	return _projectionMatrix;
}
