#pragma once
#ifndef DRAG_API_DEBUG_LOGGING_H
#define DRAG_API_DEBUG_LOGGING_H
#include <string>

namespace DragAPI {
	namespace Debug {
		enum class LogLevel {
			Info,
			Wanr,
			Error
		};
		void Log(LogLevel level, const char* format, ...);
		void Log(LogLevel level, bool performStackTrace, const char* format, ...);
	}
}



#endif