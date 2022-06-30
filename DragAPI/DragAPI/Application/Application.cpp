#include "Application.h"

namespace DragAPI {
	Application::Application() :
		m_AppName(L""),
		m_EventDispatcher(nullptr),
		m_Running(true)
	{
		this->m_EventDispatcher = new DragAPI::Events::EventDispatcher();
		this->m_EventDispatcher->RegisterIEventListener(this);
		DragAPI::Events::ApplicationStartEvent* e = new DragAPI::Events::ApplicationStartEvent();
		this->m_EventDispatcher->PushEvent(e);
	}
	Application::~Application() {
		delete this->m_EventDispatcher;
	}
}