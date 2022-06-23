#include <Windows.h>
#include "EventSystem.h"
#include "../Debug.h"

DragAPI::Events::EventDispatcher::EventDispatcher()
{
	
}

DragAPI::Events::EventDispatcher::~EventDispatcher()
{
	
}

void DragAPI::Events::EventDispatcher::PushEvent(Event* e)
{
	_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "Pushed %s to the event stack.\n", e->GetName());
	this->m_QueuedEvents.push(e);
}

void DragAPI::Events::EventDispatcher::Dispatch()
{
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
		this->m_EventListeners[i].m_Listener->OnEvent(e);
	}
}
