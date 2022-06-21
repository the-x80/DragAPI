/*
9.4.2022
Developer note:
	Note that this will be refactored sometime in the future.
	For now its highly platform specific to Windows since it uses its WinHttp API to comunicate with the servers
	This will be superseeded by the NetworkClient class for its platform independence
*/



#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <codecvt>
#include <sstream>

#include <Windows.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#include "../Diagnostics/Diagnostics.h"
#include "HTTPClient.h"

//#define _DEBUG_HTTP

#ifdef _DEBUG_HTTP
#define DEBUG_STRING_BUFFER_SIZE 2048*128
#define DEBUG_LOG(msg, ...){\
	wchar_t* l_DebugString = new wchar_t[DEBUG_STRING_BUFFER_SIZE];\
	memset(l_DebugString, 0, sizeof(wchar_t)*DEBUG_STRING_BUFFER_SIZE);\
	SYSTEMTIME systime;\
	GetSystemTime(&systime);\
	OutputDebugString(L"============================================================================================\n");\
	wsprintf(l_DebugString, msg, __VA_ARGS__);\
	OutputDebugString(l_DebugString);\
	OutputDebugString(L"\n");\
	char* l_DebugStack = new char[DEBUG_STRING_BUFFER_SIZE];\
	DragAPI::Diagnostics::StackTrace st;\
	st.Capture(1);\
	sprintf(l_DebugStack, "ThreadID:%d\nStack Trace:\n%s\n", GetCurrentThreadId(), st.ToString().c_str());\
	OutputDebugStringA(l_DebugStack);\
	delete[] l_DebugStack; \
	OutputDebugString(L"============================================================================================\n");\
	delete[] l_DebugString;\
	}
#define DEBUG_LOG_A(msg, ...){\
	char* l_DebugString = new char[DEBUG_STRING_BUFFER_SIZE];\
	memset(l_DebugString, 0, sizeof(char)*DEBUG_STRING_BUFFER_SIZE);\
	SYSTEMTIME systime;\
	GetSystemTime(&systime);\
	OutputDebugStringA("============================================================================================\n");\
	sprintf(l_DebugString, msg, __VA_ARGS__);\
	OutputDebugStringA(l_DebugString);\
	OutputDebugStringA("\n");\
	char* l_DebugStack = new char[DEBUG_STRING_BUFFER_SIZE];\
	DragAPI::Diagnostics::StackTrace st;\
	st.Capture(1);\
	sprintf(l_DebugStack, "ThreadID:%d\nStack Trace:\n%s\n", GetCurrentThreadId(), st.ToString().c_str());\
	OutputDebugStringA(l_DebugStack);\
	delete[] l_DebugStack;\
	OutputDebugStringA("============================================================================================\n");\
	delete[] l_DebugString;\
	}
#else
#define DEBUG_LOG(msg, ...)
#define DEBUG_LOG_A(msg, ...)
#endif


DragAPI::Networking::HTTP::URI::URI()
{
}

DragAPI::Networking::HTTP::URI::URI(const wchar_t* uri) :
	m_URI(uri)
{
	DEBUG_LOG(L"Created a URI(const wchar_t*) object with parameter %s/%s", uri, this->m_URI.c_str());
}

DragAPI::Networking::HTTP::URI::URI(std::wstring uri) :
	m_URI(uri)
{
	DEBUG_LOG(L"Created a URI(std::wstring) object with parameter %s", uri.c_str());
}

DragAPI::Networking::HTTP::URI::URI(URI& other) :
	m_URI(other.m_URI)
{
}

DragAPI::Networking::HTTP::URI::URI(URI&& other) noexcept :
	m_URI(other.m_URI)
{
}

DragAPI::Networking::HTTP::URI::~URI()
{
}

std::wstring DragAPI::Networking::HTTP::URI::Protocol()
{
	return std::wstring();
}

std::wstring DragAPI::Networking::HTTP::URI::Domain()
{
	return std::wstring();
}

