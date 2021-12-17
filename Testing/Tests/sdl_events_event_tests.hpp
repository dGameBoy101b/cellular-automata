#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** Unit tests for SDL::Events::Event */
	extern const std::map<std::string, std::function<void()>> SDL_EVENTS_EVENT_TESTS;
}
