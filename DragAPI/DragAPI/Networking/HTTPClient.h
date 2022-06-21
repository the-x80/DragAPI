#pragma once
#ifndef DRAG_API_HTTP_CLIENT_H
#define DRAG_API_HTTP_CLIENT_H

#include <vector>
#include <stack>
#include <string>
#include <map>

#include <winhttp.h>
#pragma comment(lib, "Winhttp.lib")

#include "Sockets.h"
#include "Exceptions.h"

#include "../Debug.h"
#include "../Diagnostics/Profiling/Profiling.h"

//8.4.2022
//Note that this will likely be massively updated in the future.
//Currently this is here as a quick and dirty way of interfacing with a HTTP server.
//It is very slow and is not optimized at all
//Also it is single threaded and no data parsing is happening at this moment.
//Functionality is very limited and only HTTP version 1.1 is used.
//No caching, no cookies, no TLS, nothing but a basic stateless comunication.


namespace DragAPI {
	namespace Networking {
		namespace HTTP {
			class HTTPClient;
			
			class URI {
			private:
				std::wstring m_URI;
			public:
				URI();
				URI(const wchar_t* uri);
				URI(std::wstring uri);
				URI(URI& other);
				URI(URI&& other) noexcept;
				~URI();

				std::wstring Protocol();
				std::wstring Domain();
				WORD Port();
				std::wstring Path();
				std::wstring Query();
				std::wstring Fragment();

				std::wstring Full();

				operator const wchar_t* ();
				operator std::string();
				operator std::wstring();
			};
			class HTTPHeader {
				friend class HTTPClient;
				friend class HTTPResponse;
			private:
				std::wstring m_Key;
				std::wstring m_Value;
			public:
				HTTPHeader();
				HTTPHeader(std::wstring key, std::wstring value);

				std::wstring GetKey();

				void SetValue(std::wstring value);
			};
			class HTTPRequest {
				friend class HTTPClient;
			private:
				std::wstring m_Verb;
				std::wstring m_ObjectName;
				std::wstring m_Version;
				std::vector<HTTPHeader> m_Headers;
			public:
				HTTPRequest();
				HTTPRequest(std::wstring method, std::wstring value, std::wstring version = L"1.1");

				void AddHeader(std::wstring key, std::wstring value);
				void ModifyHeader(std::wstring key, std::wstring newvalue);
				std::vector<HTTPHeader> Headers();

				std::wstring GetData();
				std::wstring GetVerb();
				std::wstring GetObjectName();
				std::wstring GetVersion();
			};
			class HTTPResource {
				friend class HTTPResponse;
			private:
				std::string m_ResourceType;
				std::vector<unsigned char> m_Data;
			public:
				std::string Type();
			};
			class HTTPResponse {
			private:
				std::string m_Response;
				std::string m_DataType;
				std::string m_Data;
				std::string m_Version;
				int m_ResponseCode;
				std::vector<HTTPHeader> m_Headers;
				HTTPResource m_Resource;
			public:
				HTTPResponse();
				HTTPResponse(std::string data);

				void AddHeaderRaw(const std::wstring header);
				void AddHeadersRaw(const std::wstring headers);
				std::wstring GetHeadersRaw();
				void AddDataRaw(const std::string data);
				void AddDataRaw(const std::string type, const std::string data);

				HTTPResource Resource();

				std::vector<HTTPResource> FindResources();

			private:
				void Parse();
			};
			class HTTPCookie {

			};



			class HTTPClient {
			private:
				Socket* m_Socket;
				char m_MajorVersion;//Defaults to 1
				char m_MinorVersion;//Defaults to 0

				bool m_KeepConnectionAlive;

				HINTERNET m_hSession;
				HINTERNET m_hConnection;
			public:
				HTTPClient();
				HTTPClient(HTTPClient& other);
				HTTPClient(HTTPClient&& other) noexcept;
				~HTTPClient();

				

				HTTPResponse Request(URI url, HTTPRequest request);
			private:
				void Connect(URI url);
				void Disconnect();

				int GetHeaderDataSize(HINTERNET hRequest);
				int Recv(std::string* buffer);

				bool HasRecvData();
				void WaitForData();

				std::string GetVersionAsString();
			};
		}

		namespace Exceptions {
			class HTTPException : public DragAPI::Exceptions::Exception {
			private:
				DragAPI::Networking::HTTP::HTTPClient* client;
			public:
				HTTPException();
				HTTPException(DragAPI::Networking::HTTP::HTTPClient* c, std::wstring msg);
			};
		}
	}
}

#endif