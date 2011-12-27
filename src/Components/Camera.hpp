#ifndef MIRAGE_CAMERA_HPP__
#define MIRAGE_CAMERA_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include "GameComponent.hpp"
#include "../Vector3.hpp"

class Camera : public GameComponent{
public:
	static const int MOVEMENT_UNIT = 1;
	Vector3 position;
	Vector3 target;
	Vector3 up;

	bool useAnimation;

	Camera();
	void update() {}
	void draw();

	void onKeyPressed(int key, int mouseX, int mouseY, bool special = false);
	void onMouseMoved(int x, int y, bool buttonPressed = true);
	void onMousePressed( int button, int state, int x, int y );

	void loadScript(std::string path);

private:
	int _lastMouseX;
	int _lastMouseY;
};

#endif // MIRAGE_CAMERA_HPP__
