#pragma once
#include "event.hpp"
#include "SDL2/SDL_events.h"
#include <ostream>

namespace SDL
{
	namespace Events
	{
		class KeyboardEvent : public virtual Event
		{
		public:
			/** Conversion constructor
			\param event The event to convert
			\throw std::invalid_argument The given event is not a keyboard event
			*/
			KeyboardEvent(const Event& event);
			/** Wrapping constructor
			\param event The keyboard event to wrap
			*/
			KeyboardEvent(const SDL_KeyboardEvent& event);
			/** Initialiser constructor
			\param key The key that was pressed or released
			\param is_down Whether this is a key down event or a key up event
			\param modifiers The modifier keys held during this keyboard event (defaults to none)
			\param is_repeat Whether this is a repetition of a previous event (defaults to false)
			*/
			KeyboardEvent(const SDL_Keycode& key, bool is_down, uint16_t modifiers = 0u, bool is_repeat = false);
			/** Key getter
			\return The key that changed during this event
			*/
			SDL_Keycode getKey() const;
			/** Modifer keys getter
			\return The mask of the modifier keys that were held during this event
			*/
			uint16_t getModifiers() const;
			/** Check if this is a repeated event
			\return True when this event is a reoccurrance of another keyboard event
			\return False when this event is the first keyboard event of its kind in a chain
			*/
			bool isRepeat() const;
			/** Check if this is a key down event
			\return True when this is a key down event
			\return False when this is a key up event
			*/
			bool isDown() const;
			/** Equals comparison
			\param other The other KeyboardEvent ot compare
			\return True when this and the given KeyboardEvent represent that same event
			\return False when this and the given KeyboardEvent do not represent the same event
			*/
			bool operator==(const KeyboardEvent& other) const;

			/** Not equals comparison
			\param other The other KeyboardEvent ot compare
			\return True when this and the given KeyboardEvent occurred at different times or do not represent the same event
			\return False when this and the given KeyboardEvent occurred at the same time and represent that same event
			*/
			bool operator!=(const KeyboardEvent& other) const;
		protected:
		};

	}
}
/** Stream insertion operator
\param output The output stream to insert into
\param event The keyboard event to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const SDL::Events::KeyboardEvent& event);
