#include "event_queue_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/SDL/Events/event_queue.hpp"
#include "Source/SDL/Events/quit_event.hpp"
#include "SDL2/SDL.h"

using namespace CellularAutomata::SDL::Events;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::EVENT_QUEUE_TESTS
{
	{
		"SDL::Events Queue Push and Poll",
		[]{
			Event QUIT_EVENT = QuitEvent();
			SDL_Init(SDL_INIT_VIDEO);
            TestFramework::assertEqual(isEventQueued(), false);
            pushEvent(QUIT_EVENT);
            TestFramework::assertEqual(isEventQueued(), true);
            TestFramework::assertEqual(pollNextEvent(), QUIT_EVENT);
            TestFramework::assertEqual(isEventQueued(), false);
			SDL_Quit();
		}
	}
};