WORD DragAPI::Networking::HTTP::URI::Port()
{
	return WORD();
}

std::wstring DragAPI::Networking::HTTP::URI::Path()
{
	return std::wstring();
}

std::wstring DragAPI::Networking::HTTP::URI::Query()
{
	return std::wstring();
}

std::wstring DragAPI::Networking::HTTP::URI::Fragment()
{
	return std::wstring();
}

std::wstring DragAPI::Networking::HTTP::URI::Full()
{
	return this->m_URI;
}

DragAPI::Networking::HTTP::URI::operator const wchar_t* ()
{
	return this->m_URI.c_str();
}

DragAPI::Networking::HTTP::URI::operator std::string()
{
	int len;
	int slength = (int)this->m_URI.length();
	len = WideCharToMultiByte(CP_ACP, 0, this->m_URI.c_str(), slength, 0, 0, 0, 0);
	std::string r(len, '\0');
	WideCharToMultiByte(CP_ACP, 0, this->m_URI.c_str(), slength, &r[0], len, 0, 0);
	return r;
}

DragAPI::Networking::HTTP::URI::operator std::wstring()
{
	return this->m_URI;
}

DragAPI::Networking::HTTP::HTTPHeader::HTTPHeader()
{
}

DragAPI::Networking::HTTP::HTTPHeader::HTTPHeader(std::wstring key, std::wstring value) :
	m_Key(key), m_Value(value)
{
	//Here you can perform a check to see if the supplied key and value pairs are a valid header value
}

std::wstring DragAPI::Networking::HTTP::HTTPHeader::GetKey()
{
	return this->m_Key;
}

void DragAPI::Networking::HTTP::HTTPHeader::SetValue(std::wstring value)
{
	this->m_Value = value;
}

DragAPI::Networking::HTTP::HTTPRequest::HTTPRequest()
{
}

DragAPI::Networking::HTTP::HTTPRequest::HTTPRequest(std::wstring method, std::wstring value, std::wstring version) :
	m_Verb(method),
	m_ObjectName(value),
	m_Version(version)
{
}

void DragAPI::Networking::HTTP::HTTPRequest::AddHeader(std::wstring key, std::wstring value)
{
	
}

void DragAPI::Networking::HTTP::HTTPRequest::ModifyHeader(std::wstring key, std::wstring newvalue)
{
	for (size_t i = 0; i < this->m_Headers.size(); i++) {
		if (key == m_Headers[i].GetKey()) {
			m_Headers[i].SetValue(newvalue);
			return;
		}
	}
	//If there is no header with that name you could throw an exception explaining that
}

std::vector<DragAPI::Networking::HTTP::HTTPHeader> DragAPI::Networking::HTTP::HTTPRequest::Headers()
{
	return this->m_Headers;
}

std::wstring DragAPI::Networking::HTTP::HTTPRequest::GetData()
{
	DEBUG_LOG_A("Not Implemented");
	return std::wstring();
}

std::wstring DragAPI::Networking::HTTP::HTTPRequest::GetVerb()
{
	return this->m_Verb;
}

std::wstring DragAPI::Networking::HTTP::HTTPRequest::GetObjectName()
{
	return this->m_ObjectName;
}

std::wstring DragAPI::Networking::HTTP::HTTPRequest::GetVersion()
{
	return this->m_Version;
}

std::string DragAPI::Networking::HTTP::HTTPResource::Type()
{
	return this->m_ResourceType;
}

DragAPI::Networking::HTTP::HTTPResponse::HTTPResponse()
{
}

DragAPI::Networking::HTTP::HTTPResponse::HTTPResponse(std::string data) :
	m_Response(data)
{
}

