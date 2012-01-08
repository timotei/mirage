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

#include "Math.hpp"

#define foreach BOOST_FOREACH

using boost::shared_ptr;

const GLenum _visualizationModes[3] = { GL_FILL, GL_LINE, GL_POINT };
int _currentVisualizationMode = 0;

Game::Game() :
_skybox( NULL ),
_camera( NULL ),
_components( 0 ),
_lights( 0 )
{
}

Game::~Game()
{
	delete _skybox;
	delete _camera;
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

// for testing shadows
void Game::createBigBoxWithTeapot()
{
	ModelPtr sphere( new Model );
	sphere->loadTeapot( 1, nv::vec4f( 1, 0, 0, 1 ) );
	sphere->shader = _defaultShaderProgram;

	_components.push_back( sphere );

	LightSourcePtr light0 = * _lights.begin();
	nv::vec4f lightpos = light0->getModelMatrix() * nv::vec4f( light0->translation );
	float x = 7, y = 7, z = 7;
	nv::vec3f translations[] = {
		nv::vec3f( x, 0, 0 ),
		nv::vec3f( -x, 0, 0 ),
		nv::vec3f( 0, y, 0 ),
		nv::vec3f( 0, -y, 0 ),
		nv::vec3f( 0, 0, -z ),
		nv::vec3f( 0, 0, z ),
	};

	nv::vec3f rotations[] = {
		nv::vec3f( 0, 0, 90 ),
		nv::vec3f( 0, 0, -90 ),
		nv::vec3f( 0, 0, 180 ),
		nv::vec3f( 0, 0, 0 ),
		nv::vec3f( 90, 0, 0 ),
		nv::vec3f( -90, 0, 0 ),
	};

	_shadowedModels.clear();

	for( int i = 0; i < 6; ++ i ) {
		nv::vec4f p1, p2, p3;
		ShadowedModelPtr shadowedModel = ShadowedModelPtr( new ShadowedModel );
		ModelPtr plane( new Model );
		plane->translationPostRotation = translations[ i ];
		plane->rotation = rotations [ i ];
		plane->loadPlane( x, z, nv::vec4f( 1, 1, 0, 1 ) );

		plane->getPlanePoints( p1, p2, p3 );
		shadowedModel->model = plane;
		shadowedModel->light = light0;
		shadowedModel->plane = getPlaneEquation( p1, p2, p3 );
		shadowedModel->matrix = getShadowMatrix( shadowedModel->plane, lightpos );

		_shadowedModels.push_back( shadowedModel );
	}
}

void Game::initGame(){
	std::cout << "Init started.\n";

	_defaultShaderProgram = boost::shared_ptr<ShaderProgram>( new ShaderProgram );
	_defaultShaderProgram->attachNewShader( GL_VERTEX_SHADER, "data/shaders/default.vert" );
	_defaultShaderProgram->attachNewShader( GL_FRAGMENT_SHADER, "data/shaders/default.frag" );
	_defaultShaderProgram->linkAndValidateProgram();

	// ambient
	GLfloat globalAmbient[4] = { .1f, .1f, .1f, 1.0f};
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, globalAmbient );

	_camera = new Camera;
	_camera->useAnimation = false;
	_camera->loadScript("data/scripts/camera_anim.lua");

	LightSourcePtr sun( new LightSource );
	sun->translation = nv::vec3f( -4, 0, 0 );
	sun->color = nv::vec4f( 1, 1, 1, 1 );
	sun->loadScript( "data/scripts/sun.lua" );
	_lights.push_back( sun );

	LightSourcePtr light1( new LightSource );
	light1->translation = nv::vec3f( 0, 0, 4);
	light1->color = nv::vec4f( 1, 1, 1, 1 );
	//_lights.push_back( light1 );

	_skybox = new Skybox(50, 30, 50);
	_skybox->loadTextures("data/gfx/skybox/desert_evening");

	createBigBoxWithTeapot();
	std::cout << "Init Done.\n";

	_lastClock = clock();
	_lastTime = time(NULL);
	_unprocessedTicks = 0;
}

void Game::updateScene()
{
	_camera->update();

	foreach( LightSourcePtr light, _lights ) {
		light->update();
	}

	foreach(GameComponentPtr component, _components) {
		component->update();
	}

	foreach( ShadowedModelPtr model, _shadowedModels ) {
		model->matrix = getShadowMatrix( model->plane, model->light->getModelMatrix() * nv::vec4f( model->light->translation ) );
	}
}

void Game::drawComponents( bool shadow )
{
	int lightsCount = _lights.size();
	nv::matrix4f viewMatrix = _camera->getViewMatrix();

	foreach( GameComponentPtr component, _components ) {
		boost::shared_ptr<ShaderProgram> program = component->shader;
		if ( program != NULL && program->isValid() && !shadow ) {
			program->use();
			program->setUniform( "u_PMatrix" , _projectionMatrix );
			program->setUniform( "u_VMatrix", viewMatrix );
			program->setUniform( "u_MMatrix", component->getModelMatrix() );
			program->setUniform( "u_LightsCount", lightsCount );

			foreach( LightSourcePtr light, _lights ) {
				light->sendToShaderProgram( *program, *_camera );
			}
		}

		component->draw( *_camera, shadow );

		if ( program != NULL )
			program->unUse();
	}
}

void Game::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, _visualizationModes[_currentVisualizationMode]);
	glLoadIdentity();

	_skybox->draw( *_camera );
	_camera->draw();

	foreach( LightSourcePtr light, _lights ){
		light->draw( *_camera );
	}
	
	foreach( ShadowedModelPtr shadowedModel, _shadowedModels ) {
		glEnable( GL_STENCIL_TEST );
		glStencilOp( GL_KEEP, GL_KEEP, GL_REPLACE );

		glStencilFunc( GL_ALWAYS, 1, 0 );
		glClear( GL_STENCIL_BUFFER_BIT );

		shadowedModel->model->draw( *_camera );

		glStencilFunc( GL_EQUAL, 1, 1 );
		glDisable( GL_DEPTH_TEST );
		
		glPushMatrix();
		glMultMatrixf( shadowedModel->matrix._array );
		(*_components.begin())->draw( *_camera, true);
		//drawComponents( true );
		glPopMatrix();

		glEnable( GL_DEPTH_TEST );

		glDisable( GL_STENCIL_TEST );
	}
	(*_components.begin())->draw( *_camera, false);
	
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

void Game::onMenuEntrySelected( int id )
{
	if ( id == 1000 ) { 
		_camera->useAnimation = !_camera->useAnimation;
	}else if ( id >= 100 && id <= 999 ) {
		_currentVisualizationMode = id % 10;
	}
}
