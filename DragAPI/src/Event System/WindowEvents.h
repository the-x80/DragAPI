#pragma once
#ifndef DRAG_API_WINDOW_EVENTS_H
#define DRAG_API_WINDOW_EVENTS_H
#include "Event.h"

namespace DragAPI {
	class Window;


	namespace Events {
		class WindowEvent : public Event{
		public:
			DragAPI::Window* m_Window;

			WindowEvent();
			WindowEvent(Window* wnd);
			~WindowEvent();

			DRAG_API_EVENTS_TYPE(None);
		};

		class WindowCreateEvent : public WindowEvent {
		public:
			WindowCreateEvent();
			WindowCreateEvent(Window* wnd);
			~WindowCreateEvent();


			DRAG_API_EVENTS_TYPE(WindowCreate);
		};

		class WindowCloseEvent : public WindowEvent {
		public:
			WindowCloseEvent();
			WindowCloseEvent(Window* wnd);
			~WindowCloseEvent();


			DRAG_API_EVENTS_TYPE(WindowClose);
		};
	}
}

#endif