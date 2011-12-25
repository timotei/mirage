#ifndef MIRAGE_LUACAMERA_HPP__
#define MIRAGE_LUACAMERA_HPP__

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "../Lua/Luna.hpp"

class Camera;

class LuaCamera{
public:
	static const char className[];
	static Luna<LuaCamera>::RegType methods[];

	LuaCamera(lua_State *L);
	~LuaCamera();

	int setRotation(lua_State *L);
	int getRotation(lua_State *L);

	int setPosition(lua_State *L);
	int getPosition(lua_State *L);

private:
	Camera* _camera;
};

#endif // MIRAGE_LUACAMERA_HPP__
