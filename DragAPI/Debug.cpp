#include <stdio.h>
#include <Windows.h>
#include <DbgHelp.h>

#pragma comment(lib, "DbgHelp.lib")

#include "Debug.h"
#include "StackTrace.h"
#include "DateTime.h"

void DragAPI::Debug::Write(const char* msg)
{
	if (isDebugBuild == false) {
		return;
	}

	if (IsDebuggerPresent() == false) {
		return;
	}


	DateTime messageTime = DateTime();
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
