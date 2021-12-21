#pragma once
#include "event.hpp"
#include "../../Data/position.hpp"
#include "SDL2/SDL_mouse.h"

namespace SDL
{
	namespace Events
	{
		class MouseButtonEvent : public virtual Event
		{
		public:
			/** Initialisation Constructor
			\param button The mouse button that changed
			\param is_down Whether the button was pressed or released
			\param position The position of the mouse when this event occurred
			\param is_touch Whether this is a click from a mouse or touchscreen
			\throw std::invalid_argument The given mouse button is not supported
			*/
			MouseButtonEvent(const uint8_t& button, const bool& is_down, const Data::Position<int32_t>& position, bool is_touch = false);
			/** Wrapper Constructor
			\param event The SDL mouse button event to wrap
			*/
			MouseButtonEvent(const SDL_MouseButtonEvent& event);
			/** Conversion Constructor
			\param event The event to convert
			\throw std::invalid_argument The given event is not a mouse button event
			*/
			MouseButtonEvent(const Event& event);
			/** Button getter
			\return The button that changed
			*/
			uint8_t getButton() const;
			/** State getter
			\return True when the button was pressed
			\return False when the button was released
			*/
			bool isDown() const;
			/** Position getter
			\return The position of the mouse when this event occurred
			*/
			Data::Position<int32_t> getPosition() const;
			/** Check if this was generated by a touchscreen
			\return True when this was generated by a touchscreen
			\return False when this was generated by a mouse
			*/
			bool isTouch() const;
			/** Equals operator
			\param other The other mouse button event to compare to this
			\return True The given event represents the same change to the same mouse button in the same position
			\return False otherwise
			*/
			bool operator==(const MouseButtonEvent& other) const;
			/** Not equals operator
			\param other The other mouse button event to compare to this
			\return False The given event represents the same change to the same mouse button in the same position
			\return True otherwise
			*/
			bool operator!=(const MouseButtonEvent& other) const;
		};
	}
}
/** Mouse button event stream insertion
\param output The output stream to insert into
\param event The mouse button event to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const SDL::Events::MouseButtonEvent& event);
