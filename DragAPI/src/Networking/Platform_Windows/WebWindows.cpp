#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "../../Diagnostics/StackTrace.h"
#include "WebWindows.h"


#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _WS2TCPIP_H_
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#endif


DragAPI::Networking::NetworkClientWindows::NetworkClientWindows()
{
	
}

DragAPI::Networking::NetworkClientWindows::NetworkClientWindows(NetworkClientWindows& other)
{
}

DragAPI::Networking::NetworkClientWindows::NetworkClientWindows(NetworkClientWindows&& other)
{
}

DragAPI::Networking::NetworkClientWindows::~NetworkClientWindows()
{
	
}

void DragAPI::Networking::NetworkClientWindows::Startup()
{
	ZeroMemory(&this->m_WSAData, sizeof(WSADATA));
	int l_WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &this->m_WSAData);

	//TODO: NetworkClientWindows::ctor():Implement WSAStartup Error handling.
	if (l_WSAStartupResult != 0) {//An error occured.
		switch (l_WSAStartupResult)
		{
		case WSASYSNOTREADY://The underlying network subsystem is not ready for network communication.
			break;
		case WSAVERNOTSUPPORTED://The version of Windows Sockets support requested is not provided by this particular Windows Sockets implementation.
			break;
		case WSAEINPROGRESS://A blocking Windows Sockets 1.1 operation is in progress.
			break;
		case WSAEPROCLIM://A limit on the number of tasks supported by the Windows Sockets implementation has been reached.
			break;
		case WSAEFAULT://The lpWSAData parameter is not a valid pointer.
			break;
		default:
			break;
		}
	}
}

void DragAPI::Networking::NetworkClientWindows::Cleanup()
{
	this->m_Socket->Close();
	//DragAPI::Networking::Socket::Cleanup(this->m_Socket);
	int l_WSACleanupResult = WSACleanup();
	if (l_WSACleanupResult == SOCKET_ERROR) {
		//There was an error while performing the cleanup
		switch (WSAGetLastError()) {
		case WSANOTINITIALISED:
			//A successful WSAStartup call must occur before using this function.
			break;
		case WSAENETDOWN:
			//The network subsystem has failed.
			break;
		case WSAEINPROGRESS:
			//A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.
			break;
		default:
			//Unknown error occured
			break;
		}
	}
}

void DragAPI::Networking::NetworkClientWindows::Connect(const char* address, unsigned short port)
{
	//This will be a bit more specialized than this.
	//Since the Address Family is unspecified there will be a additionall check to see what AF is optimal for the address
	this->Connect(DragAPI::Networking::AddressFamily::Unspecified, address, port);
}

