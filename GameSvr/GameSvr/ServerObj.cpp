#include "stdafx.h"
#include "ServerObj.h"
#include "Header.h"

using namespace std;

ServerObj::ServerObj() : bInited(false)
{

}


ServerObj::~ServerObj()
{
}

//ServerObj& GetServerObj()
//{
//	static ServerObj svr;
//	return svr;
//}

int ServerObj::Initialize()
{
	if (bInited)
	{
		return 1;
	}

	//lua_State * L = lua_open();
	//luaL_openlibs(L);
	//lua_openScriptFuns(L);

	bInited = true;
	return 1;
}




ServerObj& ServerObj::getInstance(int& nRetCode)
{
	static ServerObj svr;
	nRetCode = svr.Initialize();

	return svr;
}

int ServerObj::UnInitialize()
{
	/*lua_close(L);*/
	return 0;
}

void ServerObj::ThreadFunction()
{
	while (bInited)
	{
		Sleep(1);
	}
}
