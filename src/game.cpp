/*
   Copyright (C) 2011-2012 by Timotei Dolean <timotei21@gmail.com>

   Part of the Mirage Project https://github.com/timotei/mirage

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#endif

#include "Game.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <boost/make_shared.hpp>

#include "Camera.hpp"
#include "Components/GameComponent.hpp"
#include "Components/Model.hpp"
#include "Components/LightSource.hpp"
#include "Components/Skybox.hpp"

#include "Lua/LuaScript.hpp"

#include "Math.hpp"

using boost::shared_ptr;

const GLenum _visualizationModes[3] = { GL_FILL, GL_LINE, GL_POINT };
int _currentVisualizationMode = 0;

Game::Game() :
_skybox( NULL ),
_camera( NULL ),
_components( 0 ),
_lights( 0 ),
_enableShadows( true )
{
	srand( ( unsigned int ) time( NULL ) );
}

Game::~Game()
{
	delete _skybox;
	delete _camera;
}

void Game::initOpenGL() {
	_camera = new Camera;
	_camera->useAnimation = false;
	_camera->loadScript("data/scripts/camera_anim.lua");

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
void Game::createBigBoxWithSphere()
{
	ModelPtr sphere( new Model( this ) );
	sphere->loadSphere( 1, 100, 100, nv::vec4f( 1, 0, 0, 1 ) );
	sphere->shader = _defaultShaderProgram;

	_components.push_back( sphere );

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
		ModelPtr plane( new Model( this ) );
		plane->translationPostRotation = translations[ i ];
		plane->rotation = rotations [ i ];
		plane->loadPlane( x, z, nv::vec4f( 1, 1, 0, 1 ) );
		plane->shader = _defaultShaderProgram;

		plane->getPlanePoints( p1, p2, p3 );
		shadowedModel->model = plane;
		shadowedModel->plane = getPlaneEquation( p1, p2, p3 );

		_shadowedModels.push_back( shadowedModel );
	}
}

void Game::addObjects( int count, Model objectModel, float scale, float y )
{
	const int minX = -200, maxX = -200, minZ = -200, maxZ = 200;
	for( int i = 0; i < count; ++i ) {
		ModelPtr model = boost::make_shared<Model>( objectModel );
		model->shader = _defaultShaderProgram;
		model->scale = nv::vec3f( scale );

		model->translationPostRotation.x = ( float ) ( rand() % ( 2 * maxX ) + minX );
		model->translationPostRotation.y = y;
		model->translationPostRotation.z = ( float ) ( rand() % ( 2 * maxZ ) + minZ );

		model->rotation.y = ( float ) ( rand() % 360 );

		_components.push_back( model );
	}
}

void Game::createScene()
{
	// the ground
	ModelPtr ground( new Model( this ) );
	ground->loadPlane( 200, 200, nv::vec4f( .58f, .3f, 0, 1 ) );
	ground->translation = nv::vec3f( 0, -5, 0 );
	ground->shader = _defaultShaderProgram;
	ShadowedModelPtr sModel( new ShadowedModel );
	sModel->model = ground;

	nv::vec4f p1, p2, p3;
	ground->getPlanePoints( p1, p2, p3 );
	sModel->plane = getPlaneEquation(p1, p2, p3);
	_shadowedModels.push_back( sModel );

	// add cactuses
	Model cactus( this );
	cactus.loadFromFile( "data/models/cactus.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE );
	addObjects( 4, cactus, 6, 0 );

	Model cactus2( this );
	cactus2.loadFromFile( "data/models/low_poly/cactus_lo.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE  );
	addObjects( 6, cactus2, 6, 0 );

	Model waterTower( this );
	waterTower.loadFromFile( "data/models/low_poly/water_tower_lo.obj", GLM_SMOOTH | GLM_MATERIAL );
	addObjects( 1,  waterTower, 15, 7 );

	Model spine( this );
	spine.loadFromFile( "data/models/low_poly/spine.obj", GLM_SMOOTH | GLM_MATERIAL );
	addObjects( 3, spine, 4, -4 );

	Model bird( this );
	bird.loadFromFile( "data/models/brown_bird.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE );
	bird.loadScript( "data/scripts/bird.lua" );
	addObjects( 2, bird, 5, 15 );

	Model house( this );
	house.loadFromFile( "data/models/house.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE );
	addObjects( 1, house, 15, 3 );

	Model balloon( this );
	balloon.loadFromFile( "data/models/balloon.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE );
	balloon.loadScript( "data/scripts/balloon.lua" );
	addObjects( 1, balloon, 15, 35 );

	Model camel( this );
	camel.loadFromFile( "data/models/camel.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE );
	addObjects( 2, camel, 8, 1.7f );

	Model palm_tree( this );
	palm_tree.loadFromFile( "data/models/palm_tree.obj", GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE );
	addObjects( 5, palm_tree, 15, 10 );
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
	
	LightSourcePtr sun( new LightSource( this ) );
	sun->translation = nv::vec3f( -4, 0, 0 );
	sun->color = nv::vec4f( 1, 1, 1, 1 );
	sun->loadScript( "data/scripts/sun.lua" );
	_lights.push_back( sun );

	LightSourcePtr light1( new LightSource( this ) );
	light1->translation = nv::vec3f( 0, 0, 35);
	light1->color = nv::vec4f( 1, 1, 1, 1 );
	_lights.push_back( light1 );

	_skybox = new Skybox( this, 50, 30, 50 );
	_skybox->loadTextures( "data/gfx/skybox/desert_evening" );

//	createBigBoxWithSphere();

	createScene();

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
}

void Game::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, _visualizationModes[_currentVisualizationMode]);
	glLoadIdentity();

	_skybox->draw( );
	_camera->draw( );

	foreach( LightSourcePtr light, _lights ){
		light->draw( );
	}
	
	if ( _enableShadows ) {
		glEnable( GL_STENCIL_TEST );
		glStencilOp( GL_KEEP, GL_KEEP, GL_REPLACE );

		foreach( ShadowedModelPtr shadowedModel, _shadowedModels ) {

			glStencilFunc( GL_ALWAYS, 1, 0 );
			glClear( GL_STENCIL_BUFFER_BIT );

			shadowedModel->model->draw( );

			foreach( LightSourcePtr light, _lights ) {
				// compute the shadowmatrix
				shadowedModel->matrix = getShadowMatrix( shadowedModel->plane, light->getPosition() );

				glStencilFunc( GL_EQUAL, 1, 1 );
				glDisable( GL_DEPTH_TEST );

				glPushMatrix();
					glMultMatrixf( shadowedModel->matrix._array );

					foreach( GameComponentPtr component, _components ) {
						component->draw( true );
					}
				glPopMatrix();

				glEnable( GL_DEPTH_TEST );
			}
		}
		glDisable( GL_STENCIL_TEST );
	}else {
		// normal drawing
		foreach( ShadowedModelPtr shadowedModel, _shadowedModels ) {
			shadowedModel->model->draw( );
		}
	}

	foreach( GameComponentPtr component, _components ) {
		component->draw( false );
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

	nv::matrix4f matrix;
	glGetFloatv( GL_PROJECTION_MATRIX, matrix._array );
	_camera->setProjectionMatrix( matrix );
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
	}else if ( id == 1001 ) {
		_enableShadows = !_enableShadows;
	}
}

const std::list<boost::shared_ptr<LightSource>>& Game::getLights () const
{
	return _lights;
}
