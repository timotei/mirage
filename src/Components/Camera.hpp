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
#ifndef MIRAGE_CAMERA_HPP__
#define MIRAGE_CAMERA_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "nvMath.h"

#include <string>
#include <boost/shared_ptr.hpp>

class LuaScript;

class Camera {
public:
	static const int MOVEMENT_UNIT = 1;

	nv::vec3f rotation;
	nv::vec3f position;

	bool useAnimation;

	Camera();
	void update();
	void draw();

	void onKeyPressed(int key, int mouseX, int mouseY, bool special = false);
	void onMouseMoved(int x, int y, bool buttonPressed = true);
	void onMousePressed( int button, int state, int x, int y );

	void loadScript(std::string path);

	nv::matrix4f getViewMatrix() const;

	const nv::matrix4f& getProjectionMatrix() const;
	void setProjectionMatrix( nv::matrix4f newMat );

	boost::shared_ptr<LuaScript> script;
private:
	bool _leftMousePressed;
	nv::matrix4f _projectionMatrix;

	int _lastMouseX;
	int _lastMouseY;
};

#endif // MIRAGE_CAMERA_HPP__
