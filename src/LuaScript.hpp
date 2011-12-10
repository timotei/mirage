#ifndef MIRAGE_LUASCRIPT_HPP__
#define MIRAGE_LUASCRIPT_HPP__

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include <string>

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

#endif // MIRAGE_LUASCRIPT_HPP__
