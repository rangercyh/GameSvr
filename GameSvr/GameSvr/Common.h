#ifndef __COMMON__
#define __COMMON__

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <windows.h>
#include <lua.hpp>
#include <luaconf.h>
#include <conio.h>

_LARGE_INTEGER& START_TIME()
{
	static _LARGE_INTEGER time_start;
	QueryPerformanceCounter(&time_start);
	return time_start;
}

const void PRINT_TIME(_LARGE_INTEGER time_start)
{
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	_LARGE_INTEGER time_over;
	QueryPerformanceCounter(&time_over);
	std::cout << std::endl << "ºÄÊ±£º" << (time_over.QuadPart - time_start.QuadPart) / (double)f.QuadPart << "Ãë" << std::endl;
	system("pause");
}


#endif // __COMMON__