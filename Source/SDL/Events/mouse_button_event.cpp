#include "mouse_button_event.hpp"
#include <ctime>
#include <stdexcept>

using namespace CellularAutomata::SDL::Events;

MouseButtonEvent::MouseButtonEvent(const uint8_t& button, const bool& is_down, const Data::Position<int32_t>& position, bool is_touch)
{
	switch (button)
	{
	case SDL_BUTTON_LEFT:
	case SDL_BUTTON_RIGHT:
	case SDL_BUTTON_MIDDLE:
	case SDL_BUTTON_X1:
	case SDL_BUTTON_X2:
		this->event.button.type = is_down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
		this->event.button.timestamp = std::time(nullptr);
		this->event.button.windowID = SDL_GetWindowID(SDL_GetMouseFocus());
		this->event.button.which = is_touch ? SDL_TOUCH_MOUSEID : !SDL_TOUCH_MOUSEID;
		this->event.button.button = button;
		this->event.button.state = is_down ? SDL_PRESSED : SDL_RELEASED;
		this->event.button.clicks = 1;
		this->event.button.x = position.getX();
		this->event.button.y = position.getY();
		break;
	default:
		throw std::invalid_argument("Unsupported mouse button");
	}
}

MouseButtonEvent::MouseButtonEvent(const SDL_MouseButtonEvent& event)
{
	this->event.button = event;
}

MouseButtonEvent::MouseButtonEvent(const Event& event)
{
	switch (event.getType())
	{
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		this->event = event.getEvent();
		break;
	default:
		throw std::invalid_argument("Not a mouse button event");
	}
}

uint8_t MouseButtonEvent::getButton() const
{
	return this->event.button.button;
}

bool MouseButtonEvent::isDown() const
{
	return this->event.type == SDL_MOUSEBUTTONDOWN;
}

CellularAutomata::Data::Position<int32_t> MouseButtonEvent::getPosition() const
{
	return Data::Position<int32_t>(this->event.button.x, this->event.button.y);
}

bool MouseButtonEvent::isTouch() const
{
	return this->event.button.which == SDL_TOUCH_MOUSEID;
}

bool MouseButtonEvent::operator==(const MouseButtonEvent& other) const
{
    return this->isDown() == other.isDown()
    && this->getButton() == other.getButton()
    && this->getPosition() == other.getPosition();
}

bool MouseButtonEvent::operator!=(const MouseButtonEvent& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const CellularAutomata::SDL::Events::MouseButtonEvent& event)
{
	output << "Mouse " << (event.isDown() ? "Down" : "Up") << ": ";
	switch(event.getButton())
	{
	case SDL_BUTTON_LEFT:
		output << "Left";
		break;
	case SDL_BUTTON_RIGHT:
		output << "Right";
		break;
	case SDL_BUTTON_MIDDLE:
		output << "Middle";
		break;
	case SDL_BUTTON_X1:
		output << "Extra 1";
		break;
	case SDL_BUTTON_X2:
		output << "Extra 2";
		break;
	default:
		throw std::invalid_argument("Unsupported mouse button");
	}
	return output << " " << event.getPosition();
}
