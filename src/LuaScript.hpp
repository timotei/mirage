#ifndef MIRAGE_LUASCRIPT_HPP__
#define MIRAGE_LUASCRIPT_HPP__

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class LuaScript{
private:
	lua_State *_state;

public:
	LuaScript();
	~LuaScript();

	inline operator lua_State* (){
		return _state;
	}

	int executeScript(const char* path);
};

#endif // MIRAGE_LUASCRIPT_HPP__
