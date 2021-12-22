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
			/** Unit tests for SDL::Events event queue functions */
			extern const std::map<std::string, std::function<void()>> EVENT_QUEUE_TESTS;
		}
	}
}
