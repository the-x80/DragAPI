#include "Application.h"

namespace DragAPI {
	Application* Application::s_Application = nullptr;


	Application::Application() :
		m_AppName(L""),
		m_EventDispatcher(nullptr),
		m_Running(true)
	{
		Application::s_Application = this;
		this->m_EventDispatcher = new DragAPI::Events::EventDispatcher();
		this->m_EventDispatcher->RegisterIEventListener(this);
		DragAPI::Events::ApplicationStartEvent* e = new DragAPI::Events::ApplicationStartEvent();
		this->m_EventDispatcher->PushEvent(e);
	}
	Application::~Application() {
		delete this->m_EventDispatcher;
	}

	void Application::Quit(int nExitCode) {
		//Create a application request quit event
		//Dispatch it
		//Set the running state of the application to false
		//return out of the function.
		DragAPI::Events::ApplicationRequestQuitEvent* e = new DragAPI::Events::ApplicationRequestQuitEvent(nExitCode);
		Application::s_Application->m_EventDispatcher->PushEvent(e);

		Application::s_Application->m_Running = false;
	}
}