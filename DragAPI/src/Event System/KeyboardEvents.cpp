#include "KeyboardEvents.h"

DragAPI::Events::KeyboardEvent::KeyboardEvent():
	m_KeyCode(DragAPI::KeyCode::None),
	m_Modifiers(DragAPI::KeyModifiers::None)
{
}

DragAPI::Events::KeyboardEvent::KeyboardEvent(DragAPI::KeyCode keyCode):
	m_KeyCode(keyCode),
	m_Modifiers(DragAPI::KeyModifiers::None)
{
}

DragAPI::Events::KeyboardEvent::KeyboardEvent(DragAPI::KeyModifiers mods, DragAPI::KeyCode keyCode) :
	m_KeyCode(keyCode),
	m_Modifiers(mods)
{
}

DragAPI::Events::KeyboardEvent::~KeyboardEvent()
{
}

DragAPI::Events::KeyboardPressedEvent::KeyboardPressedEvent()
{
}

DragAPI::Events::KeyboardPressedEvent::KeyboardPressedEvent(DragAPI::KeyCode keyCode):
	KeyboardEvent(keyCode)
{
}

DragAPI::Events::KeyboardPressedEvent::KeyboardPressedEvent(DragAPI::KeyModifiers mods, DragAPI::KeyCode keyCode):
	KeyboardEvent(mods, keyCode)
{
}

DragAPI::Events::KeyboardPressedEvent::~KeyboardPressedEvent()
{
}

DragAPI::Events::KeyboardReleasedEvent::KeyboardReleasedEvent()
{
}

DragAPI::Events::KeyboardReleasedEvent::KeyboardReleasedEvent(DragAPI::KeyCode keyCode):
	KeyboardEvent(keyCode)
{
}

DragAPI::Events::KeyboardReleasedEvent::KeyboardReleasedEvent(DragAPI::KeyModifiers mods, DragAPI::KeyCode keyCode):
	KeyboardEvent(mods, keyCode)
{
}

DragAPI::Events::KeyboardReleasedEvent::~KeyboardReleasedEvent()
{
}
