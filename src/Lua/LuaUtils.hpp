#ifndef MIRAGE_LUAUTILS_HPP__
#define MIRAGE_LUAUTILS_HPP__

#include "../Vector3.hpp"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
}

void lua_pushvector3(lua_State *L, const Vector3& vec);

Vector3 lua_checkvector3(lua_State *L, int index);

bool lua_tovector3(lua_State *L, int index, Vector3 &res);

#endif // MIRAGE_LUAUTILS_HPP__
