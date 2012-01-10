/*
** Lua binding: luamirage
** Generated automatically by tolua++-1.0.92 on 01/10/12 11:28:20.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luamirage_open (lua_State* tolua_S);

#include "LuaMirage.hpp"
#include "../Game.hpp"
#include "../Camera.hpp"
#include "../Components/Model.hpp"
#include "../Components/GameComponent.hpp"
#include "nvMath.h"
using namespace nv;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_matrix4f (lua_State* tolua_S)
{
 matrix4f* self = (matrix4f*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Camera (lua_State* tolua_S)
{
 Camera* self = (Camera*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Model (lua_State* tolua_S)
{
 Model* self = (Model*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_vec3f (lua_State* tolua_S)
{
 vec3f* self = (vec3f*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_vec4f (lua_State* tolua_S)
{
 vec4f* self = (vec4f*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"vec4f");
 tolua_usertype(tolua_S,"GLuint");
 tolua_usertype(tolua_S,"GameComponent");
 tolua_usertype(tolua_S,"matrix4f");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"LuaScript");
 tolua_usertype(tolua_S,"Model");
 tolua_usertype(tolua_S,"vec3f");
 tolua_usertype(tolua_S,"Game");
}

/* get function: x of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_get_vec3f_x
static int tolua_get_vec3f_x(lua_State* tolua_S)
{
  vec3f* self = (vec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_set_vec3f_x
static int tolua_set_vec3f_x(lua_State* tolua_S)
{
  vec3f* self = (vec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_get_vec3f_y
static int tolua_get_vec3f_y(lua_State* tolua_S)
{
  vec3f* self = (vec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_set_vec3f_y
static int tolua_set_vec3f_y(lua_State* tolua_S)
{
  vec3f* self = (vec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_get_vec3f_z
static int tolua_get_vec3f_z(lua_State* tolua_S)
{
  vec3f* self = (vec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_set_vec3f_z
static int tolua_set_vec3f_z(lua_State* tolua_S)
{
  vec3f* self = (vec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec3f_new00
static int tolua_luamirage_vec3f_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec3f",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   vec3f* tolua_ret = (vec3f*)  Mtolua_new((vec3f)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec3f");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec3f_new00_local
static int tolua_luamirage_vec3f_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec3f",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   vec3f* tolua_ret = (vec3f*)  Mtolua_new((vec3f)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec3f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec3f_new01
static int tolua_luamirage_vec3f_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec3f",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  float Z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   vec3f* tolua_ret = (vec3f*)  Mtolua_new((vec3f)(X,Y,Z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec3f");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luamirage_vec3f_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vec3f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec3f_new01_local
static int tolua_luamirage_vec3f_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec3f",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  float Z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   vec3f* tolua_ret = (vec3f*)  Mtolua_new((vec3f)(X,Y,Z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec3f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luamirage_vec3f_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_get_vec4f_x
static int tolua_get_vec4f_x(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_set_vec4f_x
static int tolua_set_vec4f_x(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_get_vec4f_y
static int tolua_get_vec4f_y(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_set_vec4f_y
static int tolua_set_vec4f_y(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_get_vec4f_z
static int tolua_get_vec4f_z(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_set_vec4f_z
static int tolua_set_vec4f_z(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_get_vec4f_w
static int tolua_get_vec4f_w(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_set_vec4f_w
static int tolua_set_vec4f_w(lua_State* tolua_S)
{
  vec4f* self = (vec4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec4f_new00
static int tolua_luamirage_vec4f_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec4f",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   vec4f* tolua_ret = (vec4f*)  Mtolua_new((vec4f)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec4f");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec4f_new00_local
static int tolua_luamirage_vec4f_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec4f",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   vec4f* tolua_ret = (vec4f*)  Mtolua_new((vec4f)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec4f_new01
static int tolua_luamirage_vec4f_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec4f",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  float Z = ((float)  tolua_tonumber(tolua_S,4,0));
  float W = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   vec4f* tolua_ret = (vec4f*)  Mtolua_new((vec4f)(X,Y,Z,W));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec4f");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luamirage_vec4f_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vec4f */
#ifndef TOLUA_DISABLE_tolua_luamirage_vec4f_new01_local
static int tolua_luamirage_vec4f_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec4f",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  float Z = ((float)  tolua_tonumber(tolua_S,4,0));
  float W = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   vec4f* tolua_ret = (vec4f*)  Mtolua_new((vec4f)(X,Y,Z,W));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_luamirage_vec4f_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _11 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__11
