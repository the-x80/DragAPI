#ifndef DRAG_API_WINDOW_H
#define DRAG_API_WINDOW_H

#ifndef _WINDOWS_
#include <Windows.h>
#endif
#include "Array/Array.h"

namespace DragAPI {
	enum class WindowMode {
		Windowed,
		WindowedFullscreen,
		Fullscreen
	};
	class Window {
	private:
		HWND h_WindowHandle;
		RECT rect;
		WindowMode mode;

		WNDCLASSEX wcex_Registered;
		Array<Window*> childWindows;
	public:
		Window();
		Window(Window* parent);


		void Paint();


		void SetRect(long x, long y, long w, long h);
	};
}

#endif