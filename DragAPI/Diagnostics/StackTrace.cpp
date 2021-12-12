#define _CRT_SECURE_NO_WARNINGS
#include "MethodInfo.h"
#include "StackTrace.h"
#include <DbgHelp.h>
#include <accctrl.h>
#include <aclapi.h>

#pragma comment(lib, "Dbghelp.lib")

//Developer note:
//Perform cleanup on every failure.
DragAPI::Diagnostics::StackTrace::StackTrace()
{
	
}

DragAPI::Diagnostics::StackTrace::StackTrace(int n_Skip)
{
	
}

void DragAPI::Diagnostics::StackTrace::Capture()
{
	this->Capture(0);
}

void DragAPI::Diagnostics::StackTrace::Capture(int n_Skip)
{
#ifdef STACK_TRACE_DEBUG
	char cstr_DebugMessage[1024];
	memset(cstr_DebugMessage, 0, 1024);
	wsprintf(cstr_DebugMessage, "%s started.\n", __func__);
	OutputDebugString(cstr_DebugMessage);
#endif
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


	//EnterCriticalSection(&DbgHelpLock); Implement multithreading later
	SymInitialize(this->h_Process, NULL, TRUE);

	//Using for loop for more flexibility. Might be used in the future
	this->h_Process = GetCurrentProcess();
	this->h_Thread = GetCurrentThread();
	this->n_ThreadID = GetCurrentThreadId();
	for (int i=0;;i++) {
		bool b_StackWalkResult = StackWalk64(dw_MachineType, this->h_Process,
			this->h_Thread, &sf_StackFrame, &con_Context, NULL, SymFunctionTableAccess64,
			SymGetModuleBase64, NULL);

		if (i <= n_Skip) {
			continue;
		}

		if (b_StackWalkResult == false) {//StackWalk failed.
			//This could happen if the end of the stack has been reached
			//Or it could be that some other error has occured.
			//GetLastError is not reliably set by StackWalk64
			//So debbuging here is pointless.

			break;
		}

		//This code should be cleaned up a bit
		//Since not all of the symbols are located on the local machine
		//There will be a need to download windows symbols online.
		//Most likely you will have to create a SymbolHelper class to manage all of this.
		if (sf_StackFrame.AddrPC.Offset != 0) {
			//Valid frame
			int n_SymbolInfoSize = sizeof(SYMBOL_INFO) + 256;

			SYMBOL_INFO* si_Info = (SYMBOL_INFO*)malloc(n_SymbolInfoSize);
			if (si_Info == nullptr) {
				free(si_Info);
				SymCleanup(this->h_Process);
				return;
			}
			ZeroMemory(si_Info, n_SymbolInfoSize);
			si_Info->SizeOfStruct = sizeof(SYMBOL_INFO);
			si_Info->MaxNameLen = 255;
			DWORD64 dw_Displacement;

			bool b_SymFrimAddeResult = SymFromAddr(this->h_Process, sf_StackFrame.AddrPC.Offset, &dw_Displacement, si_Info);
			if (b_SymFrimAddeResult == FALSE) {
				free(si_Info);
				SymCleanup(this->h_Process);
				return;
			}


			StackTraceEntry sf_Entry;
			sf_Entry.dw_Address = sf_StackFrame.AddrPC.Offset;
			sf_Entry.dmi_Method = DebugMethodInfo();
			sf_Entry.cstr_MethodName = si_Info->Name;
			sf_Entry.n_ThreadID = this->n_ThreadID;

			this->a_StackWalkEntries.push_back(sf_Entry);
			
#ifdef STACK_TRACE_DEBUG
			char cstr_DebugMessage[1024];
			wsprintf(cstr_DebugMessage, "sf_StackFrame.AddrPC.Offset = 0x%p\nSymbol name is %s\n", (void*)sf_Entry.dw_Address, sf_Entry.dmi_Method->cstr_MethodName);
			OutputDebugString(cstr_DebugMessage);
#endif
			free(si_Info);
		}
		else {
			//Base of stack reached.
			break;
		}
	}

	SymCleanup(this->h_Process);
	//LeaveCriticalSection( &DbgHelpLock );
}
