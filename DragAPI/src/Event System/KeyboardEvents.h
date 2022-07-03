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
			KeyboardEvent(DragAPI::KeyCode keyCode);
			KeyboardEvent(DragAPI::KeyModifiers mods, DragAPI::KeyCode keyCode);
			~KeyboardEvent();

			static EventType GetStaticEventType() { return EventType::None; };
			virtual EventType GetType() override = 0;
			virtual const char* GetName() override = 0;
		};

		class KeyboardPressedEvent : public KeyboardEvent {
		public:
			KeyboardPressedEvent();
			KeyboardPressedEvent(DragAPI::KeyCode keyCode);
			KeyboardPressedEvent(DragAPI::KeyModifiers mods, DragAPI::KeyCode keyCode);
			~KeyboardPressedEvent();
			

			DRAG_API_EVENTS_TYPE(KeyboardButtonPressed);
		};
		class KeyboardReleasedEvent : public KeyboardEvent {
		public:
			KeyboardReleasedEvent();
			KeyboardReleasedEvent(DragAPI::KeyCode keyCode);
			KeyboardReleasedEvent(DragAPI::KeyModifiers mods, DragAPI::KeyCode keyCode);
			~KeyboardReleasedEvent();


			DRAG_API_EVENTS_TYPE(KeyboardButtonReleased);
		};
		class KeyboardHeldEvent : public KeyboardEvent {
		public:
			KeyboardHeldEvent();
			KeyboardHeldEvent(DragAPI::KeyCode keyCode);
			~KeyboardHeldEvent();

			DRAG_API_EVENTS_TYPE(KeyboardButtonHeld);
		};
		class KeyboardRepeatEvent : public KeyboardEvent {
		public:
			KeyboardRepeatEvent();
			KeyboardRepeatEvent(DragAPI::KeyCode keyCode);
			~KeyboardRepeatEvent();

			DRAG_API_EVENTS_TYPE(KeyboardButtonRepeat);
		};
	}
}

#endif