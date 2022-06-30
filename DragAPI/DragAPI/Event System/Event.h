#pragma once
#ifndef DRAG_API_EVENT_H
#define DRAG_API_EVENT_H
#include <bitset>
#include <functional>
#include <string>
#include "../DragAPI.Core.h"
#include "EventExceptions.h"

namespace DragAPI {
	namespace Events {
		enum class EventCategory {
			None,
			Application = BIT_SET(0),
			Input = BIT_SET(1),
			Device = BIT_SET(2),
			Keyboard = BIT_SET(3),
			Mouse = BIT_SET(4)
		};
		enum class EventType {
			None,//Should never happen.
			//Application event types
			ApplicationStart,
			ApplicationTick,
			ApplicationRequestQuit,
			ApplicationQuit,//Set when a quit message is sent
			//Window event types
			WindowCreate,
			WindowPaint,
			WindowClose,
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
			KeyboardButtonPressed,
			KeyboardButtonReleased,
			KeyboardButtonHeld,
			KeyboardButtonRepeat
		};

#define DRAG_API_EVENTS_TYPE(x)\
			static EventType GetStaticEventType() { return EventType::##x; };\
			virtual EventType GetType(){return GetStaticEventType();}\
			virtual const char* GetName(){ return #x;}

#define DRAG_API_EVENTS_CATEGORY(x)\
			virtual EventCategory GetCategory() override {return this->m_Category;}


		class Event {
		protected:
			Event();
		public:
			EventType m_Type;
			EventCategory m_Category;


			~Event();


			std::wstring ToWString() { return std::wstring(); }
			std::string ToString() { return this->GetName();}

			static EventType GetStaticEventType() { return EventType::None; };
			virtual EventType GetType() = 0;
			virtual const char* GetName() = 0;

			virtual EventCategory GetCategory() { return this->m_Category; }
		};


	}
}
#endif