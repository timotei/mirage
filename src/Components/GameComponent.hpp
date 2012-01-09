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
#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

#include "../Lua/LuaScript.hpp"
#include <boost/shared_ptr.hpp>
#include "nvMath.h"
#include "tolua++.h"

#include "../ShaderProgram.hpp"

class Game;
class Camera;
class LightSource;

class GameComponent{
public:

	GameComponent( Game* parent ) : 
	  parent( parent ),
	  scale( 1, 1, 1 )
	{ }
	virtual ~GameComponent() 
	{ }

	virtual void draw( bool = false ) = NULL;
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

	virtual nv::matrix4f getModelMatrix() {
		return 
			nv::matrix4f().set_translate( translationPostRotation ) *
			nv::matrix4f().set_rotate_degrees( rotation ) * 
			nv::matrix4f().set_translate( translation ) *
			nv::matrix4f().set_scale( scale );
	}

	nv::vec3f translation;
	nv::vec3f translationPostRotation;
	nv::vec3f rotation;
	nv::vec3f scale;

	Game* parent;
	boost::shared_ptr<LuaScript> script;
	boost::shared_ptr<ShaderProgram> shader;
};

#endif // MIRAGE_GAMECOMPONENT_HPP__