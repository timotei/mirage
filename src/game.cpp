#include "GL/glew.h"
#include "GL/freeglut.h"
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

void initOpenGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glShadeModel(GL_SMOOTH); 
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); 
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0f, (GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT, 1.0f, 1000.0f); 

	glEnable(GL_DEPTH_TEST); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);

	glutSwapBuffers();
}

void changeSize(int w, int h)
{
	SCREEN_WIDTH=w;
	SCREEN_HEIGHT=h;

	if(h == 0)
		h = 1;

	float ratio = 1.0*w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 50.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
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
	glutIdleFunc(renderScene); 
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