#ifdef __WIN32
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "FPSCounter.hpp"

FPSCounter::FPSCounter() :
	_fps(0),
	_lastFps(0),
	_lastTime(0)
{
}

void FPSCounter::draw()
{
	std::stringstream ss;
	ss << "Mirage - " << _lastFps << "fps";
	glutSetWindowTitle(ss.str().c_str());
}

void FPSCounter::update()
{
	++ _fps;
	time_t currentTime = time(NULL);
	time_t delta = currentTime - _lastTime;
	if (delta >= 1){
		_lastFps = _fps;
		_lastTime = currentTime;
		_fps = 0;
	}
}