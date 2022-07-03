#include <Windows.h>
#include "EventSystem.h"
#include "../Debugging/Debug.h"

DragAPI::Events::EventDispatcher::EventDispatcher()
{
	
}

DragAPI::Events::EventDispatcher::~EventDispatcher()
{
	
}

void DragAPI::Events::EventDispatcher::PushEvent(Event* e)
{
	//_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "Pushed %s to the event stack.\n", e->GetName());
	this->m_QueuedEvents.push(e);
}

void DragAPI::Events::EventDispatcher::Dispatch()
{
	if (this->m_QueuedEvents.size() == 0) return;
	DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "EventDispatcher @ %p :: Dispatching %d number of events to %d number of listeners.\n", this, this->m_QueuedEvents.size(), this->m_EventListeners.size());
	for (int i = 0; i < this->m_QueuedEvents.size(); i++) {
		this->DispatchEvent(this->m_QueuedEvents.front());
		this->m_QueuedEvents.pop();
	}
}

void DragAPI::Events::EventDispatcher::RegisterIEventListener(IEventListener* l)
{
	Listener l_Listener;
	l_Listener.m_Listener = l;
	this->m_EventListeners.push_back(l_Listener);
}

void DragAPI::Events::EventDispatcher::UnregisterIEventListener(IEventListener* l)
{
}

void DragAPI::Events::EventDispatcher::DispatchEvent(Event* e)
{
	for (int i = 0; i < this->m_EventListeners.size(); i++) {
		//_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "Dispatching an event of type %s to a IEventListener @ %p\n", e->GetName(), this->m_EventListeners[i].m_Listener);
		this->m_EventListeners[i].m_Listener->OnEvent(e);
		//_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "Event of type %s has been handeled by IEventListener @ %p\n", e->GetName(), this->m_EventListeners[i].m_Listener);
		delete e;
	}
}
