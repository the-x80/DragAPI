#include "Event.h"

DragAPI::Events::Event::Event():
	m_Type(EventType::None),
	m_Category(EventCategory::None)
{
}

DragAPI::Events::Event::~Event()
{
}
