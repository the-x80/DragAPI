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

		class ApplicationStartEvent : public ApplicationEvent {
		public:
			ApplicationStartEvent();

			DRAG_API_EVENTS_TYPE(ApplicationStart);
		};

		class ApplicationTickEvent : public ApplicationEvent {
		public:
			ApplicationTickEvent();

			DRAG_API_EVENTS_TYPE(ApplicationTick);
		};

		class ApplicationRequestQuitEvent : public ApplicationEvent {
		public:
			int m_ExitCode;


			ApplicationRequestQuitEvent();
			ApplicationRequestQuitEvent(int exitCode);

			DRAG_API_EVENTS_TYPE(ApplicationRequestQuit);
		};
		class ApplicationQuitEvent : public ApplicationEvent {
		public:
			ApplicationQuitEvent();

			DRAG_API_EVENTS_TYPE(ApplicationQuit);
		};
	}
}

#endif