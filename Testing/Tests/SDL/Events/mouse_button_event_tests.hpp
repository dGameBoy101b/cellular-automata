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
			/** Unit tests for SDL::Events::MouseButtonEvent */
			extern const std::map<std::string, std::function<void()>> MOUSE_BUTTON_EVENT_TESTS;
		}
	}
}
