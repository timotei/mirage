#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

#include "../Vector3.hpp"
#include "../Lua/LuaScript.hpp"
#include <boost/shared_ptr.hpp>

class GameComponent{
public:
	virtual void draw() {}
	virtual void update() {	}

	virtual void onKeyPressed(int, int, int, bool)  {};

	virtual void loadScript(std::string path) {}

	virtual ~GameComponent() {}

	Vector3 translation;
	Vector3 rotation;
	boost::shared_ptr<LuaScript> script;
};

#endif // MIRAGE_GAMECOMPONENT_HPP__