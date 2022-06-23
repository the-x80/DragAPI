 #pragma once
#ifndef DRAG_API_EVENT_SYSTEM_H
#define DRAG_API_EVENT_SYSTEM_H
#include <queue>
#include <vector>

#include "Event.h"
#include "ApplicationEvents.h"
#include "KeyboardEvents.h"



namespace DragAPI {
	namespace Events {
		class EventDispatcher;

		class IEventListener {
		public:
			IEventListener() {};
			~IEventListener() {};

			virtual void OnEvent(Event* e) = 0;
		};

		class EventDispatcher {
		public:
			EventDispatcher();
			~EventDispatcher();

			void PushEvent(Event* e);
			void Dispatch();

			void RegisterIEventListener(IEventListener* l);
			void UnregisterIEventListener(IEventListener* l);
		private:
			class Listener {
			public:
				IEventListener* m_Listener;
				std::vector<DragAPI::Events::EventType> m_SubscribedTypes;
			};
			std::vector<Listener> m_EventListeners;
			std::queue<Event*> m_QueuedEvents;

			void DispatchEvent(Event* e);
		};
	}
}
#endif