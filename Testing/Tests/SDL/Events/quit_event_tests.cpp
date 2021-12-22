#include "quit_event_tests.hpp"
#include "Testing/assertion.hpp"
#include <ctime>
#include "Source/SDL/Events/quit_event.hpp"
#include "Source/SDL/Events/keyboard_event.hpp"

using namespace CellularAutomata::SDL::Events;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::QUIT_EVENT_TESTS = {
	{
		"SDL::Events::QuitEvent Default Constructor",
		[]{
			const uint32_t BEFORE = std::time(nullptr);
			QuitEvent test = {};
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
			QuitEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), SDL_QUIT);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
		}
	},
	{
		"SDL::Events::QuitEvent Conversion Constructor",
		[]{
			const QuitEvent QUIT_EVENT = {};
			QuitEvent test = {Event(QUIT_EVENT.getEvent())};
			TestFramework::assertEqual(test.getType(), SDL_QUIT);
			TestFramework::assertEqual(test.getTimestamp(), QUIT_EVENT.getTimestamp());
		}
	},
	{
		"SDL::Events::QuitEvent Conversion Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				QuitEvent(Event(KeyboardEvent(SDLK_7, true).getEvent()));
			});
		}
	},
	{
		"SDL::Events::QuitEvent Equals Comparison",
		[]
		{
			TestFramework::assertEqual(QuitEvent(), QuitEvent());
		}
	},
	{
		"SDL::Events::QuitEvent Not Equals Comparison",
		[]{
			TestFramework::assertEqual(QuitEvent() != QuitEvent(), false);
		}
	}
};
