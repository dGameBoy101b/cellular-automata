#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** Unit tests for SDL::Events::QuitEvent */
	extern const std::map<std::string, std::function<void()>> SDL_EVENTS_QUIT_EVENT_TESTS;
}
