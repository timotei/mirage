#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#endif

#include "Game.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <vector>
#include <boost/foreach.hpp>

#include "Components/GameComponent.hpp"
#include "Components/Camera.hpp"
#include "Components/Model.hpp"
#include "Components/LightSource.hpp"
#include "Components/Skybox.hpp"

#include "Lua/LuaScript.hpp"

#define foreach BOOST_FOREACH

using boost::shared_ptr;

typedef shared_ptr<Model> ModelPtr;

const GLenum _visualizationModes[3] = { GL_FILL, GL_LINE, GL_POINT };
int _currentVisualizationMode = 0;

bool switchShader = false;

Game::Game() :
_skybox( NULL ),
_camera( NULL ),
_components( 0 ),
_sun( NULL ),
_usePerPixelLighting( true )
{
}

Game::~Game()
{
	delete _skybox;
	delete _camera;
	delete _sun;
}

void Game::initOpenGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glShadeModel(GL_SMOOTH); 

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
	initProjectionMatrix(screenWidth, screenHeight);

	glLoadIdentity();

	//enablers
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

boost::shared_ptr<ShaderProgram> _program;
void Game::initGame(){
	std::cout << "Init started.\n";

	_program = boost::shared_ptr<ShaderProgram>( new ShaderProgram );
	_program->attachNewShader( GL_VERTEX_SHADER, "data/shaders/default.perpixel.vert" );
	_program->attachNewShader( GL_FRAGMENT_SHADER, "data/shaders/default.perpixel.frag" );
	_program->linkAndValidateProgram();

	_camera = new Camera;
	_camera->useAnimation = false;
	_camera->loadScript("data/scripts/camera_anim.lua");

	_sun = new LightSource();
	_sun->translation = nv::vec3f( 0, 0, 4 );
	_sun->color = nv::vec4f( 1, 1, 1, 1 );
	_sun->loadScript( "data/scripts/sun.lua" );

	_skybox = new Skybox(50, 30, 50);
	_skybox->loadTextures("data/gfx/skybox/desert_evening");

	ModelPtr snake( new Model );
	snake->loadFromFile("data/models/low_poly/snake_lo.obj", GLM_NONE | GLM_TEXTURE);
	snake->loadTexture("data/gfx/textures/snake1.tga");
	snake->loadScript("data/scripts/snake.lua");
	snake->shader = _program;
	_components.push_back(snake);

	ModelPtr sphere( new Model );
	sphere->loadSphere( 3, 10, 10, nv::vec4f( 1, 0, 0, 1 ) );
	sphere->shader = _program;

	//_components.push_back( sphere );

	ModelPtr plane( new Model );
	plane->translation = nv::vec3f( 0, -3, 0 );
	plane->loadPlane( 10, 10, nv::vec4f( 0, 0, 0, 1 ) );
	plane->shader = _program;

	_components.push_back( plane );

	std::cout << "Init Done.\n";

	_lastClock = clock();
	_lastTime = time(NULL);
	_unprocessedTicks = 0;
}

void Game::updateScene()
{
	_camera->update();
	_sun->update();

	foreach(GameComponentPtr component, _components) {
		component->update();
	}

	if( switchShader ) {

		_usePerPixelLighting = !_usePerPixelLighting;

		_program->detachAllShaders();

		_program->attachNewShader( GL_VERTEX_SHADER, 
			_usePerPixelLighting ? "data/shaders/default.perpixel.vert" : "data/shaders/default.vert" );
		_program->attachNewShader( GL_FRAGMENT_SHADER, 
			_usePerPixelLighting ? "data/shaders/default.perpixel.frag" : "data/shaders/default.frag" );
		_program->linkAndValidateProgram();
		switchShader = false;
	}
}

void Game::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, _visualizationModes[_currentVisualizationMode]);
	glLoadIdentity();

	_camera->draw();
	nv::matrix4f viewMatrix = _camera->getViewMatrix();

	_skybox->draw();
	_sun->draw();

	foreach( GameComponentPtr component, _components ){
		boost::shared_ptr<ShaderProgram> program = component->shader;
		if ( program != NULL && program->isValid() ) {
			program->use();
			program->setUniform( "u_PMatrix" , _projectionMatrix );
			program->setUniform( "u_VMatrix", viewMatrix );
			program->setUniform( "u_MMatrix", component->getModelMatrix() );

			_sun->sendToShaderProgram( *program, *_camera );
		}

		component->draw( );

		if ( program != NULL )
			program->unUse();
	}
	
	glutSwapBuffers();
}

void Game::updateGameTitle()
{
	time_t now = time(NULL);
	if ((now - _lastTime) >= 1){
		std::stringstream ss;
		ss << "Mirage - " << _fps << " fps ; " << _ticks << " ticks";
		glutSetWindowTitle(ss.str().c_str());

		_lastTime = now;
		_fps = 0;
		_ticks = 0 ;
	}
}

void Game::runGame()
{	
	//Initialize some OpenGL parameters 
	initOpenGL(); 

	initGame();

	//Starts the GLUT infinite loop 
	glutMainLoop();
}

void Game::onNormalKeyPressed( unsigned char key, int x, int y )
{
	// ESCAPE 
	if ( key == 27 ) {
		onExit();
	}

	if ( key == '1' ) { 
		_currentVisualizationMode = (_currentVisualizationMode + 1) % 3;
	}else if ( key == '2' ) {
		switchShader = true;
	}

	_camera->onKeyPressed(key, x, y);
}

void Game::onSpecialKeyPressed( int key, int x, int y )
{
	_camera->onKeyPressed(key, x, y, true);
}

void Game::onResolutionChanged( int w, int h )
{
	initProjectionMatrix( w, h );
	glMatrixMode( GL_MODELVIEW );
}

void Game::onMouseMoved( int x, int y )
{
	_camera->onMouseMoved(x, y);
}

void Game::onMousePressed( int button, int state, int x, int y )
{
	_camera->onMousePressed( button, state, x, y );
}

void Game::updateGame()
{
	static const double MS_PER_TICKS = CLOCKS_PER_SEC / 60.0; // 60 fps
	clock_t now = clock();
	_unprocessedTicks += (double)(now - _lastClock) / MS_PER_TICKS;
	_lastClock = now;

	bool render = false;
	while(_unprocessedTicks >= 1) {
		++ _ticks;

		updateScene();
		_unprocessedTicks -= 1;
		render = true;
	}

	if (render) {
		++ _fps;
		// draw
		renderScene();
	}

	updateGameTitle();
	glutPostRedisplay();
}

void Game::initProjectionMatrix(int width, int height)
{
	screenWidth = width;
	screenHeight = height;

	if(height == 0)
		height = 1;

	float ratio = float(1.0 * width / height);

	glViewport(0, 0, screenWidth, screenHeight); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	glGetFloatv( GL_PROJECTION_MATRIX, _projectionMatrix._array );
}

void Game::onExit()
{
#if defined _WIN32 || defined _WIN64
	glutLeaveMainLoop();
#else
	exit(0);
#endif;	

#ifdef _MSC_VER
	_CrtDumpMemoryLeaks();
#endif
}
