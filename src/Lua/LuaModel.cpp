#include "LuaModel.hpp"

#include "../Components/Model.hpp"
#include "LuaUtils.hpp"

LuaModel::LuaModel(lua_State *L)
{
	_model = (Model*) lua_touserdata(L, 1);
}

LuaModel::~LuaModel()
{

}

int LuaModel::setRotation(lua_State *L)
{
	_model->rotation = lua_checkvector3(L, 1);

	return 0;
}

int LuaModel::getRotation(lua_State *L)
{
	lua_pushvector3(L, _model->rotation);
	return 1;
}