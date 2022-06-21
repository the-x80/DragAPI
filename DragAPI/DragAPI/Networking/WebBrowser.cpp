#include "WebBrowser.h"

#define _DEBUG_WEB_BROWSER

#ifdef _DEBUG_WEB_BROWSER
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
	sprintf_s(l_DebugStack, DEBUG_STRING_BUFFER_SIZE, "ThreadID:%d\nStack Trace:\n%s\n", GetCurrentThreadId(), st.ToString().c_str());\
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
	sprintf_s(l_DebugStack, DEBUG_STRING_BUFFER_SIZE, "ThreadID:%d\nStack Trace:\n%s\n", GetCurrentThreadId(), st.ToString().c_str());\
	OutputDebugStringA(l_DebugStack);\
	delete[] l_DebugStack;\
	OutputDebugStringA("============================================================================================\n");\
	delete[] l_DebugString;\
	}
#else
#define DEBUG_LOG(msg, ...)
#define DEBUG_LOG_A(msg, ...)
#endif

DragAPI::Networking::WebBrowser::WebBrowser()
{
}

DragAPI::Networking::WebBrowser::~WebBrowser()
{
}

void DragAPI::Networking::WebBrowser::NavigateTo(std::wstring URL)
{
	//Perform a check if a script thread is already running.
	//If so then stop it and clear the handles
	if (this->m_ScriptThread != INVALID_HANDLE_VALUE) {
		this->StopScriptThread();
	}


	//DEBUG_LOG(L"Downloading the root resource for %s", URL.c_str());
	this->m_CurrentURL = URL;
	//Download the root resource located at this URI location
	DragAPI::Networking::HTTP::HTTPResponse l_BaseResponse = m_HTTPClient.Request(DragAPI::Networking::HTTP::URI(URL), DragAPI::Networking::HTTP::HTTPRequest(L"GET", L"/", L"1.1"));
	
	//Dissect data from the base response
	//Try and parse for HTTP Resources

}

void DragAPI::Networking::WebBrowser::Refresh()
{
}

void DragAPI::Networking::WebBrowser::ExecuteScripts()
{
}

void DragAPI::Networking::WebBrowser::StartScriptThread()
{
}

void DragAPI::Networking::WebBrowser::StopScriptThread()
{
}
