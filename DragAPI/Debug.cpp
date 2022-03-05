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


namespace DragAPI {
	namespace Debug {
		DebugOutputMode CurrentDebugOutputMode = DebugOutputMode::DebugOutput;

		class DebugWindow : public BaseWindow<DebugWindow> {
		public:
			DebugWindow() {

			}
			DebugWindow(DebugWindow& other) {

			}
			DebugWindow(DebugWindow&& other) noexcept {

			}
			~DebugWindow() {

			}
		};
	}
}



void DragAPI::Debug::SetDebugOutput(DebugOutputMode mode)
{
	if (mode == CurrentDebugOutputMode) {//No change has been made therefore just exit.
		return;
	}

	CurrentDebugOutputMode = mode;

	switch (mode) {
	case DebugOutputMode::None:
		break;
	case DebugOutputMode::DebugOutput:
		break;
	case DebugOutputMode::ConsoleOutput:
	{
		//Perform a check to see if the console is already opened.
		if (Console::IsConsoleOpen() == true) {
			break;
		}

		//TODO: Implement error checking and exception handling.
		Console::Allocate();
	}
		break;
	case DebugOutputMode::WindowOutput:

		break;
	}
}

void DragAPI::Debug::BeginDebugGroup()
{
}

void DragAPI::Debug::EndDebugGroup()
{
}

void DragAPI::Debug::Write(const char* msg)
{
	if (isDebugBuild == false) {
		return;
	}

	if (IsDebuggerPresent() == false) {
		return;
	}


	DateTime messageTime = DateTime::Now();
	DragAPI::Diagnostics::StackTrace stackTrace = DragAPI::Diagnostics::StackTrace(1);


	char* cstr_DebugMessage = new char[2048];
}

void DragAPI::Debug::WriteLine(const char* msg)
{
	if (isDebugBuild == false) {
		return;
	}

	if (IsDebuggerPresent() == false) {
		return;
	}
}

void DragAPI::Debug::Write(const wchar_t* msg)
{
}

void DragAPI::Debug::WriteLine(const wchar_t* msg)
{
}

void DragAPI::Debug::Write(const char* msg, ...)
{
}

void DragAPI::Debug::WriteLine(const char* msg, ...)
{
}

void DragAPI::Debug::Write(const wchar_t* msg, ...)
{
}

void DragAPI::Debug::WriteLine(const wchar_t* msg, ...)
{
}

void DragAPI::Debug::WriteException(::DragAPI::Exceptions::Exception& e)
{

}
