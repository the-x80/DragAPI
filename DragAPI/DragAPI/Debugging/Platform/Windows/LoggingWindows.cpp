#include "../../../DragAPI.Core.h"

#ifdef _WIN32
#include <cstdio>
#include <cstdarg>
#include <vector>

#include "../../Debug.h"
#include "../../../Diagnostics/Platform/Windows/StackTraceWindows.h"

#include "../../../Data Types/DateTime.h"

#include <Windows.h>
#include <DbgHelp.h>
#pragma comment(lib, "DbgHelp.lib")

#ifdef _DEBUG
void DragAPI::Debug::Log(LogLevel level, const char* format, ...) {
	::DragAPI::Diagnostics::StackTrace* l_Stack = ::DragAPI::Diagnostics::StackTrace::Create(1);
	int l_ReportLevel = 0;

	switch (level) {
	case LogLevel::Info:
		l_ReportLevel = _CRT_WARN;
		break;
	case LogLevel::Wanr:
		l_ReportLevel = _CRT_WARN;
		break;
	case LogLevel::Error:
		l_ReportLevel = _CRT_ERROR;
	}

	
	
	va_list args;
	va_start(args, format);
	int size = vsnprintf(NULL, 0, format, args);
	char* output = new char[size + 1];
	vsprintf_s(output, size+1, format, args);
	_CrtDbgReport(l_ReportLevel, NULL, NULL, NULL, output);
	va_end(args);
	delete l_Stack;
	delete[] output;
}
#else
void DragAPI::Debug::Log(LogLevel level, const char* format, ...) { return; }
#endif
#endif