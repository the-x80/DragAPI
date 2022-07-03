#include "../../../DragAPI.Core.h"

#ifdef _WIN32
#include <vector>

#include "StackTraceWindows.h"

#include "../../../Debugging/Debug.h"

DragAPI::Diagnostics::StackTrace* DragAPI::Diagnostics::StackTrace::Create(size_t nSize = 0) {
	StackTrace* retVal = new StackTraceWindows();
	retVal->Capture(nSize);
	return retVal;
}


DragAPI::Diagnostics::StackTraceWindows::StackTraceWindows()
{
}

DragAPI::Diagnostics::StackTraceWindows::~StackTraceWindows()
{
}


void DragAPI::Diagnostics::StackTraceWindows::Capture(size_t n_Skip)
{
	CONTEXT con_Context;
#ifdef _M_IX86
	ZeroMemory(&con_Context, sizeof(CONTEXT));

	con_Context.ContextFlags = CONTEXT_CONTROL;

	//
	// Those three registers are enough.
	//
	__asm
	{
	Label:
		mov[con_Context.Ebp], ebp;
		mov[con_Context.Esp], esp;
		mov eax, [Label];
		mov[con_Context.Eip], eax;
	}
#else
	RtlCaptureContext(&con_Context);
#endif
	STACKFRAME64 sf_StackFrame;
	DWORD dw_MachineType;


	ZeroMemory(&sf_StackFrame, sizeof(STACKFRAME64));
#ifdef _M_IX86
	dw_MachineType = IMAGE_FILE_MACHINE_I386;
	sf_StackFrame.AddrPC.Offset = con_Context.Eip;
	sf_StackFrame.AddrPC.Mode = AddrModeFlat;
	sf_StackFrame.AddrFrame.Offset = con_Context.Ebp;
	sf_StackFrame.AddrFrame.Mode = AddrModeFlat;
	sf_StackFrame.AddrStack.Offset = con_Context.Esp;
	sf_StackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_X64
	dw_MachineType = IMAGE_FILE_MACHINE_AMD64;
	sf_StackFrame.AddrPC.Offset = con_Context.Rip;
	sf_StackFrame.AddrPC.Mode = AddrModeFlat;
	sf_StackFrame.AddrFrame.Offset = con_Context.Rsp;
	sf_StackFrame.AddrFrame.Mode = AddrModeFlat;
	sf_StackFrame.AddrStack.Offset = con_Context.Rsp;
	sf_StackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_IA64
	dw_MachineType = IMAGE_FILE_MACHINE_IA64;
	sf_StackFrame.AddrPC.Offset = con_Context.StIIP;
	sf_StackFrame.AddrPC.Mode = AddrModeFlat;
	sf_StackFrame.AddrFrame.Offset = con_Context.IntSp;
	sf_StackFrame.AddrFrame.Mode = AddrModeFlat;
	sf_StackFrame.AddrBStore.Offset = con_Context.RsBSP;
	sf_StackFrame.AddrBStore.Mode = AddrModeFlat;
	sf_StackFrame.AddrStack.Offset = con_Context.IntSp;
	sf_StackFrame.AddrStack.Mode = AddrModeFlat;
#else
#error "StackTrace::Unsupported platform"
#endif

	//Using for loop for more flexibility. Currently used to skip a certain ammount of entries.
	this->h_Process = GetCurrentProcess();
	this->h_Thread = GetCurrentThread();
	this->n_ThreadID = GetCurrentThreadId();
	for (int i = 0;; i++) {
		SetLastError(0);
		bool b_StackWalkResult = StackWalk64(dw_MachineType, this->h_Process,
			this->h_Thread, &sf_StackFrame, &con_Context, NULL, SymFunctionTableAccess64,
			SymGetModuleBase64, NULL);

		if (i < n_Skip) {//Used to skip a certain number of addresses.
			continue;
		}

		if (b_StackWalkResult == false) {//StackWalk failed.
			//This could happen if the end of the stack has been reached
			//Or it could be that some other error has occured.
			//GetLastError is not reliably set by StackWalk64
			//So debbuging here is pointless.

			break;//Break out of the loop to perform cleanup.
		}

		if (sf_StackFrame.AddrPC.Offset != 0) {
			StackTraceEntry l_Entry = StackTraceEntry(sf_StackFrame.AddrPC.Offset, this->n_ThreadID);
			this->m_StackWalkEntries.push_back(l_Entry);
		}
		else {
			//Base of stack reached.
			break;
		}
	}
}
#endif