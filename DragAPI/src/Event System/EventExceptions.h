#pragma once
#ifndef DRAG_API_EVENT_EXCEPTIONS_H
#define DRAG_API_EVENT_EXCEPTIONS_H
#include "Event.h"
#include "../Data Types/String.h"
#include "../Exceptions/Exceptions.h"

namespace DragAPI {
	namespace Events {
		class Event;
		namespace Exceptions {
			class EventException : public DragAPI::Exceptions::Exception {
			public:
				DragAPI::Events::Event* m_Event;

				EventException();
				EventException(DragAPI::Events::Event* event);
				EventException(DragAPI::Events::Event* event, DragAPI::string msg);
			};
		}
	}
}
#endif