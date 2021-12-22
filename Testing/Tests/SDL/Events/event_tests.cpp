#include "event_tests.hpp"
#include "Testing/assertion.hpp"
#include <ctime>
#include "Source/SDL/Events/event.hpp"
#include "Source/SDL/Events/quit_event.hpp"
#include "Source/SDL/Events/keyboard_event.hpp"

using namespace CellularAutomata::SDL::Events;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::EVENT_TESTS = {
	{
		"SDL::Events::Event Default Constructor",
		[]{
			Event test = {};
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
			Event test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), QUIT_EVENT.timestamp);
			TestFramework::assertEqual(test.getEvent().type, EVENT.type);
			TestFramework::assertEqual(test.getEvent().quit.timestamp, EVENT.quit.timestamp);
		}
	},
	{
		"SDL::Events::Event Equals Comparison",
		[]{
			const SDL_Event QUIT_EVENT = QuitEvent().getEvent();
			const SDL_Event KEY_EVENT = KeyboardEvent(SDLK_LSHIFT, true).getEvent();
			TestFramework::assertEqual(Event(), Event());
			TestFramework::assertEqual(Event(QUIT_EVENT), Event(QUIT_EVENT));
			TestFramework::assertEqual(Event(KEY_EVENT), Event(KEY_EVENT));

		}
	},
	{
		"SDL::Events::Event Not Equals Comparison",
		[]{
			const SDL_Event QUIT_EVENT = QuitEvent().getEvent();
			const SDL_Event KEY_EVENT1 = KeyboardEvent(SDLK_RSHIFT, true).getEvent();
			const SDL_Event KEY_EVENT2 = KeyboardEvent(SDLK_LSHIFT, true).getEvent();
			TestFramework::assertNotEqual(Event(), Event(KEY_EVENT1));
			TestFramework::assertNotEqual(Event(QUIT_EVENT), Event(KEY_EVENT1));
			TestFramework::assertNotEqual(Event(KEY_EVENT1), Event(KEY_EVENT2));
		}
	}
};
