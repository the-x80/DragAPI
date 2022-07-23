#pragma once
#ifndef DRAG_API_PROFILING_H
#define DRAG_API_PROFILING_H

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _STRING_
#include <string>
#endif

#ifndef _WINDOWS_
#include <Windows.h>
#endif

namespace DragAPI {
	namespace Diagnostics {
		namespace Profiling {

			class ProfilingTimer {
			public:
				std::string name;
				float miliseconds;
			};
			class ProfilingSession {
			private:
				std::vector<ProfilingTimer> timers;
				std::string sessionName;
			public:
				ProfilingSession();



			};






		}
	}
}

#endif