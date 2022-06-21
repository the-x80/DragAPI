#include <stdio.h>
#include <iostream>
#include <string>
#include <functional>
#include <array>
#include <vector>

#include <Windows.h>
#include <DbgHelp.h>

#pragma comment(lib, "DbgHelp.lib")

#include "Graphics/Window.h"
#include "Console/Console.h"

#include "Debug.h"
#include "Diagnostics/Diagnostics.h"
#include "DateTime.h"

#define DEBUG_STRING_BUFFER_SIZE 1024*128


namespace DragAPI {
	namespace Debug {
		DebugOutputMode CurrentDebugOutputMode = DebugOutputMode::DebugOutput;

		Debugger::Debugger()
		{
		}
		Debugger::~Debugger()
		{
		}
		void Debugger::KillProcessOnDetach(bool state)
		{
		}
		void Debugger::Break()
		{
		}
	}
}
