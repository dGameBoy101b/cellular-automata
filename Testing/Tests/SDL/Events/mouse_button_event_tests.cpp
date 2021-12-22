#include "mouse_button_event_tests.hpp"
#include "Testing/assertion.hpp"
#include <ctime>
#include "Source/SDL/Events/mouse_button_event.hpp"
#include "Source/SDL/Events/quit_event.hpp"

using namespace CellularAutomata::Data;
using namespace CellularAutomata::SDL::Events;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::MOUSE_BUTTON_EVENT_TESTS = {
	{
		"SDL::Events::MouseButtonEvent Initialiser Constructor",
		[]{
			const uint8_t BUTTON = SDL_BUTTON_LEFT;
			const bool IS_DOWN = true;
			const Position<int32_t> POS = {123, 456};
			const bool IS_TOUCH = true;
			MouseButtonEvent test = {BUTTON, IS_DOWN, POS, IS_TOUCH};
			TestFramework::assertEqual(test.getType(), IS_DOWN ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP);
			TestFramework::assertEqual(test.getButton(), BUTTON);
			TestFramework::assertEqual(test.isDown(), IS_DOWN);
			TestFramework::assertEqual(test.getPosition(), POS);
			TestFramework::assertEqual(test.isTouch(), IS_TOUCH);
		}
	},
	{
		"SDL::Events::MouseButtonEvent Wrapper Constructor",
		[]{
			const SDL_MouseButtonEvent EVENT = {
				.type = SDL_MOUSEBUTTONUP,
				.timestamp = (uint32_t)std::time(nullptr),
				.windowID = SDL_GetWindowID(SDL_GetMouseFocus()),
				.which = SDL_TOUCH_MOUSEID,
				.button = SDL_BUTTON_MIDDLE,
				.state = SDL_RELEASED,
				.clicks = 1,
				.padding1 = 0,
				.x = 471,
				.y = -823
			};
			MouseButtonEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
			TestFramework::assertEqual(test.getButton(), EVENT.button);
			TestFramework::assertEqual(test.getPosition(), Position<int32_t>(EVENT.x, EVENT.y));
			TestFramework::assertEqual(test.isDown(), EVENT.type == SDL_MOUSEBUTTONDOWN);
			TestFramework::assertEqual(test.isTouch(), EVENT.which == SDL_TOUCH_MOUSEID);
		}
	},
	{
		"SDL::Events::MouseButtonEvent Conversion Constructor",
		[]{
			const uint8_t BUTTON = SDL_BUTTON_RIGHT;
			const bool IS_DOWN = true;
			const Position<int32_t> POS = {902, -444};
			const bool IS_TOUCH = true;
			MouseButtonEvent test = {Event(MouseButtonEvent(BUTTON, IS_DOWN, POS, IS_TOUCH))};
			TestFramework::assertEqual(test.getButton(), BUTTON);
			TestFramework::assertEqual(test.isDown(), IS_DOWN);
			TestFramework::assertEqual(test.getPosition(), POS);
			TestFramework::assertEqual(test.isTouch(), IS_TOUCH);
		}
	},
	{
		"SDL::Events::MouseButtonEvent Conversion Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				MouseButtonEvent(Event(QuitEvent().getEvent()));
			});
		}
	},
	{
		"SDL::Events::MouseButtonEvent Equals Comparison",
		[]
		{
			const uint8_t BUTTON = SDL_BUTTON_X2;
			const bool IS_DOWN = false;
			const Position<int32_t> POS = {-2390, 302};
			TestFramework::assertEqual(MouseButtonEvent(BUTTON, IS_DOWN, POS, false), MouseButtonEvent(BUTTON, IS_DOWN, POS, true));
		}
	},
	{
		"SDL::Events::MouseButtonEvent Not Equals Comparison",
		[]{
			TestFramework::assertNotEqual(MouseButtonEvent(SDL_BUTTON_X1, true, {}), MouseButtonEvent(SDL_BUTTON_LEFT, true, {}));
			TestFramework::assertNotEqual(MouseButtonEvent(SDL_BUTTON_RIGHT, true, {}), MouseButtonEvent(SDL_BUTTON_RIGHT, false, {}));
			TestFramework::assertNotEqual(MouseButtonEvent(SDL_BUTTON_MIDDLE, true, {}), MouseButtonEvent(SDL_BUTTON_MIDDLE, true, {-12, -489}));
		}
	}
};
