#include "Web.h"
#ifdef WIN32
#include "Platform_Windows\WebWindows.h"
#else
#error (Web.h)Unable to compile. Unsupported platform
#endif

DragAPI::Networking::NetworkClient::NetworkClient()
{
	
}

DragAPI::Networking::NetworkClient::~NetworkClient()
{
	
}

DragAPI::Networking::NetworkClient* DragAPI::Networking::NetworkClient::Create(NetworkProtocol proto)
{
#ifdef WIN32
	return new DragAPI::Networking::NetworkClientWindows();
#else

#endif
}

void DragAPI::Networking::NetworkClient::Cleanup(NetworkClient* client)
{
	delete client;
}


