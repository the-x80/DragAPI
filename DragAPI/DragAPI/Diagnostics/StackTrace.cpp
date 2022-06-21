#define _CRT_SECURE_NO_WARNINGS
#include "MethodInfo.h"
#include "StackTrace.h"
#include <DbgHelp.h>
#include <accctrl.h>
#include <aclapi.h>

#pragma comment(lib, "Dbghelp.lib")

//Developer note:
//Perform cleanup on every failure.
DragAPI::Diagnostics::StackTrace::StackTrace():
	h_Process(INVALID_HANDLE_VALUE),
	h_Thread(INVALID_HANDLE_VALUE),
	n_ThreadID(0),
	a_StackWalkEntries()
{
	
}

DragAPI::Diagnostics::StackTrace::StackTrace(int n_Skip) :
	h_Process(INVALID_HANDLE_VALUE),
	h_Thread(INVALID_HANDLE_VALUE),
	n_ThreadID(0),
	a_StackWalkEntries()
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

	//Using for loop for more flexibility. Currently used to skip a certain ammount of entries.
	this->h_Process = GetCurrentProcess();
	this->h_Thread = GetCurrentThread();
	this->n_ThreadID = GetCurrentThreadId();
	for (int i=0;;i++) {
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
			this->a_StackWalkEntries.push_back(l_Entry);
		}
		else {
			//Base of stack reached.
			break;
		}
	}
}

std::string DragAPI::Diagnostics::StackTrace::ToString()
{
	std::string retVal;
	for (size_t i = 0; i < a_StackWalkEntries.size(); i++) {
		retVal.append(a_StackWalkEntries[i].cstr_MethodName);
		retVal.append("\n");
	}
	return retVal;
}

std::wstring DragAPI::Diagnostics::StackTrace::ToWString()
{
	std::wstring retVal;
	for (size_t i = 0; i < a_StackWalkEntries.size(); i++) {
		//retVal.append(a_StackWalkEntries[i].cstr_MethodName.c_str());
		retVal.append(L"\n");
	}
	return retVal;
}


//TODO: Implement the constructors for StackTraceEntry class
DragAPI::Diagnostics::StackTraceEntry::StackTraceEntry():
	dw_Address(0),
	dmi_Method(),
	cstr_MethodName(),
	n_ThreadID(0)
{
}

DragAPI::Diagnostics::StackTraceEntry::StackTraceEntry(DWORD64 address) :
	dw_Address(address),
	dmi_Method(),
	cstr_MethodName(),
	n_ThreadID(0)
{
	//TODO:Implement a mutex for multithreading purpouses since Sym functions cannot be called by multiple threads.

	HANDLE h_Process = GetCurrentProcess();
	bool l_SymInitializeResult = SymInitialize(h_Process, NULL, TRUE);
	if (l_SymInitializeResult == FALSE) {
		//TODO: Handle this error but do not throw an exception
		OutputDebugString(L"Unable to initialize symbols.\n");
		return;
	}

	int n_SymbolInfoSize = sizeof(SYMBOL_INFO) + 256;

	SYMBOL_INFO* si_Info = (SYMBOL_INFO*)malloc(n_SymbolInfoSize);
	if (si_Info == nullptr) {
		//free(si_Info);//This will cause an error
		SymCleanup(h_Process);
		return;
	}
	ZeroMemory(si_Info, n_SymbolInfoSize);
	si_Info->SizeOfStruct = sizeof(SYMBOL_INFO);
	si_Info->MaxNameLen = 255;
	DWORD64 dw_Displacement;

	bool b_SymFromAddrResult = SymFromAddr(h_Process, address, &dw_Displacement, si_Info);
	if (b_SymFromAddrResult == FALSE) {
		free(si_Info);
		SymCleanup(h_Process);
		return;
	}


	free(si_Info);
	SymCleanup(h_Process);
}

DragAPI::Diagnostics::StackTraceEntry::StackTraceEntry(DWORD64 address, int threadid) :
	dw_Address(address),
	dmi_Method(),
	cstr_MethodName(),
	n_ThreadID(threadid)
{
	//TODO:Implement a mutex for multithreading purpouses since Sym functions cannot be called by multiple threads.

	HANDLE h_Process = GetCurrentProcess();
	bool l_SymInitializeResult = SymInitialize(h_Process, NULL, TRUE);
	if (l_SymInitializeResult == FALSE) {
		//TODO: Handle this error but do not throw an exception
		OutputDebugString(L"Unable to initialize symbols.\n");
		return;
	}

	int n_SymbolInfoSize = sizeof(SYMBOL_INFO) + 256;

	SYMBOL_INFO* si_Info = (SYMBOL_INFO*)malloc(n_SymbolInfoSize);
	if (si_Info == nullptr) {
		//free(si_Info);//This will cause an error
		SymCleanup(h_Process);
		return;
	}
	ZeroMemory(si_Info, n_SymbolInfoSize);
	si_Info->SizeOfStruct = sizeof(SYMBOL_INFO);
	si_Info->MaxNameLen = 255;
	DWORD64 dw_Displacement;

	bool b_SymFromAddrResult = SymFromAddr(h_Process, address, &dw_Displacement, si_Info);
	if (b_SymFromAddrResult == FALSE) {
		free(si_Info);
		SymCleanup(h_Process);
		return;
	}


	free(si_Info);
	SymCleanup(h_Process);
}
