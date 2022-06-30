#ifndef STACK_TRACE_H
#define STACK_TRACE_H

#ifdef _DEBUG
//#define STACK_TRACE_DEBUG
#endif
#include <vector>
#include <string>


#ifndef _WINDOWS_
#include <Windows.h>
#endif


#include "MethodInfo.h"

namespace DragAPI{
	namespace Diagnostics {
		class StackTraceEntry {
		private:
		public:
			DWORD64 dw_Address;
			DebugMethodInfo dmi_Method;

			std::string cstr_MethodName;
			int n_ThreadID;

			StackTraceEntry();
			explicit StackTraceEntry(DWORD64 address);
			explicit StackTraceEntry(DWORD64 address, int threadid);
		};
		/*
		class StackTrace {
		private:
			

			
		protected:

		public:
			std::vector<StackTraceEntry> a_StackWalkEntries;

			StackTrace();
			StackTrace(int n_Skip);

			void Capture();
			void Capture(int n_Skip);

			std::string ToString();
			std::wstring ToWString();
		};
		*/

		class StackTrace {
		public:
			std::vector<StackTraceEntry> m_StackWalkEntries;


			StackTrace();
			~StackTrace();

			virtual void Capture(size_t nSkip = 0) = 0;

			std::string ToString();
			std::wstring ToWString();

			static StackTrace* Create(size_t nSkip);
		};
	}
}

#endif