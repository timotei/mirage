#include "LuaScript.hpp"

#include <iostream>

LuaScript::LuaScript() :
_state(lua_open())
{
	luaL_openlibs(_state);
}

LuaScript::~LuaScript()
{
	lua_close(_state);
	_state = NULL;
}

int LuaScript::executeScript(const char* path)
{
	int res = luaL_loadfile(_state, path);
	if (res != 0){
		std::cerr << "Error loading script: " << path << "\n";
		return res;
	}

	res = lua_pcall(_state, 0, LUA_MULTRET, 0);

	if (res != 0){
		std::cerr << "Lua Error: " << lua_tostring(_state, -1) << "\n";
		lua_pop(_state, 1);
	}
}
