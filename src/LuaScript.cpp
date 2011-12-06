#include "LuaScript.hpp"

#include <iostream>

LuaScript::LuaScript(std::string path) :
_state(lua_open()),
_path(path)
{
	luaL_openlibs(_state);
	executeScript();
}

LuaScript::~LuaScript()
{
	lua_close(_state);
	_state = NULL;
}

int LuaScript::executeScript()
{
	int res = luaL_loadfile(_state, _path.c_str());
	if (res != 0){
		std::cerr << "Error loading script: " << _path << "\n";
		return res;
	}

	res = lua_pcall(_state, 0, LUA_MULTRET, 0);

	if (res != 0){
		std::cerr << "Lua Error: " << lua_tostring(_state, -1) << "\n";
		lua_pop(_state, 1);
	}
}

void LuaScript::callVoidFunction(std::string functionName)
{
	lua_getglobal(_state, functionName.c_str());

	lua_call(_state, 0, 0);
}