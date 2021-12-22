#include "mouse_wheel_event.hpp"
#include <ctime>
#include <stdexcept>

using namespace CellularAutomata::SDL::Events;

MouseWheelEvent::MouseWheelEvent(const Data::Position<int32_t>& velocity, bool is_touch, bool is_flipped)
{
	this->event.wheel.type = SDL_MOUSEWHEEL;
	this->event.wheel.timestamp = std::time(nullptr);
	this->event.wheel.windowID = SDL_GetWindowID(SDL_GetMouseFocus());
	this->event.wheel.which = is_touch ? SDL_TOUCH_MOUSEID : !SDL_TOUCH_MOUSEID;
	this->event.wheel.x = (is_flipped ? -1 : 1) * velocity.getX();
	this->event.wheel.y = (is_flipped ? -1 : 1) * velocity.getY();
	this->event.wheel.direction = is_flipped ? SDL_MOUSEWHEEL_FLIPPED : SDL_MOUSEWHEEL_NORMAL;
}

MouseWheelEvent::MouseWheelEvent(const SDL_MouseWheelEvent& event)
{
	this->event.wheel = event;
}

MouseWheelEvent::MouseWheelEvent(const Event& event)
{
	switch (event.getType())
	{
	case SDL_MOUSEWHEEL:
		this->event = event.getEvent();
		break;
	default:
		throw std::invalid_argument("Not a mouse wheel event");
	}
}

CellularAutomata::Data::Position<int32_t> MouseWheelEvent::getVelocity() const
{
	return Data::Position<int32_t>(this->event.wheel.x, this->event.wheel.y);
}

bool MouseWheelEvent::isTouch() const
{
	return this->event.wheel.which == SDL_TOUCH_MOUSEID;
}

bool MouseWheelEvent::isFlipped() const
{
	return this->event.wheel.direction == SDL_MOUSEWHEEL_FLIPPED;
}

bool MouseWheelEvent::operator==(const MouseWheelEvent& other) const
{
	return this->getVelocity() == other.getVelocity();
}

bool MouseWheelEvent::operator!=(const MouseWheelEvent& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const CellularAutomata::SDL::Events::MouseWheelEvent& event)
{
	return output << "Mouse Wheel: " << event.getVelocity();
}
