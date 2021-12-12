#pragma once
#ifndef  DRAG_API_WEB_H
#define DRAG_API_WEB_H

#include <vector>
#include <string>
#include <array>

#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
#endif

#include "../HTML/HTML.h"

namespace DragAPI {
	namespace Networking {
		class NetworkServer {
		private:
		protected:
		public:
			NetworkServer();
			NetworkServer(NetworkServer& other);
			NetworkServer(NetworkServer&& other);
			~NetworkServer();
		};
		class NetworkClient {
		private:
		protected:
		public:
			NetworkClient();
			NetworkClient(NetworkClient& other);
			NetworkClient(NetworkClient&& other);
			~NetworkClient();
		};

		class HTTPServer : public NetworkServer {
		private:

			//Allocated on the heap because of the size.
			DragAPI::HTML::HTMLDocument* document;
		protected:
		public:
			HTTPServer();
			HTTPServer(HTTPServer& other);
			HTTPServer(HTTPServer&& other);
			~HTTPServer();

			bool Start();
			bool Stop();

			bool Listen();
		};
		class HTTPClient : public NetworkClient {
		private:
		protected:
		public:

		};
	}
}



#endif // ! DRAG_API_WEB_H