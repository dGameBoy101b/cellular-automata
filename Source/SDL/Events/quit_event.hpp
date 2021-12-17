#pragma once
#include "event.hpp"
#include <ostream>

namespace SDL
{
	namespace Events
	{
		class QuitEvent : public virtual Event
		{
		public:
			/** Default constructor */
			QuitEvent();
			/** Wrapper constructor
			\param event The quit event to wrap
			*/
			QuitEvent(const SDL_QuitEvent& event);
			/** Conversion constructor
			\param event The event to convert
			\throw std::invalid_argument The given event is not a quit event
			*/
			QuitEvent(const Event& event);
			/** Equals comparison
			\param other The other QuitEvent to compare to this
			\return True
			*/
			bool operator==(const QuitEvent& event) const;
			/** Not equals comparison
			\param other The other QuiteEvent to compare to this
			\return False
			*/
			bool operator!=(const QuitEvent& event) const;
		};
	}
}
/** Stream insertion
\param output The output stream to insert into
\param event The QuitEvent to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const SDL::Events::QuitEvent& event);
