#include "sdl_events_mouse_button_event_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/SDL/Events/mouse_button_event.hpp"
#include <ctime>
#include "../../Source/SDL/Events/quit_event.hpp"

const std::map<std::string, std::function<void()>> Tests::SDL_EVENTS_MOUSE_BUTTON_EVENT_TESTS = {
	{
		"SDL::Events::MouseButtonEvent Initialiser Constructor",
		[]{
			const uint8_t BUTTON = SDL_BUTTON_LEFT;
			const bool IS_DOWN = true;
			const Data::Position<int32_t> POS = {123, 456};
			const bool IS_TOUCH = true;
			SDL::Events::MouseButtonEvent test = {BUTTON, IS_DOWN, POS, IS_TOUCH};
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
			SDL::Events::MouseButtonEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
			TestFramework::assertEqual(test.getButton(), EVENT.button);
			TestFramework::assertEqual(test.getPosition(), Data::Position<int32_t>(EVENT.x, EVENT.y));
			TestFramework::assertEqual(test.isDown(), EVENT.type == SDL_MOUSEBUTTONDOWN);
			TestFramework::assertEqual(test.isTouch(), EVENT.which == SDL_TOUCH_MOUSEID);
		}
	},
	{
		"SDL::Events::MouseButtonEvent Conversion Constructor",
		[]{
			const uint8_t BUTTON = SDL_BUTTON_RIGHT;
			const bool IS_DOWN = true;
			const Data::Position<int32_t> POS = {902, -444};
			const bool IS_TOUCH = true;
			SDL::Events::MouseButtonEvent test = {SDL::Events::Event(SDL::Events::MouseButtonEvent(BUTTON, IS_DOWN, POS, IS_TOUCH))};
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
				SDL::Events::MouseButtonEvent(SDL::Events::QuitEvent());
			});
		}
	},
	{
		"SDL::Events::MouseButtonEvent Equals Comparison",
		[]
		{
			const uint8_t BUTTON = SDL_BUTTON_X2;
			const bool IS_DOWN = false;
			const Data::Position<int32_t> POS = {-2390, 302};
			TestFramework::assertEqual(SDL::Events::MouseButtonEvent(BUTTON, IS_DOWN, POS, false), SDL::Events::MouseButtonEvent(BUTTON, IS_DOWN, POS, true));
		}
	},
	{
		"SDL::Events::MouseButtonEvent Not Equals Comparison",
		[]{
			TestFramework::assertNotEqual(SDL::Events::MouseButtonEvent(SDL_BUTTON_X1, true, {}), SDL::Events::MouseButtonEvent(SDL_BUTTON_LEFT, true, {}));
			TestFramework::assertNotEqual(SDL::Events::MouseButtonEvent(SDL_BUTTON_RIGHT, true, {}), SDL::Events::MouseButtonEvent(SDL_BUTTON_RIGHT, false, {}));
			TestFramework::assertNotEqual(SDL::Events::MouseButtonEvent(SDL_BUTTON_MIDDLE, true, {}), SDL::Events::MouseButtonEvent(SDL_BUTTON_MIDDLE, true, {-12, -489}));
		}
	}
};
