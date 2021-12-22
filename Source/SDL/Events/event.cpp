#include "event.hpp"
#include "quit_event.hpp"
#include "keyboard_event.hpp"
#include "mouse_button_event.hpp"
#include "mouse_wheel_event.hpp"
#include <stdexcept>

using namespace CellularAutomata::SDL::Events;

Event::Event(const SDL_Event& event)
{
	this->event = event;
}

const SDL_Event& Event::getEvent() const
{
	return this->event;
}

SDL_EventType Event::getType() const
{
	return (SDL_EventType)this->event.type;
}

uint32_t Event::getTimestamp() const
{
	switch (this->event.type)
	{
	case SDL_QUIT:
		return this->event.quit.timestamp;
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		return this->event.key.timestamp;
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		return this->event.button.timestamp;
	case SDL_MOUSEWHEEL:
		return this->event.wheel.timestamp;
	default:
		throw std::domain_error("Unrecognised event type");
	}
}

bool Event::operator==(const Event& other) const
{
	if (this->getType() != other.getType())
	{
		return false;
	}
	switch (this->getType())
	{
	case SDL_QUIT:
		return QuitEvent(*this) == QuitEvent(other);
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		return KeyboardEvent(*this) == KeyboardEvent(other);
	case SDL_FIRSTEVENT:
	case SDL_LASTEVENT:
		return true;
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		return MouseButtonEvent(*this) == MouseButtonEvent(other);
	case SDL_MOUSEWHEEL:
		return MouseWheelEvent(*this) == MouseWheelEvent(other);
	default:
		throw std::domain_error("Unrecognised event type");
	}
}

bool Event::operator!=(const Event& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const CellularAutomata::SDL::Events::Event& event)
{
	switch (event.getType())
	{
	case SDL_QUIT:
		return output << CellularAutomata::SDL::Events::QuitEvent(event);
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		return output << CellularAutomata::SDL::Events::KeyboardEvent(event);
	case SDL_FIRSTEVENT:
	case SDL_LASTEVENT:
		return output << "None Event";
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		return output << CellularAutomata::SDL::Events::MouseButtonEvent(event);
	case SDL_MOUSEWHEEL:
		return output << CellularAutomata::SDL::Events::MouseWheelEvent(event);
	default:
		std::domain_error("Unrecognised event type");
	}
}
