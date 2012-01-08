#ifndef MIRAGE_GAME_HPP__
#define MIRAGE_GAME_HPP__

#include <list>
#include <time.h>
#include <boost/shared_ptr.hpp>
#include "nvMath.h"

#include "Utils.hpp"

class Skybox;
class Camera;
class GameComponent;
class LightSource;
class ShaderProgram;
class Model;

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

	int screenHeight;
	int screenWidth;

	Camera const * getCamera() { return _camera; }

private:
	DISALLOW_COPY_AND_ASSIGN(Game);

	typedef boost::shared_ptr<GameComponent> GameComponentPtr;
	typedef boost::shared_ptr<LightSource> LightSourcePtr;
	typedef boost::shared_ptr<Model> ModelPtr;

	struct ShadowedModel {
		ModelPtr model;

		nv::vec4f plane;
		nv::matrix4f matrix;
	};
	typedef boost::shared_ptr<ShadowedModel> ShadowedModelPtr;

	Skybox* _skybox;
	Camera* _camera;
	nv::matrix4f _projectionMatrix;
	
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
	void createBigBoxWithTeapot();
	void drawComponents( bool shadow );
};

#endif // MIRAGE_GAME_HPP__
