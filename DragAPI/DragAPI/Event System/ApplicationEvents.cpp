#include "ApplicationEvents.h"

DragAPI::Events::ApplicationEvent::ApplicationEvent()
{
}

DragAPI::Events::ApplicationStartEvent::ApplicationStartEvent()
{
}

DragAPI::Events::ApplicationRequestQuitEvent::ApplicationRequestQuitEvent()
{
}

DragAPI::Events::ApplicationRequestQuitEvent::ApplicationRequestQuitEvent(int exitCode):
	m_ExitCode(exitCode)
{
}

DragAPI::Events::ApplicationQuitEvent::ApplicationQuitEvent()
{
}
