#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** Unit tests for SDL::Events::MouseButtonEvent */
	extern const std::map<std::string, std::function<void()>> SDL_EVENTS_MOUSE_BUTTON_EVENT_TESTS;
}
