#pragma once
#ifndef DRAG_API_THREADING_H
#define DRAG_API_THREADING_H

namespace DragAPI {
	namespace Threading {
		class Thread {
		public:
			Thread() {};
			~Thread() {};

			static Thread* Create();

			virtual void Start(void* param = nullptr) = 0;
			virtual void Terminate() = 0;
			virtual void Pause() = 0;
		};
	}
}

#endif