void DragAPI::Networking::NetworkClientWindows::Connect(AddressFamily af, const char* address, unsigned short port)
{
	//Firstly remap the AF and Proto parameters to Windows values
	int l_AddressFamily = AF_UNSPEC;
	int l_Protocol = 0;
	switch (af)
	{
	case DragAPI::Networking::AddressFamily::Unspecified:
		l_AddressFamily = AF_UNSPEC;
		break;
	case DragAPI::Networking::AddressFamily::IPv4:
		l_AddressFamily = AF_INET;
		break;
	case DragAPI::Networking::AddressFamily::IPX:
		l_AddressFamily = AF_IPX;
		break;
	case DragAPI::Networking::AddressFamily::AppleTalk:
		l_AddressFamily = AF_APPLETALK;
		break;
	case DragAPI::Networking::AddressFamily::NetBIOS:
		l_AddressFamily = AF_NETBIOS;
		break;
	case DragAPI::Networking::AddressFamily::IPv6:
		l_AddressFamily = AF_INET6;
		break;
	case DragAPI::Networking::AddressFamily::InfraRedDataAsociation:
		l_AddressFamily = AF_IRDA;
		break;
	case DragAPI::Networking::AddressFamily::Bluetooth:
		l_AddressFamily = AF_BTH;
		break;
	default:
		break;
	}
	

	char* l_PortString = new char[512];
	ZeroMemory(l_PortString, sizeof(char) * 512);
	sprintf_s(l_PortString, 512, "%d", port);

	ADDRINFOEXA* hints = new ADDRINFOEXA();
	ZeroMemory(hints, sizeof(ADDRINFOEXA));
	hints->ai_family = l_AddressFamily;
	hints->ai_socktype = SOCK_STREAM;
	hints->ai_protocol = (int)this->m_Protocol;

	ADDRINFOEXA* result = new ADDRINFOEXA();
	ZeroMemory(result, sizeof(ADDRINFOEXA));

	int l_GetAddrInfoResult = GetAddrInfoExA(address, l_PortString, NS_ALL, nullptr, hints, &result, NULL, NULL, NULL, NULL);
	switch (l_GetAddrInfoResult) {
	case 0:
		//The call to GetAddRinfoEx was sucsessfull
		//No further action should be taken. Just brake out of the switch statement.
		break;
	default:
		//This is an unhandeled error. You should throw an exception.
		break;
	}

	int i = 0;
	for (ADDRINFOEXA* ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		//Resolving the addresses.
		switch (ptr->ai_family) {
		case AF_UNSPEC:
			break;
		case AF_INET:
			// the InetNtop function is available on Windows Vista and later
			{
				
				wchar_t* l_IPString = new wchar_t[46];
				InetNtop(AF_INET, &((struct sockaddr_in*)ptr->ai_addr)->sin_addr, l_IPString, 46);
				delete [] l_IPString;
			}

			// We could also use the WSAAddressToString function
			// sockaddr_ip = (LPSOCKADDR) ptr->ai_addr;
			// The buffer length is changed by each call to WSAAddresstoString
			// So we need to set it for each iteration through the loop for safety
			// ipbufferlength = 46;
			// iRetval = WSAAddressToString(sockaddr_ip, (DWORD) ptr->ai_addrlen, NULL, 
			//    ipstringbuffer, &ipbufferlength );
			// if (iRetval)
			//    wprintf(L"WSAAddressToString failed with %u\n", WSAGetLastError() );
			// else    
			//    wprintf(L"\tIPv4 address %ws\n", ipstringbuffer);
			l_AddressFamily = AF_INET;
			break;
		case AF_INET6:
			// the InetNtop function is available on Windows Vista and later
			{

				wchar_t* l_IPString = new wchar_t[46];
				InetNtop(AF_INET6, &((struct sockaddr_in6*)ptr->ai_addr)->sin6_addr, l_IPString, 46);
				delete[] l_IPString;
			}

			// We could also use WSAAddressToString which also returns the scope ID
			// sockaddr_ip = (LPSOCKADDR) ptr->ai_addr;
			// The buffer length is changed by each call to WSAAddresstoString
			// So we need to set it for each iteration through the loop for safety
			// ipbufferlength = 46;
			//iRetval = WSAAddressToString(sockaddr_ip, (DWORD) ptr->ai_addrlen, NULL, 
			//    ipstringbuffer, &ipbufferlength );
			//if (iRetval)
			//    wprintf(L"WSAAddressToString failed with %u\n", WSAGetLastError() );
			//else    
			//    wprintf(L"\tIPv6 address %ws\n", ipstringbuffer);
			l_AddressFamily = AF_INET6;
			break;
		default:
			break;
		}
	}





	//this->m_Socket = Socket::Create((int)l_AddressFamily, SOCK_STREAM, (int)this->m_Protocol);
	//this->m_Socket->Connect();//Not sure yet how to implement this

	//TODO: Finish the WebWindows::Connect function.
	
}

void DragAPI::Networking::NetworkClientWindows::Disconnect()
{
}

size_t DragAPI::Networking::NetworkClientWindows::Send(const char* data)
{
	return size_t();
}

size_t DragAPI::Networking::NetworkClientWindows::Recv(char* buffer)
{
	return size_t();
}

void DragAPI::Networking::NetworkClientWindows::QueryRecvData(int* availableBytes)
{
}
