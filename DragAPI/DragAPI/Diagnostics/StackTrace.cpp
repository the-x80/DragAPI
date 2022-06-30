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
	m_StackWalkEntries()
{
	
}

DragAPI::Diagnostics::StackTrace::~StackTrace()
{
}

std::string DragAPI::Diagnostics::StackTrace::ToString()
{
	std::string retVal;
	for (size_t i = 0; i < m_StackWalkEntries.size(); i++) {
		retVal.append(m_StackWalkEntries[i].cstr_MethodName);
		retVal.append("\n");
	}
	return retVal;
}

std::wstring DragAPI::Diagnostics::StackTrace::ToWString()
{
	std::wstring retVal;
	for (size_t i = 0; i < m_StackWalkEntries.size(); i++) {
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
