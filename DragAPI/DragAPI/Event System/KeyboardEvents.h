#pragma once
#ifndef DRAG_API_EVENT_SYSTEM_KEYBOARD_EVENTS_H
#define DRAG_API_EVENT_SYSTEM_KEYBOARD_EVENTS_H
#include "Event.h"
#include "../KeyCodes.h"

namespace DragAPI {
	namespace Events {
		class KeyboardEvent : public Event {
		public:
			DragAPI::KeyCode m_KeyCode;
			DragAPI::KeyModifiers m_Modifiers;

			KeyboardEvent();
			~KeyboardEvent();
		};
	}
}

#endif