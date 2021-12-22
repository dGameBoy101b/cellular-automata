#pragma once
#include "SDL2/sdl_events.h"
#include <ostream>

namespace CellularAutomata
{
	namespace SDL
	{
		namespace Events
		{
			class Event
			{
			public:
				/** Wrapper constructor
				\param event The SDL event to wrap
				*/
				Event(const SDL_Event& event = {});
				/** Virtual default destructor */
				virtual ~Event() = default;
				/** Event unwrapper
				\return The underlying sdl event
				*/
				const SDL_Event& getEvent() const;
				/** Event type getter
				\return The type of this event
				*/
				SDL_EventType getType() const;
				/** Timestamp getter
				\return The timestamp of when this event occurred
				*/
				uint32_t getTimestamp() const;
				/** Equals comparison
				\param other The other event to compare to this
				\return True when the given event is the same type as this and are equal for that event type
				\return False otherwise
				*/
				bool operator==(const Event& other) const;
				/** Not equals comparison
				\param other The other event to compare to this
				\return True when the given event is a different type as this or are not equal for the matching event type
				\return False otherwise
				*/
				bool operator!=(const Event& other) const;
			protected:
				/** The wrapped SDL event */
				SDL_Event event;
			};
		}
	}
}
/** Stream insertion operator
\param output The output stream to insert into
\param event The event to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const CellularAutomata::SDL::Events::Event& event);
