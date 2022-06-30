#include "WindowEvents.h"
#include "../Graphics/Window.h"

DragAPI::Events::WindowEvent::WindowEvent():
	m_Window(nullptr)
{
}

DragAPI::Events::WindowEvent::WindowEvent(Window* wnd):
	m_Window(wnd)
{
}

DragAPI::Events::WindowEvent::~WindowEvent()
{
}

DragAPI::Events::WindowCreateEvent::WindowCreateEvent()
{
}

DragAPI::Events::WindowCreateEvent::WindowCreateEvent(Window* wnd):
	WindowEvent(wnd)
{
}

DragAPI::Events::WindowCreateEvent::~WindowCreateEvent()
{
}

DragAPI::Events::WindowCloseEvent::WindowCloseEvent()
{
}

DragAPI::Events::WindowCloseEvent::WindowCloseEvent(Window* wnd):
	WindowEvent(wnd)
{
}

DragAPI::Events::WindowCloseEvent::~WindowCloseEvent()
{
}
