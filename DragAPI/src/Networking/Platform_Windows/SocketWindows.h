//TODO: Create a preprocessor check for the compiled platform and if not windows then exclude this from the build process

#pragma once
#ifndef DRAG_API_SOCKETS_WINDOWS_H
#define DRAG_API_SOCKETS_WINDOWS_H



#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _WS2TCPIP_H_
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#endif

#include "../../Exceptions/Exceptions.h"

namespace DragAPI {
	namespace Networking {



		class Socket {
		public:
			enum class AddressFamilyWindows : int {
				Unspecified,
				INet = 2,
				IPX = 6,
				AppleTalk = 16,
				NetBios = 17,
				INet6 = 23,
				IRDA = 26,
				Bluetooth = 32
			};
			enum class TypeWindows : int {
				Stream,
				DataGram,
				Raw,
				RDM,
				SeqPacket
			};
			enum class ProtocolWindows : int {

			};
		private:
			SOCKET m_WinSocketHandle;
		public:
			Socket();
			Socket(int af, int type, int proto);
			static Socket Create(int af, int type, int proto);
			void Close();

			void Connect(const char* address);
		};
	}
}

#endif //_WIN32
#endif