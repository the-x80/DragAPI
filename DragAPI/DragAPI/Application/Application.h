#pragma once
#ifndef DRAG_API_APPLICATION_H
#define DRAG_API_APPLICATION_H
#include <vector>
#include <string>


#include "../Exceptions/Exceptions.h"

#include "../Event System/EventSystem.h"

namespace DragAPI {
	class Application : public DragAPI::Events::IEventListener
	{
	private:
		std::wstring m_AppName;
		
		
	protected:
		DragAPI::Events::EventDispatcher* m_EventDispatcher;
		bool m_Running;
		
	public:
		Application();
		~Application();

		/// <summary>
		/// Creates an application object
		/// Should be defined in client
		/// </summary>
		/// <returns>Application object</returns>
		static Application* CreateApplication();

		/// <summary>
		/// Posts a quit event
		/// </summary>
		/// <param name="nExitCode"></param>
		virtual void Quit(int nExitCode) = 0;

		/// <summary>
		/// Used to run the application.
		/// Must be implemented by a derrived class
		/// </summary>
		virtual void Run() = 0;


		virtual void OnEvent(DragAPI::Events::Event* e) override {
			//_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "DragAPI::Application has recieved an event of type %s\n", e->GetName());
		}
	};
}
#endif