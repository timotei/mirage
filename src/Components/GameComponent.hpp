#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

#include "../Lua/LuaScript.hpp"
#include <boost/shared_ptr.hpp>
#include "nvMath.h"
#include "tolua++.h"

#include "../ShaderProgram.hpp"

class Camera;

class GameComponent{
public:
	virtual void draw( Camera& ) = NULL;
	virtual void update() 
	{
		if ( script != NULL ) {
			script->callVoidFunction( "update" );
		}
	}

	virtual void onKeyPressed(int, int, int, bool) {};

	virtual void loadScript(std::string path) {
		script = boost::shared_ptr<LuaScript>(new LuaScript);

		tolua_pushusertype(*script, (void*)this, "GameComponent");
		lua_setglobal(*script, "CurrentComponent");

		script->executeScript(path);
	}


	virtual ~GameComponent() {}

	virtual nv::matrix4f getModelMatrix() {
		return 
			nv::matrix4f().set_translate( translation ) *
			nv::matrix4f().set_rotate_degrees( rotation ) * 
			nv::matrix4f().set_translate( translationPostRotation );
	}

	nv::vec3f translation;
	nv::vec3f translationPostRotation;
	nv::vec3f rotation;

	boost::shared_ptr<LuaScript> script;
	boost::shared_ptr<ShaderProgram> shader;
};

#endif // MIRAGE_GAMECOMPONENT_HPP__