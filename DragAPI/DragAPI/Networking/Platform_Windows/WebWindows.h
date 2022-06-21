#pragma once

#include "../Web.h"
#include "SocketWindows.h"

namespace DragAPI {
	namespace Networking {
		class NetworkServerWindows : public NetworkServer{

		};
		class NetworkClientWindows : public NetworkClient{
		private:
			WSADATA m_WSAData;
			Socket* m_Socket;
		public:
			NetworkClientWindows();
			NetworkClientWindows(NetworkClientWindows& other);
			NetworkClientWindows(NetworkClientWindows&& other);
			~NetworkClientWindows();
			void Startup() override;
			void Cleanup() override;

			void Connect(const char* address, unsigned short port) override;
			void Connect(AddressFamily af, const char* address, unsigned short port) override;
			void Disconnect() override;

			size_t Send(const char* data) override;
			size_t Recv(char* buffer) override;

			void QueryRecvData(int* availableBytes) override;

			Socket* GetSocket() override { return m_Socket; }
		};
	}
}