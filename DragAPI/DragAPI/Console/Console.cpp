#ifdef _WIN32
	#include <Windows.h>
#endif

#include "../Application/Application.h"
#include "Console.h"

bool DragAPI::Console::Allocate()
{
#ifdef _WIN32
	return AllocConsole();
#else

#endif
	return false;
}

bool DragAPI::Console::IsConsoleOpen()
{
#ifdef _WIN32
	return (GetConsoleWindow() != NULL) ? true : false;
#else

#endif
	return false;
}
