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
			/** Unit tests for SDL::Events::Event */
			extern const std::map<std::string, std::function<void()>> EVENT_TESTS;
		}
	}
}
