#include "stdafx.h"
#include "LuaFuns.h"

using namespace std;

static int LuaTest(lua_State* L)
{
	int e = 0;
	if (lua_gettop(L) >= 1)
	{
		e = luaL_checkint(L, 1);
	}
	switch (e)
	{
	case 1:
		lua_pushinteger(L, e * 10);
		break;
	case 2:
		lua_pushstring(L, "lalalalademaxiya");
		break;
	case 3:
		lua_newtable(L);
		lua_pushinteger(L, 1);
		lua_pushstring(L, "aaaa");
		lua_settable(L, -3);
		lua_pushinteger(L, 5);
		lua_pushinteger(L, 1000);
		lua_settable(L, -3);
		break;
	default:
		lua_pushstring(L, "what the fuck!");
		break;
	}

	return 1;
}


const struct luaL_Reg ScriptFuns[] = {
	{ "Test", LuaTest },
	{ NULL, NULL }
};



