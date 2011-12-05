#include "GL/glew.h"
#include "GL/freeglut.h"
#include "glm.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

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

//TODO: SOLID vs POLYGON? - what about SMOOTH
GLenum _visualization[2] = { GL_FILL, GL_LINE };
int _visualizeMode = 0;

Camera _camera;
GameComponentsVector _components(0);

LightSource *_moon,  *_sun;
GLfloat _sunRotate;

Model box;
Model _snake;
GLfloat _snakeRotation;
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
	_camera.position.z = 30;
}

void initGame(){
	_components.push_back(GameComponentPtr(new FPSCounter));

	box.loadFromFile("data/models/box.obj");

	_sun = new LightSource(GL_LIGHT0);
	_sun->diffuse = Vector4(1, 1, 1, 1);
	_sun->position = Vector4(0, -10, 0, 0);
	_sun->modelPosition = Vector3(0, 10, 0);
	_sun->ambient = Vector4(1, 1, 1, 1);

	_moon = new LightSource(GL_LIGHT1);

	boost::shared_ptr<Skybox> skybox(new Skybox(50, 20, 50));
	skybox->loadTextures("data/gfx/skybox/desert_evening");
	_components.push_back(skybox);

	_snake.loadFromFile("data/models/low_poly/snake_lo.obj", GLM_SMOOTH | GLM_TEXTURE);
	_snake.loadTexture("data/gfx/textures/snake1.tga");
}

void updateScene()
{
	_camera.update();
	_sun->update();
	_moon->update();

	foreach(GameComponentPtr component, _components){
		component->update();
	}

	_sunRotate += 0.1f;
	if (_sunRotate >= 360) _sunRotate -= 360;

	_snakeRotation += _snakeRotationIncrement;
	if (_snakeRotation >= 5 || _snakeRotation <= -5)
		_snakeRotationIncrement *= -1;
}

void renderScene(void)
{
	// update
	updateScene();

	// draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, _visualization[_visualizeMode]);

	_camera.draw();

	glPushMatrix();
		glRotatef(_sunRotate, 0, 0, 1);
		_sun->draw();
	glPopMatrix();
//	_moon->draw();

	//box.draw();
	glPushMatrix();
		glRotatef(_snakeRotation, 0, 1, 0);
		_snake.draw();
	glPopMatrix();

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
void report_errors(lua_State *L, int status)
{
  if ( status!=0 ) {
    std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1); // remove error message
  }
}

void initLua()
{
	char* file = "data/scripts/snake.lua";
	lua_State *L = lua_open();

	luaL_openlibs(L); // provides io.*

	std::cerr << "-- Loading file: " << file << std::endl;

    int s = luaL_loadfile(L, file);

    if ( s==0 ) {
      // execute Lua program
      s = lua_pcall(L, 0, LUA_MULTRET, 0);
    }

    report_errors(L, s);
    lua_close(L);
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

	initLua();

	//Starts the GLUT infinite loop 
	glutMainLoop();
	return 0;
}