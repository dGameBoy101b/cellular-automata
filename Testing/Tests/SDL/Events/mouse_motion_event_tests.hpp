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
			/** CellularAutomata::SDL::Events::MouseMotionEvent unit tests */
			extern const std::map<std::string, std::function<void()>> MOUSE_MOTION_EVENT_TESTS;
		}
	}
}
