#pragma once
#ifndef DRAG_API_EVENT_H
#define DRAG_API_EVENT_H
#include <bitset>
#include <functional>
#include <string>

namespace DragAPI {
	namespace Events {
		enum class EventClass {
			None
		};
		enum class EventType {
			None,//Should never happen.
			Quit,//Set when a quit message is sent
			//Window event types
			WindowCreate,
			WindowPaint,
			WindowDestroy,
			WindowMinimize,
			WindowMaximize,
			WindowMove,
			WindowResize,
			//Mouse EventTypes
			MouseMove,
			MouseDrag,
			MouseButtonDown,
			MouseButtonUp,
			MouseScroll,
			//Keyboard events
			KeyboardButtonDown,
			KeyboardButtonUp,
			KeyboardButtonRepeat
		};


		class Event {
		protected:
			Event();
		public:
			EventType m_Type;
			EventClass m_Class;


			~Event();


			std::wstring ToWString();
			std::string ToString();
		};
	}
}
#endif