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
	nv::vec3f target;
	nv::vec3f up;

	bool useAnimation;

	Camera();
	void update();
	void draw();

	void onKeyPressed(int key, int mouseX, int mouseY, bool special = false);
	void onMouseMoved(int x, int y, bool buttonPressed = true);
	void onMousePressed( int button, int state, int x, int y );

	void loadScript(std::string path);

	nv::matrix4f getViewMatrix();

	boost::shared_ptr<LuaScript> script;
private:
	bool _leftMousePressed;

	int _lastMouseX;
	int _lastMouseY;
};

#endif // MIRAGE_CAMERA_HPP__
