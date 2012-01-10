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
#ifndef MIRAGE_GAME_HPP__
#define MIRAGE_GAME_HPP__

#include <list>
#include <time.h>
#include <boost/shared_ptr.hpp>
#include "nvMath.h"

#include "Utils.hpp"
#include "Components/Model.hpp"
#include "Components/LightSource.hpp"

class Skybox;
class Camera;
class GameComponent;
class ShaderProgram;

class Game {
public:
	Game();
	~Game();

	void runGame();

	void onNormalKeyPressed( unsigned char key, int x, int y );
	void onResolutionChanged( int w, int h );
	void onSpecialKeyPressed( int key, int x, int y );
	void onMouseMoved( int x, int y );
	void onMousePressed( int button, int state, int x, int y );
	void onMenuEntrySelected( int id );
	void onExit();
	void updateGame();

	const std::list<LightSourcePtr>& getLights() const;

	int screenHeight;
	int screenWidth;

	Camera const * getCamera() { return _camera; }

private:
	DISALLOW_COPY_AND_ASSIGN(Game);

	struct ShadowedModel {
		ModelPtr model;

		nv::vec4f plane;
		nv::matrix4f matrix;
	};
	typedef boost::shared_ptr<GameComponent> GameComponentPtr;
	typedef boost::shared_ptr<ShadowedModel> ShadowedModelPtr;

	Skybox* _skybox;
	Camera* _camera;
	
	std::list<LightSourcePtr> _lights;
	std::list<GameComponentPtr> _components;
	std::list<ShadowedModelPtr> _shadowedModels;

	clock_t _lastClock;
	time_t _lastTime;
	double _unprocessedTicks;
	long _fps, _ticks;

	bool _enableShadows;

	boost::shared_ptr<ShaderProgram> _defaultShaderProgram;

	void updateScene();
	void renderScene();
	void updateGameTitle();

	void initOpenGL();
	void initGame();
	void initProjectionMatrix( int width, int height );
	void createBigBoxWithSphere();
	void drawComponents( bool shadow );
	void createScene();
	void addObjects( int count, Model objectModel, float scale, float y );
};

#endif // MIRAGE_GAME_HPP__
