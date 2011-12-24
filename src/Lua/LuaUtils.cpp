#include "LuaUtils.hpp"

bool lua_tovector3(lua_State *L, int index, Vector3 &res)
{
	if (!lua_checkstack(L, LUA_MINSTACK))
		return false;

	// Get the absolute index of the table.
	int initial_top = lua_gettop(L);
	if (-initial_top <= index && index <= -1)
		index = initial_top + index + 1;

	for (lua_pushnil(L); lua_next(L, index); lua_pop(L, 1))
	{
		if (lua_isnumber(L, -2)) continue;

		const char* id = lua_tostring(L, -2);

		float nr = static_cast<float>(lua_tonumber(L, -1));

		if (id[0] == 'x'){
			res.x = nr;
		}else if (id[0] == 'y'){
			res.y = nr;
		}else if (id[0] == 'z'){
			res.z = nr;
		}
	}

	lua_settop(L, initial_top);
	return true;
}

Vector3 lua_checkvector3(lua_State *L, int index)
{
	Vector3 res;
	if (!lua_tovector3(L, index, res))
		luaL_typerror(L, index, "Vector 3");

	return res;
}

void lua_pushvector3(lua_State *L, const Vector3& vec)
{
	lua_newtable(L);

	if (!lua_checkstack(L, LUA_MINSTACK))
		return;

	lua_pushnumber(L, vec.x);
	lua_setfield(L, -2, "x");

	lua_pushnumber(L, vec.y);
	lua_setfield(L, -2, "y");

	lua_pushnumber(L, vec.z);
	lua_setfield(L, -2, "z");
}
