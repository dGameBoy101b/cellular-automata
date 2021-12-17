#include "sdl_events_quit_event_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/SDL/Events/quit_event.hpp"
#include <ctime>
#include "../../Source/SDL/Events/keyboard_event.hpp"

const std::map<std::string, std::function<void()>> Tests::SDL_EVENTS_QUIT_EVENT_TESTS = {
	{
		"SDL::Events::QuitEvent Default Constructor",
		[]{
			const uint32_t BEFORE = std::time(nullptr);
			SDL::Events::QuitEvent test = {};
			const uint32_t AFTER = std::time(nullptr);
			TestFramework::assertEqual(test.getType(), SDL_QUIT);
			TestFramework::assertRange(test.getTimestamp(), BEFORE, AFTER);
		}
	},
	{
		"SDL::Events::QuitEvent Wrapper Constructor",
		[]{
			const SDL_QuitEvent EVENT = {
				.type = SDL_QUIT,
				.timestamp = (uint32_t)std::time(nullptr)
			};
			SDL::Events::QuitEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), SDL_QUIT);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
		}
	},
	{
		"SDL::Events::QuitEvent Conversion Constructor",
		[]{
			const SDL::Events::QuitEvent QUIT_EVENT = {};
			SDL::Events::QuitEvent test = {SDL::Events::Event(QUIT_EVENT.getEvent())};
			TestFramework::assertEqual(test.getType(), SDL_QUIT);
			TestFramework::assertEqual(test.getTimestamp(), QUIT_EVENT.getTimestamp());
		}
	},
	{
		"SDL::Events::QuitEvent Conversion Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				SDL::Events::QuitEvent(SDL::Events::Event(SDL::Events::KeyboardEvent(SDLK_7, true).getEvent()));
			});
		}
	},
	{
		"SDL::Events::QuitEvent Equals Comparison",
		[]
		{
			TestFramework::assertEqual(SDL::Events::QuitEvent(), SDL::Events::QuitEvent());
		}
	},
	{
		"SDL::Events::QuitEvent Not Equals Comparison",
		[]{
			TestFramework::assertEqual(SDL::Events::QuitEvent() != SDL::Events::QuitEvent(), false);
		}
	}
};
