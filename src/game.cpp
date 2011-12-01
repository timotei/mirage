#include "GL/glew.h"
#include "GL/freeglut.h"
#include "glm.h"

#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <sstream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include "Components/GameComponent.hpp"

#define foreach BOOST_FOREACH

typedef boost::shared_ptr<GameComponent> GameComponentPtr;
typedef std::vector<GameComponentPtr> GameComponentsVector;

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 600;
int camera[3] = {0};
GameComponentsVector _components(0);

int fps;

void initProjectionMatrix(int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

	if(height == 0)
		height = 1;

	float ratio = 1.0 * width / height;

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

	// inits
	camera[3] = 50;
}

void updateScene()
{
	foreach(GameComponentPtr component, _components){
		component->update();
	}
}

void renderScene(void)
{
	// update
	updateScene();

	// draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(camera[0], camera[1], camera[2], 0.0, 0.0, 0, 0.0, 1.0, 0.0);

	foreach(GameComponentPtr component, _components){
		component->draw();
	}

	glutSwapBuffers();

	std::stringstream ss;
	ss << "Mirage - " << fps << "fps";
	glutSetWindowTitle(ss.str().c_str());
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

	switch( key ) {
		case 'w': 
			break;
		case 'a':
			break;
		case 's':
			break;
		case 'd':
			break;
		default:
			break;
	}
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
	//Initialize some OpenGL parameters 
	initOpenGL(); 
	//Starts the GLUT infinite loop 
	glutMainLoop();
	return 0;
}