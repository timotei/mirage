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

#include "Lua/LuaScript.hpp"

#define foreach BOOST_FOREACH

using boost::shared_ptr;

typedef shared_ptr<Model> ModelPtr;
typedef shared_ptr<GameComponent> GameComponentPtr;
typedef std::list<GameComponentPtr> GameComponentsVector;

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 600;

//TODO: SOLID vs POLYGON? - what about SMOOTH
GLenum _visualization[2] = { GL_FILL, GL_LINE };
int _visualizeMode = 0;

Camera _camera;
GameComponentsVector _components(0);

LightSource *_sun;

ModelPtr _snake;
GLfloat _snakeRotationIncrement = 0.05f;

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
	_camera.loadScript("data/scripts/camera_anim.lua");
}

void initGame(){
	_components.push_back(GameComponentPtr(new FPSCounter));

	_sun = new LightSource(GL_LIGHT0);
	_sun->diffuse = Vector4(1, 1, 1, 1);
	_sun->position = Vector4(0, -10, 0, 0);
	_sun->modelPosition = Vector3(0, 10, 0);
	_sun->ambient = Vector4(1, 1, 1, 1);

	shared_ptr<Skybox> skybox(new Skybox(50, 20, 50));
	skybox->loadTextures("data/gfx/skybox/desert_evening");
	_components.push_back(skybox);

	_snake = ModelPtr(new Model);
	_snake->loadFromFile("data/models/low_poly/snake_lo.obj", GLM_SMOOTH | GLM_TEXTURE);
	_snake->loadTexture("data/gfx/textures/snake1.tga");
	_snake->translation = Vector3(-3, 0, 0);

	_snake->loadScript("data/scripts/snake.lua");

	_components.push_back(_snake);
}

void updateScene()
{
	_camera.update();
	if (_camera.useAnimation)
		_camera.script->callVoidFunction("update");
	_sun->update();

	foreach(GameComponentPtr component, _components){
		if (component->script != NULL){
			component->script->callVoidFunction("update");
		}
		component->update();
	}

	_sun->rotation.z += 0.1f;
	if (_sun->rotation.z >= 360) _sun->rotation.z -= 360;
}

void renderScene(void)
{
	// update
	updateScene();

	// draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, _visualization[_visualizeMode]);

	_sun->draw();
	_camera.draw();

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
	
	if (key == '1'){
		_visualizeMode = (_visualizeMode + 1) % 2;
	}

	_camera.onKeyPressed(key, x, y);
}
void processSpecialKeys(int key, int x, int y)
{ 	
	_camera.onKeyPressed(key, x, y, true);
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
	glutSpecialFunc(processSpecialKeys);

	glutMouseFunc(mousePressed);
	glutMotionFunc(mouseMotion);
	//Initialize some OpenGL parameters 
	initOpenGL(); 

	initGame();

	//Starts the GLUT infinite loop 
	glutMainLoop();
	return 0;
}