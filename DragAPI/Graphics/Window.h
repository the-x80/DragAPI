#ifndef DRAG_API_WINDOW_H
#define DRAG_API_WINDOW_H

#ifndef _WINDOWS_
#include <Windows.h>
#endif
#include "../Array/Array.h"

//TODO Set the window class to be a wrapper around OS specific window classes

namespace DragAPI {
	enum class WindowMode {
		Windowed,
		WindowedFullscreen,
		Fullscreen
	};
	class Window {
	private:
		HWND h_WindowHandle;
		MSG msg;
		RECT rect;//Will be replaced with custom rect structure.
		WindowMode mode;

		WNDCLASSEX wcex_Registered;
		Array<Window*> childWindows;

		bool b_IsCreated;
	public:
		Window();
		Window(Window* parent);

		void Create();
		void Create(HINSTANCE hInstance);
		void Show(bool value);

		HWND GetHandle() const;

		void Paint();
		void SetRect(long x, long y, long w, long h);
	};
}

#endif