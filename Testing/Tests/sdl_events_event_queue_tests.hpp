#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** Unit tests for SDL::Events event queue functions */
	extern const std::map<std::string, std::function<void()>> SDL_EVENTS_EVENT_QUEUE_TESTS;
}