static int tolua_get_matrix4f__11(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_11'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_11);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _11 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__11
static int tolua_set_matrix4f__11(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_11'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_11 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _12 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__12
static int tolua_get_matrix4f__12(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_12'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_12);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _12 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__12
static int tolua_set_matrix4f__12(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_12'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_12 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _13 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__13
static int tolua_get_matrix4f__13(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_13'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_13);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _13 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__13
static int tolua_set_matrix4f__13(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_13'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_13 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _14 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__14
static int tolua_get_matrix4f__14(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_14'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_14);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _14 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__14
static int tolua_set_matrix4f__14(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_14'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_14 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _21 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__21
static int tolua_get_matrix4f__21(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_21'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_21);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _21 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__21
static int tolua_set_matrix4f__21(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_21'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_21 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _22 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__22
static int tolua_get_matrix4f__22(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_22'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_22);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _22 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__22
static int tolua_set_matrix4f__22(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_22'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_22 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _23 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__23
static int tolua_get_matrix4f__23(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_23'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_23);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _23 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__23
static int tolua_set_matrix4f__23(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_23'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_23 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _24 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__24
static int tolua_get_matrix4f__24(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_24'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_24);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _24 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__24
static int tolua_set_matrix4f__24(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_24'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_24 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _31 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__31
static int tolua_get_matrix4f__31(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_31'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_31);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _31 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__31
static int tolua_set_matrix4f__31(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_31'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_31 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _32 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__32
static int tolua_get_matrix4f__32(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_32'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_32);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _32 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__32
static int tolua_set_matrix4f__32(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_32'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_32 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _33 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__33
static int tolua_get_matrix4f__33(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_33'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_33);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _33 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__33
static int tolua_set_matrix4f__33(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_33'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_33 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _34 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__34
static int tolua_get_matrix4f__34(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_34'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_34);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _34 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__34
static int tolua_set_matrix4f__34(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_34'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_34 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _41 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__41
static int tolua_get_matrix4f__41(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_41'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_41);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _41 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__41
static int tolua_set_matrix4f__41(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_41'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_41 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _42 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__42
static int tolua_get_matrix4f__42(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_42'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_42);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _42 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__42
static int tolua_set_matrix4f__42(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_42'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_42 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _43 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__43
static int tolua_get_matrix4f__43(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_43'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_43);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _43 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__43
static int tolua_set_matrix4f__43(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_43'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_43 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _44 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_matrix4f__44
static int tolua_get_matrix4f__44(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_44'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_44);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _44 of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_matrix4f__44
static int tolua_set_matrix4f__44(lua_State* tolua_S)
{
  matrix4f* self = (matrix4f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_44'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_44 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _array of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_get_luamirage_matrix4f__array
static int tolua_get_luamirage_matrix4f__array(lua_State* tolua_S)
{
 int tolua_index;
  matrix4f* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (matrix4f*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=16)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->_array[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _array of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_set_luamirage_matrix4f__array
static int tolua_set_luamirage_matrix4f__array(lua_State* tolua_S)
{
 int tolua_index;
  matrix4f* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (matrix4f*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=16)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->_array[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_luamirage_matrix4f_new00
static int tolua_luamirage_matrix4f_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"matrix4f",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   matrix4f* tolua_ret = (matrix4f*)  Mtolua_new((matrix4f)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"matrix4f");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  matrix4f */
#ifndef TOLUA_DISABLE_tolua_luamirage_matrix4f_new00_local
static int tolua_luamirage_matrix4f_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"matrix4f",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   matrix4f* tolua_ret = (matrix4f*)  Mtolua_new((matrix4f)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"matrix4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_luamirage_GameComponent_draw00
static int tolua_luamirage_GameComponent_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_luamirage_GameComponent_update00
static int tolua_luamirage_GameComponent_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onKeyPressed of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_luamirage_GameComponent_onKeyPressed00
static int tolua_luamirage_GameComponent_onKeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int tolua_var_2 = ((int)  tolua_tonumber(tolua_S,3,0));
  int tolua_var_3 = ((int)  tolua_tonumber(tolua_S,4,0));
  bool tolua_var_4 = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onKeyPressed'", NULL);
#endif
  {
   self->onKeyPressed(tolua_var_1,tolua_var_2,tolua_var_3,tolua_var_4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadScript of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_luamirage_GameComponent_loadScript00
static int tolua_luamirage_GameComponent_loadScript00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameComponent",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
  std::string path = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadScript'", NULL);
#endif
  {
   self->loadScript(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadScript'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: translation of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_get_GameComponent_translation
static int tolua_get_GameComponent_translation(lua_State* tolua_S)
{
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'translation'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->translation,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: translation of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_set_GameComponent_translation
static int tolua_set_GameComponent_translation(lua_State* tolua_S)
{
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'translation'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->translation = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: translationPostRotation of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_get_GameComponent_translationPostRotation
static int tolua_get_GameComponent_translationPostRotation(lua_State* tolua_S)
{
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'translationPostRotation'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->translationPostRotation,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: translationPostRotation of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_set_GameComponent_translationPostRotation
static int tolua_set_GameComponent_translationPostRotation(lua_State* tolua_S)
{
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'translationPostRotation'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->translationPostRotation = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_get_GameComponent_rotation
static int tolua_get_GameComponent_rotation(lua_State* tolua_S)
{
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rotation,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_set_GameComponent_rotation
static int tolua_set_GameComponent_rotation(lua_State* tolua_S)
{
  GameComponent* self = (GameComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rotation = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  Camera */
#ifndef TOLUA_DISABLE_tolua_get_Camera_rotation
static int tolua_get_Camera_rotation(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rotation,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  Camera */
#ifndef TOLUA_DISABLE_tolua_set_Camera_rotation
static int tolua_set_Camera_rotation(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rotation = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  Camera */
#ifndef TOLUA_DISABLE_tolua_get_Camera_position
static int tolua_get_Camera_position(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->position,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  Camera */
#ifndef TOLUA_DISABLE_tolua_set_Camera_position
static int tolua_set_Camera_position(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->position = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useAnimation of class  Camera */
#ifndef TOLUA_DISABLE_tolua_get_Camera_useAnimation
static int tolua_get_Camera_useAnimation(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useAnimation'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->useAnimation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useAnimation of class  Camera */
#ifndef TOLUA_DISABLE_tolua_set_Camera_useAnimation
static int tolua_set_Camera_useAnimation(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useAnimation'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->useAnimation = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_new00
static int tolua_luamirage_Camera_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Camera* tolua_ret = (Camera*)  Mtolua_new((Camera)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_new00_local
static int tolua_luamirage_Camera_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Camera* tolua_ret = (Camera*)  Mtolua_new((Camera)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_update00
static int tolua_luamirage_Camera_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_draw00
static int tolua_luamirage_Camera_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onKeyPressed of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_onKeyPressed00
static int tolua_luamirage_Camera_onKeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
  int mouseX = ((int)  tolua_tonumber(tolua_S,3,0));
  int mouseY = ((int)  tolua_tonumber(tolua_S,4,0));
  bool special = ((bool)  tolua_toboolean(tolua_S,5,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onKeyPressed'", NULL);
#endif
  {
   self->onKeyPressed(key,mouseX,mouseY,special);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onMouseMoved of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_onMouseMoved00
static int tolua_luamirage_Camera_onMouseMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  bool buttonPressed = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onMouseMoved'", NULL);
#endif
  {
   self->onMouseMoved(x,y,buttonPressed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onMouseMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onMousePressed of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_onMousePressed00
static int tolua_luamirage_Camera_onMousePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
  int state = ((int)  tolua_tonumber(tolua_S,3,0));
  int x = ((int)  tolua_tonumber(tolua_S,4,0));
  int y = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onMousePressed'", NULL);
#endif
  {
   self->onMousePressed(button,state,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onMousePressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadScript of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_loadScript00
static int tolua_luamirage_Camera_loadScript00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  std::string path = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadScript'", NULL);
#endif
  {
   self->loadScript(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadScript'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_luamirage_Camera_getViewMatrix00
static int tolua_luamirage_Camera_getViewMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewMatrix'", NULL);
#endif
  {
   matrix4f tolua_ret = (matrix4f)  self->getViewMatrix();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((matrix4f)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"matrix4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(matrix4f));
     tolua_pushusertype(tolua_S,tolua_obj,"matrix4f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_update00
static int tolua_luamirage_Model_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Model* self = (Model*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_draw00
static int tolua_luamirage_Model_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Model* self = (Model*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFromFile of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_loadFromFile00
static int tolua_luamirage_Model_loadFromFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GLuint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Model* self = (Model*)  tolua_tousertype(tolua_S,1,0);
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  GLuint mode = *((GLuint*)  tolua_tousertype(tolua_S,3,0));
  bool unitize = ((bool)  tolua_toboolean(tolua_S,4,true));
  bool force = ((bool)  tolua_toboolean(tolua_S,5,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadFromFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadFromFile(fileName,mode,unitize,force);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFromFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadTexture of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_loadTexture00
static int tolua_luamirage_Model_loadTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Model* self = (Model*)  tolua_tousertype(tolua_S,1,0);
  char* fileName = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadTexture'", NULL);
#endif
  {
   self->loadTexture(fileName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadScript of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_loadScript00
static int tolua_luamirage_Model_loadScript00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Model* self = (Model*)  tolua_tousertype(tolua_S,1,0);
  std::string path = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadScript'", NULL);
#endif
  {
   self->loadScript(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadScript'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_new00
static int tolua_luamirage_Model_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Game",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* game = ((Game*)  tolua_tousertype(tolua_S,2,0));
  {
   Model* tolua_ret = (Model*)  Mtolua_new((Model)(game));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Model");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_new00_local
static int tolua_luamirage_Model_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Model",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Game",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* game = ((Game*)  tolua_tousertype(tolua_S,2,0));
  {
   Model* tolua_ret = (Model*)  Mtolua_new((Model)(game));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Model");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: runGame of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_runGame00
static int tolua_luamirage_Game_runGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'runGame'", NULL);
#endif
  {
   self->runGame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onNormalKeyPressed of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onNormalKeyPressed00
static int tolua_luamirage_Game_onNormalKeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
  unsigned char key = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onNormalKeyPressed'", NULL);
#endif
  {
   self->onNormalKeyPressed(key,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onNormalKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onResolutionChanged of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onResolutionChanged00
static int tolua_luamirage_Game_onResolutionChanged00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onResolutionChanged'", NULL);
#endif
  {
   self->onResolutionChanged(w,h);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onResolutionChanged'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onSpecialKeyPressed of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onSpecialKeyPressed00
static int tolua_luamirage_Game_onSpecialKeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onSpecialKeyPressed'", NULL);
#endif
  {
   self->onSpecialKeyPressed(key,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onSpecialKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onMouseMoved of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onMouseMoved00
static int tolua_luamirage_Game_onMouseMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onMouseMoved'", NULL);
#endif
  {
   self->onMouseMoved(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onMouseMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onMousePressed of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onMousePressed00
static int tolua_luamirage_Game_onMousePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
  int state = ((int)  tolua_tonumber(tolua_S,3,0));
  int x = ((int)  tolua_tonumber(tolua_S,4,0));
  int y = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onMousePressed'", NULL);
#endif
  {
   self->onMousePressed(button,state,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onMousePressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onMenuEntrySelected of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onMenuEntrySelected00
static int tolua_luamirage_Game_onMenuEntrySelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onMenuEntrySelected'", NULL);
#endif
  {
   self->onMenuEntrySelected(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onMenuEntrySelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onExit of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_onExit00
static int tolua_luamirage_Game_onExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onExit'", NULL);
#endif
  {
   self->onExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateGame of class  Game */
#ifndef TOLUA_DISABLE_tolua_luamirage_Game_updateGame00
static int tolua_luamirage_Game_updateGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Game",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateGame'", NULL);
#endif
  {
   self->updateGame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: screenHeight of class  Game */
#ifndef TOLUA_DISABLE_tolua_get_Game_screenHeight
static int tolua_get_Game_screenHeight(lua_State* tolua_S)
{
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->screenHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: screenHeight of class  Game */
#ifndef TOLUA_DISABLE_tolua_set_Game_screenHeight
static int tolua_set_Game_screenHeight(lua_State* tolua_S)
{
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->screenHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: screenWidth of class  Game */
#ifndef TOLUA_DISABLE_tolua_get_Game_screenWidth
static int tolua_get_Game_screenWidth(lua_State* tolua_S)
{
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->screenWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: screenWidth of class  Game */
#ifndef TOLUA_DISABLE_tolua_set_Game_screenWidth
static int tolua_set_Game_screenWidth(lua_State* tolua_S)
{
  Game* self = (Game*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->screenWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_luamirage_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"vec3f","vec3f","",tolua_collect_vec3f);
  #else
  tolua_cclass(tolua_S,"vec3f","vec3f","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"vec3f");
   tolua_variable(tolua_S,"x",tolua_get_vec3f_x,tolua_set_vec3f_x);
   tolua_variable(tolua_S,"y",tolua_get_vec3f_y,tolua_set_vec3f_y);
   tolua_variable(tolua_S,"z",tolua_get_vec3f_z,tolua_set_vec3f_z);
   tolua_function(tolua_S,"new",tolua_luamirage_vec3f_new00);
   tolua_function(tolua_S,"new_local",tolua_luamirage_vec3f_new00_local);
   tolua_function(tolua_S,".call",tolua_luamirage_vec3f_new00_local);
   tolua_function(tolua_S,"new",tolua_luamirage_vec3f_new01);
   tolua_function(tolua_S,"new_local",tolua_luamirage_vec3f_new01_local);
   tolua_function(tolua_S,".call",tolua_luamirage_vec3f_new01_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"vec4f","vec4f","",tolua_collect_vec4f);
  #else
  tolua_cclass(tolua_S,"vec4f","vec4f","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"vec4f");
   tolua_variable(tolua_S,"x",tolua_get_vec4f_x,tolua_set_vec4f_x);
   tolua_variable(tolua_S,"y",tolua_get_vec4f_y,tolua_set_vec4f_y);
   tolua_variable(tolua_S,"z",tolua_get_vec4f_z,tolua_set_vec4f_z);
   tolua_variable(tolua_S,"w",tolua_get_vec4f_w,tolua_set_vec4f_w);
   tolua_function(tolua_S,"new",tolua_luamirage_vec4f_new00);
   tolua_function(tolua_S,"new_local",tolua_luamirage_vec4f_new00_local);
   tolua_function(tolua_S,".call",tolua_luamirage_vec4f_new00_local);
   tolua_function(tolua_S,"new",tolua_luamirage_vec4f_new01);
   tolua_function(tolua_S,"new_local",tolua_luamirage_vec4f_new01_local);
   tolua_function(tolua_S,".call",tolua_luamirage_vec4f_new01_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"matrix4f","matrix4f","",tolua_collect_matrix4f);
  #else
  tolua_cclass(tolua_S,"matrix4f","matrix4f","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"matrix4f");
   tolua_variable(tolua_S,"_11",tolua_get_matrix4f__11,tolua_set_matrix4f__11);
   tolua_variable(tolua_S,"_12",tolua_get_matrix4f__12,tolua_set_matrix4f__12);
   tolua_variable(tolua_S,"_13",tolua_get_matrix4f__13,tolua_set_matrix4f__13);
   tolua_variable(tolua_S,"_14",tolua_get_matrix4f__14,tolua_set_matrix4f__14);
   tolua_variable(tolua_S,"_21",tolua_get_matrix4f__21,tolua_set_matrix4f__21);
   tolua_variable(tolua_S,"_22",tolua_get_matrix4f__22,tolua_set_matrix4f__22);
   tolua_variable(tolua_S,"_23",tolua_get_matrix4f__23,tolua_set_matrix4f__23);
   tolua_variable(tolua_S,"_24",tolua_get_matrix4f__24,tolua_set_matrix4f__24);
   tolua_variable(tolua_S,"_31",tolua_get_matrix4f__31,tolua_set_matrix4f__31);
   tolua_variable(tolua_S,"_32",tolua_get_matrix4f__32,tolua_set_matrix4f__32);
   tolua_variable(tolua_S,"_33",tolua_get_matrix4f__33,tolua_set_matrix4f__33);
   tolua_variable(tolua_S,"_34",tolua_get_matrix4f__34,tolua_set_matrix4f__34);
   tolua_variable(tolua_S,"_41",tolua_get_matrix4f__41,tolua_set_matrix4f__41);
   tolua_variable(tolua_S,"_42",tolua_get_matrix4f__42,tolua_set_matrix4f__42);
   tolua_variable(tolua_S,"_43",tolua_get_matrix4f__43,tolua_set_matrix4f__43);
   tolua_variable(tolua_S,"_44",tolua_get_matrix4f__44,tolua_set_matrix4f__44);
   tolua_array(tolua_S,"_array",tolua_get_luamirage_matrix4f__array,tolua_set_luamirage_matrix4f__array);
   tolua_function(tolua_S,"new",tolua_luamirage_matrix4f_new00);
   tolua_function(tolua_S,"new_local",tolua_luamirage_matrix4f_new00_local);
   tolua_function(tolua_S,".call",tolua_luamirage_matrix4f_new00_local);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"GameComponent","GameComponent","",NULL);
  tolua_beginmodule(tolua_S,"GameComponent");
   tolua_function(tolua_S,"draw",tolua_luamirage_GameComponent_draw00);
   tolua_function(tolua_S,"update",tolua_luamirage_GameComponent_update00);
   tolua_function(tolua_S,"onKeyPressed",tolua_luamirage_GameComponent_onKeyPressed00);
   tolua_function(tolua_S,"loadScript",tolua_luamirage_GameComponent_loadScript00);
   tolua_variable(tolua_S,"translation",tolua_get_GameComponent_translation,tolua_set_GameComponent_translation);
   tolua_variable(tolua_S,"translationPostRotation",tolua_get_GameComponent_translationPostRotation,tolua_set_GameComponent_translationPostRotation);
   tolua_variable(tolua_S,"rotation",tolua_get_GameComponent_rotation,tolua_set_GameComponent_rotation);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LuaScript","LuaScript","",NULL);
  tolua_beginmodule(tolua_S,"LuaScript");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Camera","Camera","",tolua_collect_Camera);
  #else
  tolua_cclass(tolua_S,"Camera","Camera","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Camera");
   tolua_variable(tolua_S,"rotation",tolua_get_Camera_rotation,tolua_set_Camera_rotation);
   tolua_variable(tolua_S,"position",tolua_get_Camera_position,tolua_set_Camera_position);
   tolua_variable(tolua_S,"useAnimation",tolua_get_Camera_useAnimation,tolua_set_Camera_useAnimation);
   tolua_function(tolua_S,"new",tolua_luamirage_Camera_new00);
   tolua_function(tolua_S,"new_local",tolua_luamirage_Camera_new00_local);
   tolua_function(tolua_S,".call",tolua_luamirage_Camera_new00_local);
   tolua_function(tolua_S,"update",tolua_luamirage_Camera_update00);
   tolua_function(tolua_S,"draw",tolua_luamirage_Camera_draw00);
   tolua_function(tolua_S,"onKeyPressed",tolua_luamirage_Camera_onKeyPressed00);
   tolua_function(tolua_S,"onMouseMoved",tolua_luamirage_Camera_onMouseMoved00);
   tolua_function(tolua_S,"onMousePressed",tolua_luamirage_Camera_onMousePressed00);
   tolua_function(tolua_S,"loadScript",tolua_luamirage_Camera_loadScript00);
   tolua_function(tolua_S,"getViewMatrix",tolua_luamirage_Camera_getViewMatrix00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Model","Model","GameComponent",tolua_collect_Model);
  #else
  tolua_cclass(tolua_S,"Model","Model","GameComponent",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Model");
   tolua_function(tolua_S,"update",tolua_luamirage_Model_update00);
   tolua_function(tolua_S,"draw",tolua_luamirage_Model_draw00);
   tolua_function(tolua_S,"loadFromFile",tolua_luamirage_Model_loadFromFile00);
   tolua_function(tolua_S,"loadTexture",tolua_luamirage_Model_loadTexture00);
   tolua_function(tolua_S,"loadScript",tolua_luamirage_Model_loadScript00);
   tolua_function(tolua_S,"new",tolua_luamirage_Model_new00);
   tolua_function(tolua_S,"new_local",tolua_luamirage_Model_new00_local);
   tolua_function(tolua_S,".call",tolua_luamirage_Model_new00_local);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Game","Game","",NULL);
  tolua_beginmodule(tolua_S,"Game");
   tolua_function(tolua_S,"runGame",tolua_luamirage_Game_runGame00);
   tolua_function(tolua_S,"onNormalKeyPressed",tolua_luamirage_Game_onNormalKeyPressed00);
   tolua_function(tolua_S,"onResolutionChanged",tolua_luamirage_Game_onResolutionChanged00);
   tolua_function(tolua_S,"onSpecialKeyPressed",tolua_luamirage_Game_onSpecialKeyPressed00);
   tolua_function(tolua_S,"onMouseMoved",tolua_luamirage_Game_onMouseMoved00);
   tolua_function(tolua_S,"onMousePressed",tolua_luamirage_Game_onMousePressed00);
   tolua_function(tolua_S,"onMenuEntrySelected",tolua_luamirage_Game_onMenuEntrySelected00);
   tolua_function(tolua_S,"onExit",tolua_luamirage_Game_onExit00);
   tolua_function(tolua_S,"updateGame",tolua_luamirage_Game_updateGame00);
   tolua_variable(tolua_S,"screenHeight",tolua_get_Game_screenHeight,tolua_set_Game_screenHeight);
   tolua_variable(tolua_S,"screenWidth",tolua_get_Game_screenWidth,tolua_set_Game_screenWidth);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luamirage (lua_State* tolua_S) {
 return tolua_luamirage_open(tolua_S);
};
#endif

