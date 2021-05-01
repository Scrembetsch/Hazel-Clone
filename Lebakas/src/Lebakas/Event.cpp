#include "Event.h"

Event::Event(Type type)
	: EventType(type)
	, Key(Device::Input::Key::Unknown)
{
}