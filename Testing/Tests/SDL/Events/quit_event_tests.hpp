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
			/** Unit tests for SDL::Events::QuitEvent */
			extern const std::map<std::string, std::function<void()>> QUIT_EVENT_TESTS;
		}
	}
}
