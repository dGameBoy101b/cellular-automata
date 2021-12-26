#include "mouse_motion_event.hpp"
#include <ctime>
#include <stdexcept>

using namespace CellularAutomata::SDL::Events;

MouseMotionEvent::MouseMotionEvent(const Data::Position<int32_t>& position, const Data::Position<int32_t>& velocity, bool is_touch)
{
	this->event.motion.type = SDL_MOUSEMOTION;
	this->event.motion.timestamp = std::time(nullptr);
	this->event.motion.windowID = SDL_GetWindowID(SDL_GetMouseFocus());
	this->event.motion.which = is_touch ? SDL_TOUCH_MOUSEID : !SDL_TOUCH_MOUSEID;
	this->event.motion.state = SDL_GetMouseState(nullptr, nullptr);
	this->event.motion.x = position.getX();
	this->event.motion.y = position.getY();
	this->event.motion.xrel = velocity.getX();
	this->event.motion.yrel = velocity.getY();
}

MouseMotionEvent::MouseMotionEvent(const SDL_MouseMotionEvent& event)
{
	this->event.motion = event;
}

MouseMotionEvent::MouseMotionEvent(const Event& event)
{
	switch (event.getType())
	{
	case SDL_MOUSEMOTION:
		this->event = event.getEvent();
		break;
	default:
		throw std::invalid_argument("Not a mouse motion event");
	}
}

bool MouseMotionEvent::isTouch() const
{
	return this->event.motion.which == SDL_TOUCH_MOUSEID;
}

CellularAutomata::Data::Position<int32_t> MouseMotionEvent::getPosition() const
{
	return Data::Position<int32_t>(this->event.motion.x, this->event.motion.y);
}

CellularAutomata::Data::Position<int32_t> MouseMotionEvent::getVelocity() const
{
	return Data::Position<int32_t>(this->event.motion.xrel, this->event.motion.yrel);
}

bool MouseMotionEvent::operator==(const MouseMotionEvent& other) const
{
	return this->getPosition() == other.getPosition()
	&& this->getVelocity() == other.getVelocity();
}

bool MouseMotionEvent::operator!=(const MouseMotionEvent& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const CellularAutomata::SDL::Events::MouseMotionEvent& event)
{
	return output << "Mouse Motion: " << event.getPosition() << " - " << event.getVelocity();
}
