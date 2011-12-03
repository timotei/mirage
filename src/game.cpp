#include "GL/glew.h"
#include "GL/freeglut.h"
#include "glm.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include "Vector3.hpp"
#include "Components/GameComponent.hpp"
#include "Components/FPSCounter.hpp"
#include "Components/Camera.hpp"
#include "Components/Model.hpp"
#include "Components/LightSource.hpp"
#include "Components/Skybox.hpp"

#define foreach BOOST_FOREACH

typedef boost::shared_ptr<GameComponent> GameComponentPtr;
typedef std::list<GameComponentPtr> GameComponentsVector;

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 600;

Camera _camera;
GameComponentsVector _components(0);

LightSource *_moon,  *_sun;
GLfloat _sunRotate;

Model box;

void initProjectionMatrix(int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

	if(height == 0)
		height = 1;

	float ratio = float(1.0 * width / height);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
}


void initOpenGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glShadeModel(GL_SMOOTH); 

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
	initProjectionMatrix(SCREEN_WIDTH, SCREEN_HEIGHT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//enablers
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	// inits
	_camera.position.z = 10;
}

void initGame(){
	_components.push_back(GameComponentPtr(new FPSCounter));

	box.loadFromFile("data/models/box.obj");

	_sun = new LightSource(GL_LIGHT0);
	_sun->setDiffuse(Vector3(1, 1, 1));
	_sun->setPosition(Vector3(0, 10, 0));
	_sun->setAmbient(Vector3(1, 1, 1));

	_moon = new LightSource(GL_LIGHT1);

	boost::shared_ptr<Skybox> skybox(new Skybox(50, 10, 50));
	skybox->loadTextures("data/gfx/skybox/desertplains");
	_components.push_back(skybox);
}

void updateScene()
{
	_camera.update();
	_sun->update();
	_moon->update();

	foreach(GameComponentPtr component, _components){
		component->update();
	}

	_sunRotate += 0.1;
	if (_sunRotate >= 360) _sunRotate -= 360;
}

void renderScene(void)
{
	// update
	updateScene();

	// draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_camera.draw();
	glPushMatrix();
		//glRotatef(_sunRotate, 0, 0, 1);
		_sun->draw();
	glPopMatrix();
	_moon->draw();

	box.draw();

	foreach(GameComponentPtr component, _components){
		component->draw();
	}

	glutSwapBuffers();
}

void changeSize(int w, int h)
{
	initProjectionMatrix(w, h);
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y)
{ 
	// ESCAPE 
	if ( key == 27 ){
		glutLeaveMainLoop();
	}
	
	_camera.onKeyPressed(key, x, y);
}

void mouseMotion(int x, int y){
	_camera.onMouseMoved(x, y);
}

void mousePressed(int button, int state, int x, int y){
	_camera.onMousePressed(button, state, x, y);
}

void idleFunc(){
	glutPostRedisplay();
}
int main( int argc, char* argv[])
{
	//Initialize the GLUT library 
	glutInit(&argc, argv); 
	//Set the display mode 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
	//Set the initial position and dimensions of the window 
	glutInitWindowPosition(100, 100); 
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	
	//creates the window 
	glutCreateWindow("Mirage"); 
	//Specifies the function to call when the window needs to be redisplayed 
	glutDisplayFunc(renderScene); 
	//Sets the idle callback function 
	glutIdleFunc(idleFunc); 
	//Sets the reshape callback function 
	glutReshapeFunc(changeSize); 
	//Keyboard callback function 
	glutKeyboardFunc(processNormalKeys); 

	glutMouseFunc(mousePressed);
	glutMotionFunc(mouseMotion);
	//Initialize some OpenGL parameters 
	initOpenGL(); 

	initGame();

	//Starts the GLUT infinite loop 
	glutMainLoop();
	return 0;
}