/*
   Copyright (C) 2011-2012 by Timotei Dolean <timotei21@gmail.com>

   Part of the Mirage Project https://github.com/timotei/mirage

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
#ifndef MIRAGE_LUAMIRAGE_HPP__
#define MIRAGE_LUAMIRAGE_HPP__

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luamirage_open (lua_State* tolua_S);

#endif // MIRAGE_LUAMIRAGE_HPP__
