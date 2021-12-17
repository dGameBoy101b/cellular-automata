#include "sdl_events_event_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/SDL/Events/event.hpp"
#include <ctime>
#include "../../Source/SDL/Events/quit_event.hpp"
#include "../../Source/SDL/Events/keyboard_event.hpp"

const std::map<std::string, std::function<void()>> Tests::SDL_EVENTS_EVENT_TESTS = {
	///\todo Create SDL::Events::Event unit tests
	{
		"SDL::Events::Event Default Constructor",
		[]{
			SDL::Events::Event test = {};
			TestFramework::assertEqual(test.getEvent().type, (uint32_t)SDL_FIRSTEVENT);
		}
	},
	{
		"SDL::Events::Event Wrapper Constructor",
		[]{
			const SDL_QuitEvent QUIT_EVENT = {
				.type = SDL_QUIT,
				.timestamp = (uint32_t)std::time(nullptr)
			};
			const SDL_Event EVENT = {
				.quit = QUIT_EVENT
			};
			SDL::Events::Event test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), QUIT_EVENT.timestamp);
			TestFramework::assertEqual(test.getEvent().type, EVENT.type);
			TestFramework::assertEqual(test.getEvent().quit.timestamp, EVENT.quit.timestamp);
		}
	},
	{
		"SDL::Events::Event Equals Comparison",
		[]{
			const SDL_Event QUIT_EVENT = SDL::Events::QuitEvent().getEvent();
			const SDL_Event KEY_EVENT = SDL::Events::KeyboardEvent(SDLK_LSHIFT, true).getEvent();
			TestFramework::assertEqual(SDL::Events::Event(), SDL::Events::Event());
			TestFramework::assertEqual(SDL::Events::Event(QUIT_EVENT), SDL::Events::Event(QUIT_EVENT));
			TestFramework::assertEqual(SDL::Events::Event(KEY_EVENT), SDL::Events::Event(KEY_EVENT));

		}
	},
	{
		"SDL::Events::Event Not Equals Comparison",
		[]{
			const SDL_Event QUIT_EVENT = SDL::Events::QuitEvent().getEvent();
			const SDL_Event KEY_EVENT1 = SDL::Events::KeyboardEvent(SDLK_RSHIFT, true).getEvent();
			const SDL_Event KEY_EVENT2 = SDL::Events::KeyboardEvent(SDLK_LSHIFT, true).getEvent();
			TestFramework::assertNotEqual(SDL::Events::Event(), SDL::Events::Event(KEY_EVENT1));
			TestFramework::assertNotEqual(SDL::Events::Event(QUIT_EVENT), SDL::Events::Event(KEY_EVENT1));
			TestFramework::assertNotEqual(SDL::Events::Event(KEY_EVENT1), SDL::Events::Event(KEY_EVENT2));
		}
	}
};
