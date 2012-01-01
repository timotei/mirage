#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include <iostream>

// find memory leaks :D
#ifdef DEBUG
	#define _CRTDBG_MAP_ALLOC
	#define NEW   new( _NORMAL_BLOCK, __FILE__, __LINE__)
	#include <stdlib.h>
	#include <crtdbg.h>
#else
	#define NEW   new
#endif

#include "Utils.hpp"
#include "Game.hpp"

Game mainGame;

void changeSize(int w, int h)
{
	mainGame.onResolutionChanged( w, h );
}

void processNormalKeys(unsigned char key, int x, int y)
{
	mainGame.onNormalKeyPressed( key, x, y );
}
void processSpecialKeys(int key, int x, int y)
{
	mainGame.onSpecialKeyPressed( key, x, y );
}

void mouseMotion(int x, int y)
{
	mainGame.onMouseMoved( x, y );
}

void mousePressed(int button, int state, int x, int y)
{
	mainGame.onMousePressed( button, state, x, y );
}

void displayFunc()
{
	mainGame.updateGame();
}

void idleFunc()
{
	glutPostRedisplay();
}

void registerCallbacks()
{
	//Specifies the function to call when the window needs to be redisplayed 
	glutDisplayFunc(displayFunc); 
	//Sets the idle callback function 
	glutIdleFunc(idleFunc); 
	//Sets the reshape callback function 
	glutReshapeFunc(changeSize); 
	//Keyboard callback function 
	glutKeyboardFunc(processNormalKeys); 
	glutSpecialFunc(processSpecialKeys);

	glutMouseFunc(mousePressed);
	glutMotionFunc(mouseMotion);
}

int main( int argc, char* argv[])
{
	//Initialize the GLUT library 
	glutInit(&argc, argv);

	//Set the display mode 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
	//Set the initial position and dimensions of the window 
	glutInitWindowPosition(400, 100); 
	glutInitWindowSize(mainGame.screenWidth, mainGame.screenHeight);
	
	//creates the window 
	glutCreateWindow("Mirage");

	registerCallbacks();
	
	// init GLEW
	GLenum err = glewInit();
	if (err != GLEW_OK){
		std::cerr << "Error trying to init glew: " << glewGetErrorString(err) << "\n";
		exit(1);
	}

	mainGame.runGame();

	mainGame.onExit();
	return 0;
}