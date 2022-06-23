#include "EventExceptions.h"

DragAPI::Events::Exceptions::EventException::EventException():
	m_Event(nullptr)
{
}

DragAPI::Events::Exceptions::EventException::EventException(DragAPI::Events::Event* event):
	m_Event(event)
{
}

DragAPI::Events::Exceptions::EventException::EventException(DragAPI::Events::Event* event, DragAPI::string msg):
	Exception::Exception(msg.c_str()),
	m_Event(event)
{
}
