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
#include "LuaScript.hpp"

#include <iostream>
#include <sstream>
#include "LuaMirage.hpp"

LuaScript::LuaScript() :
_state(lua_open())
{
	luaL_openlibs(_state);
	tolua_luamirage_open(_state);
}

LuaScript::~LuaScript()
{
	lua_close(_state);
	_state = NULL;
}

int LuaScript::executeScript(std::string path)
{
	std::cout << "Loading lua script " << path << " ...";
	int res = luaL_loadfile(_state, path.c_str());
	if (res != 0){
		std::cerr << "Error loading script: " << path << "\n";
		std::cerr << "The error(s): " << lua_tostring(_state, -1) << "\n";
		return res;
	}

	res = lua_pcall(_state, 0, LUA_MULTRET, 0);

	if (res != 0){
		std::cerr << "Lua Error: " << lua_tostring(_state, -1) << "\n";
		lua_pop(_state, 1);
	}

	std::cout << "done.\n";
	return res;
}

void LuaScript::callVoidFunction(std::string functionName)
{
	lua_getglobal(_state, functionName.c_str());

	lua_call(_state, 0, 0);
}