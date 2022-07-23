#pragma once
#ifdef PLATFORM_WINDOWS
#include <Windows.h>
#include "../../Window.h"

namespace DragAPI::UI {
	class Window_win32 : public Window {
	public:
		~Window_win32();
	};
}

#endif