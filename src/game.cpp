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

#define foreach BOOST_FOREACH

typedef boost::shared_ptr<GameComponent> GameComponentPtr;
typedef std::list<GameComponentPtr> GameComponentsVector;

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 600;
Vector3 _cameraPosition;
Vector3 _cameraTarget;
int _cameraMovement = 1;
GameComponentsVector _components(0);

GLMmodel *box;

bool loadModel(GLMmodel *&targetModel, char* fileName, bool unitize = true, bool force = false){
	if (targetModel == NULL || force){
		targetModel = glmReadOBJ(fileName);

		if (targetModel == NULL) return false;

		if (unitize){
			glmUnitize(targetModel);
		}

		glmFacetNormals(targetModel);
		glmVertexNormals(targetModel, 90.0);
	}
	return true;
}

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
	_cameraPosition.z = 10;
}

void initGame(){
	_components.push_back(GameComponentPtr(new FPSCounter));

	loadModel(box, "data/models/box.obj");
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
	gluLookAt(_cameraPosition.x, _cameraPosition.y, _cameraPosition.z, 
		_cameraTarget.x, _cameraTarget.y, _cameraTarget.z,
		0.0, 1.0, 0.0);

	glmDraw(box, GLM_SMOOTH);

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

	switch( key ) {
		case 'w':
			_cameraPosition.z -= _cameraMovement;
			break;
		case 'a':
			_cameraPosition.x -= _cameraMovement;
			_cameraTarget.x -= _cameraMovement;
			break;
		case 's':
			_cameraPosition.z += _cameraMovement;
			break;
		case 'd':
			_cameraPosition.x += _cameraMovement;
			_cameraTarget.x += _cameraMovement;
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

	initGame();

	//Starts the GLUT infinite loop 
	glutMainLoop();
	return 0;
}