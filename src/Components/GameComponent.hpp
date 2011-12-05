#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

#include "../Vector3.hpp"

class GameComponent{
public:
	virtual void draw() {}
	virtual void update() {}

	virtual void onKeyPressed(int, int, int, bool)  {};

	virtual ~GameComponent() {}

	Vector3 translation;
	Vector3 rotation;
};

#endif // MIRAGE_GAMECOMPONENT_HPP__