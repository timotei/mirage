#include "LuaCamera.hpp"

#include "../Components/Camera.hpp"
#include "LuaUtils.hpp"

LuaCamera::LuaCamera(lua_State *L)
{
	_camera = (Camera*) lua_touserdata(L, 1);
}

LuaCamera::~LuaCamera()
{
}

int LuaCamera::setRotation(lua_State *L)
{
	_camera->rotation = lua_checkvector3(L, 1);

	return 0;
}

int LuaCamera::getRotation(lua_State *L)
{
	lua_pushvector3(L, _camera->rotation);
	return 1;
}

int LuaCamera::setPosition(lua_State *L)
{
	_camera->position = lua_checkvector3(L, 1);
	return 0;
}

int LuaCamera::getPosition(lua_State *L)
{
	lua_pushvector3(L, _camera->position);
	return 1;
}