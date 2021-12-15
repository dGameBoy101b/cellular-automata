#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** Unit tests for SDL::Video::Window */
	extern const std::map<std::string, std::function<void()>> SDL_WINDOW_TESTS;
}
