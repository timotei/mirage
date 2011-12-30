/*
** Lua binding: luamirage
** Generated automatically by tolua++-1.0.92 on 12/30/11 13:29:14.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luamirage_open (lua_State* tolua_S);

#include "LuaMirage.hpp"
#include "../Components/Model.hpp"
#include "../Components/GameComponent.hpp"
#include "../Components/Camera.hpp"
#include "nvVector.h"
#include "nvMath.h"
using namespace nv;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_vec4f (lua_State* tolua_S)
{
 vec4f* self = (vec4f*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_GameComponent (lua_State* tolua_S)
{
 GameComponent* self = (GameComponent*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"vec4f");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Model");
 tolua_usertype(tolua_S,"vec3f");
 tolua_usertype(tolua_S,"GameComponent");
 tolua_usertype(tolua_S,"GLuint");
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

/* method: delete of class  GameComponent */
#ifndef TOLUA_DISABLE_tolua_luamirage_GameComponent_delete00
static int tolua_luamirage_GameComponent_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
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

/* get function: target of class  Camera */
#ifndef TOLUA_DISABLE_tolua_get_Camera_target
static int tolua_get_Camera_target(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->target,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: target of class  Camera */
#ifndef TOLUA_DISABLE_tolua_set_Camera_target
static int tolua_set_Camera_target(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->target = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: up of class  Camera */
#ifndef TOLUA_DISABLE_tolua_get_Camera_up
static int tolua_get_Camera_up(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'up'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->up,"vec3f");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: up of class  Camera */
#ifndef TOLUA_DISABLE_tolua_set_Camera_up
static int tolua_set_Camera_up(lua_State* tolua_S)
{
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'up'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vec3f",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->up = *((vec3f*)  tolua_tousertype(tolua_S,2,0))
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
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Model* tolua_ret = (Model*)  Mtolua_new((Model)());
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
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Model* tolua_ret = (Model*)  Mtolua_new((Model)());
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

/* method: delete of class  Model */
#ifndef TOLUA_DISABLE_tolua_luamirage_Model_delete00
static int tolua_luamirage_Model_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
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
  tolua_cclass(tolua_S,"GameComponent","GameComponent","",tolua_collect_GameComponent);
  #else
  tolua_cclass(tolua_S,"GameComponent","GameComponent","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GameComponent");
   tolua_function(tolua_S,"draw",tolua_luamirage_GameComponent_draw00);
   tolua_function(tolua_S,"update",tolua_luamirage_GameComponent_update00);
   tolua_function(tolua_S,"onKeyPressed",tolua_luamirage_GameComponent_onKeyPressed00);
   tolua_function(tolua_S,"loadScript",tolua_luamirage_GameComponent_loadScript00);
   tolua_function(tolua_S,"delete",tolua_luamirage_GameComponent_delete00);
   tolua_variable(tolua_S,"translation",tolua_get_GameComponent_translation,tolua_set_GameComponent_translation);
   tolua_variable(tolua_S,"rotation",tolua_get_GameComponent_rotation,tolua_set_GameComponent_rotation);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Camera","Camera","GameComponent",tolua_collect_Camera);
  #else
  tolua_cclass(tolua_S,"Camera","Camera","GameComponent",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Camera");
   tolua_variable(tolua_S,"position",tolua_get_Camera_position,tolua_set_Camera_position);
   tolua_variable(tolua_S,"target",tolua_get_Camera_target,tolua_set_Camera_target);
   tolua_variable(tolua_S,"up",tolua_get_Camera_up,tolua_set_Camera_up);
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
   tolua_function(tolua_S,"delete",tolua_luamirage_Model_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luamirage (lua_State* tolua_S) {
 return tolua_luamirage_open(tolua_S);
};
#endif

