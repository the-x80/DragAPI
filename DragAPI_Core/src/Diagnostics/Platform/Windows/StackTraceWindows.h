#pragma once
#ifndef DRAG_API_STACK_TRACE_WINDOWS_H
#define DRAG_API_STACK_TRACE_WINDOWS_H

#include "../../StackTrace.h"

namespace DragAPI {
	namespace Diagnostics {
		class StackTraceWindows : public StackTrace {
		public:
			HANDLE h_Process;
			HANDLE h_Thread;
			int n_ThreadID;

			StackTraceWindows();
			~StackTraceWindows();

			virtual void Capture(size_t nSkip = 0) override;
		};
	}
}
#endif