#include "Window.h"
#include "Platform\Windows\Window_win32.h"

DragAPI::UI::Window* DragAPI::UI::Window::Create(const char* pCaption, const DragAPI::rect_uint16& rClientRect)
{
#ifdef PLATFORM_WINDOWS
	return new DragAPI::UI::Window_win32();
#endif
	return nullptr;
}
