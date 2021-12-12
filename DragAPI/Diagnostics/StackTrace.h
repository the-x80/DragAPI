#ifndef STACK_TRACE_H
#define STACK_TRACE_H

#ifdef _DEBUG
//#define STACK_TRACE_DEBUG
#endif

#ifndef _WINDOWS_
#include <Windows.h>
#endif
#ifndef VECTOR_H
#include <vector>
#endif
#include <string>

namespace DragAPI{
	namespace Diagnostics {
		class StackTraceEntry {
		public:
			DWORD64 dw_Address;
			DebugMethodInfo dmi_Method;

			std::string cstr_MethodName;
			int n_ThreadID;
		};
		class StackTrace {
		private:
			HANDLE h_Process;
			HANDLE h_Thread;
			int n_ThreadID;
		protected:

		public:
			std::vector<StackTraceEntry> a_StackWalkEntries;

			StackTrace();
			StackTrace(int n_Skip);

			void Capture();
			void Capture(int n_Skip);
		};
	}
}

#endif