#ifndef DRAG_API_SOCKETS_H
#define DRAG_API_SOCKETS_H

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _WS2TCPIP_H_
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#endif

namespace DragAPI {
	namespace Networking {
		


		class Socket {
		public:
			enum class AddressFamily : int {

			};
			enum class Type : int {

			};
			enum class Protocol : int {

			};



		private:
			SOCKET handle;
		public:
			static Socket Create(int af, int type, int protocol);



			Socket();
		};
	}
}


#endif
