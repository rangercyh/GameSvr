// GameSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include "LuaFuns.h"
#include "Common.h"
#include "ServerObj.h"

using namespace std;

// 注册C写的Lua模块
int lua_openScriptFuns(lua_State *L)
{
	luaL_register(L, "scriptfuns", ScriptFuns);
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//_LARGE_INTEGER time_start = START_TIME();

	//lua_State * L = lua_open();
	//luaL_openlibs(L);
	//lua_openScriptFuns(L);

	// 1、加载并运行整个文件
	//cout << "按任意键重新加载和运行脚本（按‘.’结束程序）：" << endl;
	//while (_getch() != '.')
	//{
	//	luaL_dofile(L, "C:\\Users\\D15411\\Documents\\Visual Studio 2013\\Projects\\ConsoleApplication1\\Debug\\luascript.lua");
	//};

	// 2、加载整个文件然后调用指定函数
	//luaL_dofile(L, "C:\\Users\\D15411\\Documents\\Visual Studio 2013\\Projects\\ConsoleApplication1\\Debug\\luascript.lua");
	//lua_getglobal(L, "haha");
	//if (lua_pcall(L, 0, 1, 0) != 0)
	//{
	//	cout << "error running function \"haha\": " << lua_tostring(L, -1) << endl;
	//}
	//cout << lua_tointeger(L, -1) << endl;
	//lua_pop(L, 1);

	int nRetCode = 0;
	ServerObj& g_ServerObj = ServerObj::getInstance(nRetCode);
	if (nRetCode != enumServerStateOK)
	{
		g_ServerObj.UnInitialize();
		return 1;
	}

	g_ServerObj.ThreadFunction();

	/*lua_close(L);*/
	/*PRINT_TIME(time_start);*/
	return 0;
}

