#pragma once
#ifndef DRAG_API_DEBUG_H
#define DRAG_API_DEBUG_H
#include "Exceptions/Exceptions.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <functional>
#include <array>
#include <vector>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <DbgHelp.h>

#pragma comment(lib, "DbgHelp.lib")
#else
#define OutputDebugString printf
#endif

#include "Graphics/Window.h"
#include "Console/Console.h"

#include "Diagnostics/Diagnostics.h"
#include "DateTime.h"

//TODO: Debug.h: Implement the debugging code.
/*
void OutputDebugStringAF(const char* msg, ...) {

}
void OutputDebugStringWF(const char* msg, ...) {

}

#ifdef _UNICODE
#define OutputDebugStringF OutputDebugStringWF
#else
#define OutputDebugStringF OutputDebugStringAF
#endif
*/

#define DEBUG_STRING_BUFFER_SIZE 1024*128

namespace DragAPI {
	namespace Debug {
#ifdef _DEBUG
		static bool isDebugBuild = true;
#else
		static bool isDebugBuild = false;
#endif
		enum class DebugOutputMode {
			None = 0,
			DebugOutput,
			ConsoleOutput,
			WindowOutput
		};

		enum class LogEntryType {
			Info,
			Warning,
			Error
		};

		class LogEntry {
		private:
			std::wstring m_Message;
			LogEntryType m_Type;
			DragAPI::Diagnostics::StackTrace m_StackTrace;

		public:
			LogEntry() {};
			~LogEntry() {};
		};


		static std::vector<LogEntry> g_Entries;


		void SetDebugOutput(DebugOutputMode mode);

		/// <summary>
		/// Prints a string to the debug output.
		/// No formatting is performed nor anything added. What is supplied is printed.
		/// </summary>
		inline void Print(const char* msg) {
#ifdef _WIN32
			OutputDebugStringA(msg);
#else
#endif
		}
		/// <summary>
		/// Prints a string to the debug output.
		/// No formatting is performed nor anything added. What is supplied is printed.
		/// </summary>
		inline void Print(const wchar_t* msg) {
#ifdef _WIN32
			OutputDebugStringW(msg);
#else
#endif
		}

		inline void BeginDebugGroup() {

		}
		inline void EndDebugGroup() {

		}

		inline void Write(const char* msg) {

		}
		inline void Write(const char* msg, ...) {

		}

#pragma warning(disable:4244)
		inline void Write(const wchar_t* msg) {

		}
		/// <summary>
		/// Simply writes a entry to the debug output with some added information.
		/// </summary>
		/// <param name="msg">The pointer to a wide character string that is formatted and printed to the debug output</param>
		/// <param name=""></param>
		inline void Write(const wchar_t* msg, ...) {
			std::va_list args;
			va_start(args, msg);
			
			SYSTEMTIME systime;
			GetSystemTime(&systime);
			OutputDebugString(L"============================================================================================\n");

			//Parse the msg to get the variadic argument types
			//Get the indices of all % symbols
			//Parse the characters after the % symbols untill a space has been reached
			//Calculate the size of the output string
			//Allocate space on the heap to store the output string
			std::vector<std::string> l_ParameterStrings;
			size_t l_OutputStringSize = wcslen(msg);
			for (int i = 0; i < wcslen(msg); i++) {
				if (msg[i] == '%') {
					//This is a wildcard character. Parse the characters after it untill a space is reached to get the token
					std::string l_Token;
					for (int o = i+1; o < wcslen(msg); o++) {
						if (msg[o] == ' ') {
							i = o;
							break;
						}


						l_Token += msg[o];
					}

					std::string l_ParameterString;
					if (l_Token == "d") {//The parameter is a integer type

					}

					l_ParameterStrings.push_back(l_ParameterString);
				}
			}

			
			wchar_t* l_OutputString = new wchar_t[l_OutputStringSize];
			memset(l_OutputString, 0, sizeof(wchar_t) * l_OutputStringSize);

			OutputDebugString(l_OutputString);
			delete[] l_OutputString;

			OutputDebugString(L"\n");
			DragAPI::Diagnostics::StackTrace st;
			st.Capture(1);
			wchar_t* l_StackTraceString = new wchar_t[DEBUG_STRING_BUFFER_SIZE];
			wsprintf(l_StackTraceString, L"ThreadID:%d\nStack Trace:\n%s", GetCurrentThreadId(), st.ToWString().c_str());
			OutputDebugString(l_StackTraceString);
			OutputDebugString(L"============================================================================================\n");
			delete[] l_StackTraceString;
			va_end(args);
		}

		inline void WriteException(::DragAPI::Exceptions::Exception& e) {

		}




		/// <summary>
		/// Platform independent debugger implementation
		/// </summary>
		class Debugger {
		private:
			int m_ProcessID;
		public:
			Debugger();
			~Debugger();

			void KillProcessOnDetach(bool state);

			void Break();
		};

		static std::vector<Debugger> g_AttachedDebuggers;

		Debugger* AttachDebuggerToProcess();
		Debugger* AttachDebuggerToProcess(int procid);
		void DetachDebuggerFromProcess();
		void DetachDebuggerFromProcess(int procid);
	}
}

#undef DEBUG_STRING_BUFFER_SIZE

#endif