void DragAPI::Networking::HTTP::HTTPResponse::AddHeaderRaw(const std::wstring header)
{
	//Here you parse the header for data before placing it into the array
	//Implement some error checking aswell
	HTTPHeader l_Header;
	size_t l_ColonIndex = header.find(':', 0);
	if (l_ColonIndex != std::wstring::npos) {//If the index was found
		l_Header.m_Key = std::wstring(l_ColonIndex + 1, 0);
		for (size_t i = 0; i < l_ColonIndex; i++) {
			l_Header.m_Key = header.substr(0, l_ColonIndex);
		}
		l_Header.m_Value = std::wstring(header.length() - l_ColonIndex, 0);
		for (size_t i = l_ColonIndex + 1; i < header.length(); i++) {
			l_Header.m_Value[i- (l_ColonIndex+1)] = header[i];
		}
	}
	DEBUG_LOG(L"Added header\nKey:%s\nValue:%s", l_Header.m_Key.c_str(), l_Header.m_Value.c_str());
	this->m_Headers.push_back(l_Header);
}

void DragAPI::Networking::HTTP::HTTPResponse::AddHeadersRaw(const std::wstring headers)
{
	std::wstring l_IndividualHeader;
	std::wstringstream wss(headers);
	while (std::getline(wss, l_IndividualHeader, L'\n')) {
		if (l_IndividualHeader.length() == 0) {//Empty line
			continue;
		}
		this->AddHeaderRaw(l_IndividualHeader);
	}
}

std::wstring DragAPI::Networking::HTTP::HTTPResponse::GetHeadersRaw()
{
	return std::wstring();
}

void DragAPI::Networking::HTTP::HTTPResponse::AddDataRaw(const std::string data)
{
	this->AddDataRaw("html/text", data);
}

void DragAPI::Networking::HTTP::HTTPResponse::AddDataRaw(const std::string type, const std::string data)
{
	this->m_Response = std::string(data);
	m_Resource.m_Data.resize(data.length());
	for (size_t i = 0; i < data.length()/*Its single byte per character.*/; i++) {
		m_Resource.m_Data[i] = data[i];
	}
	this->m_Resource.m_ResourceType = type;
}

DragAPI::Networking::HTTP::HTTPResource DragAPI::Networking::HTTP::HTTPResponse::Resource()
{
	return this->m_Resource;
}

void DragAPI::Networking::HTTP::HTTPResponse::Parse()
{

}




