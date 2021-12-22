#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace SDL
	{
		namespace Video
		{
			/** Unit tests for SDL::Video::Window */
			extern const std::map<std::string, std::function<void()>> WINDOW_TESTS;
		}
	}
}
