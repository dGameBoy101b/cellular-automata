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
			/** Unit tests for SDL::Events::KeyboardEvent */
			extern const std::map<std::string, std::function<void()>> KEYBOARD_EVENT_TESTS;
		}
	}
}
