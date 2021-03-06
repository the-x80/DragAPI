#ifndef METHOD_INFO_H
#define METHOD_INFO_H
#include <string>

#include <Windows.h>
#include <DbgHelp.h>

#include "InfoObject.h"
#include "ModuleInfo.h"
#include "TypeInfo.h"
namespace DragAPI {
	namespace Diagnostics {
		class MethodInfo : public InfoObject {
		public:
			char* cstr_MethodName;
			int n_ParameterCount;
			TypeInfo* a_ParameterTypes;
			TypeInfo* ti_ReturnType;
			ModuleInfo* m_Module;

			MethodInfo();
			MethodInfo(DWORD64 dw_Address, bool b_InitializeSymbols);
			MethodInfo(SYMBOL_INFO* si_Info);
			~MethodInfo();
		};
		class DebugMethodInfo : public MethodInfo {
		public:
			DebugTypeInfo* a_ParameterTypes;
			DebugTypeInfo* ti_ReturnType;
			DebugModuleInfo* m_Module;

			char* cstr_SourceFileDirectory;
			char* cstr_SourceFileName;
			int n_SourceFileLineNumber;

			DebugMethodInfo();
			DebugMethodInfo(DWORD64 dw_Address, bool b_InitializeSymbols);
			DebugMethodInfo(SYMBOL_INFO* si_Info);
			~DebugMethodInfo();
		};


		namespace Exceptions {

		}
	}
}

#endif