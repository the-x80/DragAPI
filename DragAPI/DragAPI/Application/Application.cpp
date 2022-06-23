#include "Application.h"

namespace DragAPI {
	Application::Application() :
		m_AppName(L""),
		m_EventDispatcher(nullptr),
		m_Running(true)
	{
		this->m_EventDispatcher = new DragAPI::Events::EventDispatcher();
		this->m_EventDispatcher->RegisterIEventListener(this);
	}
	Application::~Application() {
		delete this->m_EventDispatcher;
	}
}