DragAPI::Networking::HTTP::HTTPClient::HTTPClient()
{
	//TODO:Implement a name for the HTTP client(1st parameter of WinHttpOpen)
	m_hSession = WinHttpOpen((LPCWSTR)L"Unknown", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
}

DragAPI::Networking::HTTP::HTTPClient::HTTPClient(HTTPClient& other)
{
}

DragAPI::Networking::HTTP::HTTPClient::HTTPClient(HTTPClient&& other) noexcept
{
}

DragAPI::Networking::HTTP::HTTPClient::~HTTPClient()
{
	WinHttpCloseHandle(m_hSession);
}

DragAPI::Networking::HTTP::HTTPResponse DragAPI::Networking::HTTP::HTTPClient::Request(URI url, HTTPRequest request)
{
	this->Connect(url);

	HINTERNET l_hRequest = WinHttpOpenRequest(this->m_hConnection, request.GetVerb().c_str(), request.GetObjectName().c_str(), request.GetVersion().c_str(), WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
	for (size_t i = 0; i < request.Headers().size(); i++) {
		//Add headers to the opened request
	}

	WinHttpSendRequest(l_hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);
	WinHttpReceiveResponse(l_hRequest, NULL);

	HTTPResponse retVal = HTTPResponse();
	//Query the headers here before downloading the data.
	//This is done so we know how big the data is and what type it is as well as other data.
	size_t l_HeaderLength = 0;
	WinHttpQueryHeaders(l_hRequest, WINHTTP_QUERY_RAW_HEADERS, WINHTTP_HEADER_NAME_BY_INDEX, WINHTTP_NO_OUTPUT_BUFFER, (LPDWORD)&l_HeaderLength, WINHTTP_NO_HEADER_INDEX);
	if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
		DEBUG_LOG_A("Allocating memory to store header data(%d bytes).", l_HeaderLength);
		std::wstring l_HeaderRaw = std::wstring(l_HeaderLength * 2, 0);
		l_HeaderLength *= 2ul;
		if (WinHttpQueryHeaders(l_hRequest, WINHTTP_QUERY_RAW_HEADERS_CRLF, WINHTTP_HEADER_NAME_BY_INDEX, (LPVOID)l_HeaderRaw.c_str(), (LPDWORD)&l_HeaderLength, WINHTTP_NO_HEADER_INDEX) == FALSE) {
			DEBUG_LOG_A("An error has occured while trying to get the header data. GetLastError returned %d.\nBytes requested %d\n", GetLastError(), l_HeaderLength);
		}

		DEBUG_LOG(L"Recived headers:\n%s", l_HeaderRaw.c_str());
		retVal.AddHeadersRaw(l_HeaderRaw);
	}
	

	
	std::string l_ResponseBuffer;
	do
	{
		// Check for available data.
		size_t dwSize = 0;
		if (!WinHttpQueryDataAvailable(l_hRequest, (DWORD*)&dwSize))
		{
			DEBUG_LOG_A("Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
			break;//You should throw an error here instead.
		}

		// No more available data.
		if (!dwSize)
			break;

		//From this point onwards there should be a difference in approach
		// The data will still be storred in a char* but later in the HTTPResource class it will be handeled propperly
		// Allocate space for the buffer.
		char* pszOutBuffer = new char[(dwSize + 1)];

		// Read the Data.
		ZeroMemory(pszOutBuffer, dwSize + 1);
		DWORD dwDownloaded = 0;
		if (!WinHttpReadData(l_hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded))
		{
			DEBUG_LOG_A("Error %u in WinHttpReadData.\n", GetLastError());
		}
		l_ResponseBuffer.append(pszOutBuffer);
		// Free the memory allocated to the buffer.
		delete[] pszOutBuffer;
	} while (true);
	//Since we are done with the request data the handle should be closed.
	WinHttpCloseHandle(l_hRequest);

	//Add the recived data to the HTTPResponse class
	retVal.AddDataRaw(l_ResponseBuffer);

	//Disconnect from the connected server.
	this->Disconnect();

	
	
	
	
	DEBUG_LOG_A("Recived headers:\n\nRecived data:\n%s", l_ResponseBuffer.c_str());
	return retVal;
}

void DragAPI::Networking::HTTP::HTTPClient::Connect(URI url)
{
	/*
	WSADATA wsaData;
	int WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (WSAStartupResult != 0) {//There was an error
		switch (WSAStartupResult) {
			//Implement error checking. 
			//See https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup for error codes


		default:
			//This is for unexpected and/or unhandeled error codes
			throw new DragAPI::Exceptions::Exception("Unknown Exception");
			return;
		}
	}


	WORD l_Port = 80;//For HTTP requests port 80 is the default

	//Parse the URL to get the address and port of the server
	struct hostent* hp;
	unsigned int addr;
	struct sockaddr_in server;

	this->m_Socket = Socket::Create(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (inet_addr(((std::string)url).c_str()) == INADDR_NONE)
	{
		DEBUG_LOG_A("Gettting host by hostname(%s).", ((std::string)url).c_str());
		hp = gethostbyname(((std::string)url).c_str());
	}
	else
	{
		DEBUG_LOG(L"Gettting host by address.");
		addr = inet_addr(((std::string)url).c_str());
		hp = gethostbyaddr((char*)&addr, sizeof(addr), AF_INET);
	}

	if (hp == NULL)
	{
		DEBUG_LOG(L"Host was not resolved.");
		this->m_Socket.Close();
		return;
	}

	server.sin_addr.s_addr = *((unsigned long*)hp->h_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(l_Port);
	if (connect(this->m_Socket, (struct sockaddr*)&server, sizeof(server)))
	{
		DEBUG_LOG(L"Could not connect to %d.", server.sin_addr.s_addr);
		this->m_Socket.Close();
		return;
	}
	*/
	this->m_hConnection = WinHttpConnect(this->m_hSession, url, INTERNET_DEFAULT_PORT, 0);
}

void DragAPI::Networking::HTTP::HTTPClient::Disconnect()
{
	/*
	this->m_Socket.Close();
	WSACleanup();
	*/
	WinHttpCloseHandle(this->m_hConnection);
}



int DragAPI::Networking::HTTP::HTTPClient::GetHeaderDataSize(HINTERNET hRequest)
{
	int retVal;
	WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_RAW_HEADERS_CRLF, WINHTTP_HEADER_NAME_BY_INDEX, WINHTTP_NO_OUTPUT_BUFFER, (LPDWORD)&retVal, WINHTTP_NO_HEADER_INDEX);
	return retVal;
}

int DragAPI::Networking::HTTP::HTTPClient::Recv(std::string* buffer)
{
	/*
	DEBUG_LOG_A("Reciving data.");
	int size = 0;
	while(this->HasRecvData() == true){
		int currentSize = 0;
		char recvChar = '\0';
		currentSize = recv(this->m_Socket, &recvChar, sizeof(char), 0);//Implement error checking
		if (currentSize == 0) {//Connection is gracefully closed. No data is going to be read anymore
			return size;
		}
		if (currentSize == SOCKET_ERROR) {
			DEBUG_LOG_A("An error has occured while reciving the data.\nNumber of bytes read %d\n", size);
			switch (WSAGetLastError()) {

			}
			return size;//This will most likely not execute mainly because of a exception throw in the code above.
		}
		size += currentSize;
		buffer->append(1, recvChar);
	}
	DEBUG_LOG_A("Recived data:\n%s\n\nBytes recived %d", buffer->c_str(), size);
	return size;
	*/
	return 0;
}

bool DragAPI::Networking::HTTP::HTTPClient::HasRecvData()
{
	/*
	fd_set read_fd, except_fd;
	FD_ZERO(&read_fd);
	FD_ZERO(&except_fd);

	FD_SET(this->m_Socket, &read_fd);
	FD_SET(this->m_Socket, &except_fd);

	timeval timeout = { 0 };
	timeout.tv_sec = 0;
	int n_SelectResult = select(0, &read_fd, NULL, &except_fd, &timeout);

	if (n_SelectResult == SOCKET_ERROR) {        //Select error occured
		//Should probbably do some error checking in here.
		//For now just return false.
		return false;
	}
	if (n_SelectResult == 0) {                    // Timeout
		return false;
	}

	if (FD_ISSET(this->m_Socket, &except_fd)) {  // An exception occured - we want to quit
		throw;//Throw something normal.
		return false;
	}
	else
	{  // We got data! Could be false. Check FD_ISSET(&read_fd)
		//return true;
	}
	if (FD_ISSET(this->m_Socket, &read_fd)) {
		//Could mean we got data or the connection was closed.
		//Currently there is no way of checking between them

		//The only way to be sure is to attempt to read data and the recv function returns 0
		//Another way is to send data and see if the send function return 0
		return true;
	}
	*/
	return false;
}

void DragAPI::Networking::HTTP::HTTPClient::WaitForData()
{
	/*
	while (HasRecvData() == false) {
		Sleep(10);
	}
	*/
}

std::string DragAPI::Networking::HTTP::HTTPClient::GetVersionAsString()
{
	char* l_VersionData = new char[32];
	memset(l_VersionData, 0, sizeof(char) * 32);
	sprintf_s(l_VersionData, 32, "%d.%d", this->m_MajorVersion, this->m_MinorVersion);
	std::string retVal = std::string(l_VersionData);
	delete[] l_VersionData;
	return retVal;
}


