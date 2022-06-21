#pragma once
#ifndef DRAG_API_WEB_BROWSER_H
#define DRAG_API_WEB_BROWSER_H
#include <string>
#include <vector>


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#include "../../DragAPI.h"

namespace DragAPI {
	namespace Networking {

		/// <summary>
		/// Basic web browser backend implementation.
		/// Used to explore the web witouth having to render anything.
		/// </summary>
		class WebBrowser {
		private:
			DragAPI::Networking::HTTP::HTTPClient m_HTTPClient;
			std::wstring m_CurrentURL;
			HANDLE m_ScriptThread;
		public:
			WebBrowser();
			~WebBrowser();

			void NavigateTo(std::wstring URL);
			void Refresh();

		private:
			void ExecuteScripts();

			void StartScriptThread();
			void StopScriptThread();
		};
		namespace Exceptions {

		}
	}
}
#endif