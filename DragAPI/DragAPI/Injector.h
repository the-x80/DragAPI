#pragma once
#ifndef DRAG_API_INJECTOR_H
#define DRAG_API_INJECTOR_H
#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Data Types/String.h"

namespace DragAPI {
	class Injector {
	private:
		String h_InjectedDllFileName;
		HANDLE h_TargetProcess;
	public:
		Injector();
		Injector(Injector& other);
		Injector(Injector&& other);
		~Injector();

		
		void SetInjectedDLL(const char* fName);


		void Inject();
		void Inject(bool createProcess);
	};
}

#endif