#include "quit_event.hpp"
#include <ctime>
#include <stdexcept>

using namespace SDL::Events;

QuitEvent::QuitEvent()
{
	this->event.type = SDL_QUIT;
	this->event.quit.type = SDL_QUIT;
	this->event.quit.timestamp = (uint32_t)std::time(nullptr);
}

QuitEvent::QuitEvent(const SDL_QuitEvent& event)
{
	this->event.type = SDL_QUIT;
	this->event.quit = event;
}

QuitEvent::QuitEvent(const Event& event)
{
	switch (event.getType())
	{
	case SDL_QUIT:
		this->event = event.getEvent();
		break;
	default:
		throw std::invalid_argument("Event is not a quit event");
	}
}

bool QuitEvent::operator==(const QuitEvent& other) const
{
	return true;
}

bool QuitEvent::operator!=(const QuitEvent& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const QuitEvent& event)
{
	time_t stamp = event.getTimestamp();
	return output << std::ctime(&stamp) << " Quit";
}
