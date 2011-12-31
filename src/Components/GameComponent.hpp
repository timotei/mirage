#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

#include "../Lua/LuaScript.hpp"
#include <boost/shared_ptr.hpp>
#include "nvMath.h"

#include "../ShaderProgram.hpp"

class GameComponent{
public:
	virtual void draw() {}
	virtual void update() 
	{
		if ( script != NULL ) {
			script->callVoidFunction( "update" );
		}
	}

	virtual void onKeyPressed(int, int, int, bool) {};

	virtual void loadScript(std::string path) {}

	virtual ~GameComponent() {}

	virtual nv::matrix4f getModelMatrix() {
		return 
			nv::matrix4f().set_rotate_degrees( rotation ) * 
			nv::matrix4f().set_translate( translation );
	}

	nv::vec3f translation;
	nv::vec3f rotation;

	boost::shared_ptr<LuaScript> script;
	ShaderProgram shader;
};

#endif // MIRAGE_GAMECOMPONENT_HPP__