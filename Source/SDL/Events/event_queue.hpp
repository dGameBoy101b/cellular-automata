#pragma once
#include "SDL2/SDL_events.h"
#include "event.hpp"

namespace CellularAutomata
{
	namespace SDL
	{
		namespace Events
		{
			/** Poll the next event in the queue
			\return The next event in the queue
			*/
			Event pollNextEvent();
			/** Check if there is an event in the queue
			\return True when the event queue contains at least one event
			\return False when the event queue contain no events
			*/
			bool isEventQueued();
			/** Push given event onto the event queue
			\param event The event to push onto the queue
			\throw std::domain_error The event was filtered out
			\throw std::runtime Failed to push the given event onto the queue
			*/
			void pushEvent(const Event& event);
		}
	}
}
