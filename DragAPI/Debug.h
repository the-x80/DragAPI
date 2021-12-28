#ifndef DRAG_API_DEBUG_H
#define DRAG_API_DEBUG_H
#include "Exceptions/Exceptions.h"


namespace DragAPI {
	namespace Debug {
#ifdef _DEBUG
		static bool isDebugBuild = true;
#else
		static bool isDebugBuild = false;
#endif
		inline void BeginDebugGroup();
		inline void EndDebugGroup();

		inline void Write(const char* msg);
		inline void WriteLine(const char* msg);

		inline void Write(const wchar_t* msg);
		inline void WriteLine(const wchar_t* msg);

		inline void Write(const char* msg, ...);
		inline void WriteLine(const char* msg, ...);

		inline void Write(const wchar_t* msg, ...);
		inline void WriteLine(const wchar_t* msg, ...);

		inline void WriteException(::DragAPI::Exceptions::Exception& e);
	}
}


#endif