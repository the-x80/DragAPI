#pragma once
#ifndef DRAG_API_APPLICATION_H
#define DRAG_API_APPLICATION_H
#include <vector>
#include <string>

#include "../Exceptions/Exceptions.h"

#include "../Event System/EventSystem.h"

namespace DragAPI {
	class Application
	{
	private:
		std::wstring m_AppName;
		
	protected:
		
		
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
	};
}
#endif