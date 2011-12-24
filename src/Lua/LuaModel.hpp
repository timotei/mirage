#ifndef MIRAGE_LUAMODEL_HPP__
#define MIRAGE_LUAMODEL_HPP__

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "../Lua/Luna.hpp"

class Model;

class LuaModel{
public:
	static const char className[];
	static Luna<LuaModel>::RegType methods[];

	LuaModel(lua_State *L);
	~LuaModel();

	int setRotation(lua_State *L);
	int getRotation(lua_State *L);
private:
	Model* _model;
};

#endif // MIRAGE_LUAMODEL_HPP__
