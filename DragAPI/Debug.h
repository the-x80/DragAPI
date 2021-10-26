#ifndef DRAG_API_DEBUG_H
#define DRAG_API_DEBUG_H


namespace DragAPI {
	namespace Debug {
#ifdef _DEBUG
		static bool isDebugBuild = true;
#else
		static bool isDebugBuild = false;
#endif

		inline void Write(const char* msg);
		inline void WriteLine(const char* msg);
	}
}


#endif