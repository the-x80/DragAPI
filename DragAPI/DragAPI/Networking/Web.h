#pragma once
#ifndef  DRAG_API_WEB_H
#define DRAG_API_WEB_H

#include <vector>
#include <string>
#include <array>



#include "Sockets.h"

namespace DragAPI {
	namespace Networking {
		enum class AddressFamily {
			Unspecified,
			IPv4,
			IPX,
			AppleTalk,
			NetBIOS,
			IPv6,
			InfraRedDataAsociation,
			Bluetooth
		};

		//Developer note(9.4.2022):Most of theese are not even used and could be infered by the usage of the other parameters in the class methods
		//The network client and server classes are not intended for Ir and Bluetooth functionality.
		//Theese should be separated into a specialized class
		enum class NetworkProtocol {
			ICMP,
			IGMP,
			TCP,
			UDP,
			ICMPV6,
			ReliableMulticast
		};

		class NetworkServer {
		private:
		protected:
		public:
			NetworkServer();
			NetworkServer(NetworkServer& other);
			NetworkServer(NetworkServer&& other);
			~NetworkServer();
		};

		/// <summary>
		/// Platform independent wrapper class used to create platform specific networking implementations.
		/// </summary>
		class NetworkClient {
		private:
		protected:
			//Note that the IP address and port are not storred anywhere.
			//This is still a work in progress class it might be added later on if developement requires it.

			NetworkProtocol m_Protocol;
		public:
			NetworkClient();
			~NetworkClient();
			static NetworkClient* Create(NetworkProtocol proto);//This function is a work in progress. Parameters will be added later
			static void Cleanup(NetworkClient* client);
			virtual void Startup() = 0;
			virtual void Cleanup() = 0;

			virtual void Connect(const char* address, unsigned short port) = 0;
			virtual void Connect(AddressFamily af, const char* address, unsigned short port) = 0;
			virtual void Disconnect() = 0;

			virtual size_t Send(const char* data) = 0;
			virtual size_t Recv(char* buffer) = 0;

			virtual void QueryRecvData(int* availableBytes) = 0;

			virtual Socket* GetSocket() = 0;
		};
	}
}



#endif // ! DRAG_API_WEB_H