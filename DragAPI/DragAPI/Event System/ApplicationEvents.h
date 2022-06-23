#pragma once
#ifndef DRAG_API_APPLICATION_EVENTS_H
#define DRAG_API_APPLICATION_EVENTS_H
#include "Event.h"


namespace DragAPI {
	namespace Events {
		class ApplicationEvent : public Event {
		public:
			ApplicationEvent();
		};

		class ApplicationStart : public ApplicationEvent {
		public:
			ApplicationStart();
		};

		class ApplicationTick : public ApplicationEvent {
		public:
			ApplicationTick();
		};

		class ApplicationQuit : public ApplicationEvent {
		public:
			ApplicationQuit();
		};
	}
}

#endif