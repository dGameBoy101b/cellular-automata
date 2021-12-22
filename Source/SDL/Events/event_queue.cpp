#include "event_queue.hpp"
#include <stdexcept>

using namespace CellularAutomata::SDL;

bool Events::isEventQueued()
{
	return SDL_PollEvent(nullptr) == 1;
}

Events::Event Events::pollNextEvent()
{
	SDL_Event event;
	if (SDL_PollEvent(&event) != 1)
	{
		throw std::domain_error("No event queued");
	}
	return Events::Event(event);
}

void Events::pushEvent(const Events::Event& event)
{
	SDL_Event sdl_event = event.getEvent();
	auto res = SDL_PushEvent(&sdl_event);
	if (res == 0)
	{
		throw std::domain_error("Pushed event was filtered out");
	}
	if (res < 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
}
