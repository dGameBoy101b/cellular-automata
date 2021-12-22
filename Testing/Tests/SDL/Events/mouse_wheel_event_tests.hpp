#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace SDL
	{
		namespace Events
		{
			/** SDL::Events::MouseWheelEvent unit tests */
			extern const std::map<std::string, std::function<void()>> MOUSE_WHEEL_EVENT_TESTS;
		}
	}
}
