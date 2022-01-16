#pragma once
#ifndef DRAG_API_EVENT_SYSTEM_H
#define DRAG_API_EVENT_SYSTEM_H
#include <vector>
#include <functional>
#include "Callback.h"
#include "../Data Types/Queue.h"

namespace DragAPI {
	class EventDispatcher;

	class Event {
	private:
	public:
	};

	class EventListener {
	protected:
		std::vector<Callback<void, Event>*> callbacks;
		EventDispatcher* dispatcher;
	public:
		EventListener();
		EventListener(EventListener& other);
		EventListener(EventListener&& other);
		~EventListener();


	};

	class EventDispatcher {
	private:
		Queue<Event> eventQueue;
	public:
		EventDispatcher();
		EventDispatcher(EventDispatcher&) = delete;
		EventDispatcher(EventDispatcher&&) = delete;
		~EventDispatcher();
	};

	
}

#endif