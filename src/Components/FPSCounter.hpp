#ifndef MIRAGE_FPSCOUNTER_HPP__
#define MIRAGE_FPSCOUNTER_HPP__

#include "GameComponent.hpp"

class FPSCounter : public GameComponent{
public:
	void update();
	void draw();
	FPSCounter();

private:
	time_t _lastTime;
	int _fps;
	int _lastFps;
};

#endif // MIRAGE_FPSCOUNTER_HPP__
