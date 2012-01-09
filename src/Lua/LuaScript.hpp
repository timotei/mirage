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
#ifndef MIRAGE_LUASCRIPT_HPP__
#define MIRAGE_LUASCRIPT_HPP__

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include <string>
#include <boost/shared_ptr.hpp>

class LuaScript{
private:
	lua_State *_state;

public:
	LuaScript();
	~LuaScript();

	inline operator lua_State* (){
		return _state;
	}

	int executeScript(std::string path);
	void callVoidFunction(std::string functionName);
};

typedef boost::shared_ptr<LuaScript> LuaScriptPtr;

#endif // MIRAGE_LUASCRIPT_HPP__
