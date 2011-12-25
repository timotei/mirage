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
	int res = luaL_loadfile(_state, path.c_str());
	if (res != 0){
		std::cerr << "Error loading script: " << path << "\n";
		return res;
	}

	std::cerr << "Loaded file " << path << "\n";

	res = lua_pcall(_state, 0, LUA_MULTRET, 0);

	if (res != 0){
		std::cerr << "Lua Error: " << lua_tostring(_state, -1) << "\n";
		lua_pop(_state, 1);
	}
	return res;
}

void LuaScript::callVoidFunction(std::string functionName)
{
	lua_getglobal(_state, functionName.c_str());

	lua_call(_state, 0, 0);
}