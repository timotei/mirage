#ifndef MIRAGE_CAMERA_HPP__
#define MIRAGE_CAMERA_HPP__

#include "GL/freeglut.h"

#include "GameComponent.hpp"
#include "../Vector3.hpp"

class Camera : public GameComponent{
public:
	static const int MOVEMENT_UNIT = 1;
	Vector3 position;
	Vector3 target;
	Vector3 up;

	Camera();
	void update() {}
	void draw();

	void onKeyPressed(char key, int mouseX, int mouseY, bool special = false);
	void onMouseMoved(int x, int y, bool buttonPressed = true);
	void onMousePressed( int button, int state, int x, int y );
private:
	int _lastMouseX;
	int _lastMouseY;

	GLfloat _rotationX;
	GLfloat _rotationY;
};

#endif // MIRAGE_CAMERA_HPP__
