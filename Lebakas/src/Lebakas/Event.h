#pragma once

#include "Core.h"
#include "Input.h"

/// <summary>
/// Wrapper for sfml events
/// </summary>
class LEBAKAS_API Event
{
public:
	enum Type
	{
		NONE,
		CLOSE_WINDOW,
		KEY_PRESSED,
		KEY_RELEASED,

		NUM_EVENTS
	};

	Event(Type type = NONE);

	Type EventType;
	Device::Input::Key Key;
};