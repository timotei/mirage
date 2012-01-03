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

private:
	DISALLOW_COPY_AND_ASSIGN(Game);

	typedef boost::shared_ptr<GameComponent> GameComponentPtr;

	Skybox* _skybox;
	Camera* _camera;
	nv::matrix4f _projectionMatrix;
	
	LightSource* _sun;

	std::list<GameComponentPtr> _components;

	clock_t _lastClock;
	time_t _lastTime;
	double _unprocessedTicks;
	long _fps, _ticks;

	bool _usePerPixelLighting;
	boost::shared_ptr<ShaderProgram> _defaultShaderProgram;

	void updateScene();
	void renderScene();
	void updateGameTitle();

	void initOpenGL();
	void initGame();
	void initProjectionMatrix( int width, int height );
};

#endif // MIRAGE_GAME_HPP__
