#include "sdl_events_event_queue_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/SDL/Events/event_queue.hpp"
#include "../../Source/SDL/Events/quit_event.hpp"
#include "SDL2/SDL.h"

const std::map<std::string, std::function<void()>> Tests::SDL_EVENTS_EVENT_QUEUE_TESTS
{
	{
		"SDL::Events Queue Push and Poll",
		[]{
			SDL::Events::Event QUIT_EVENT = SDL::Events::QuitEvent();
			SDL_Init(SDL_INIT_VIDEO);
            TestFramework::assertEqual(SDL::Events::isEventQueued(), false);
            SDL::Events::pushEvent(QUIT_EVENT);
            TestFramework::assertEqual(SDL::Events::isEventQueued(), true);
            TestFramework::assertEqual(SDL::Events::pollNextEvent(), QUIT_EVENT);
            TestFramework::assertEqual(SDL::Events::isEventQueued(), false);
			SDL_Quit();
		}
	}
};
