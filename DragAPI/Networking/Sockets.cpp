#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#include "Sockets.h"

DragAPI::Networking::Socket DragAPI::Networking::Socket::Create(int af, int type, int protocol)
{
	Socket retVal;
	retVal.handle = socket(af, type, protocol);
	return Socket();
}

DragAPI::Networking::Socket::Socket()
{
}
