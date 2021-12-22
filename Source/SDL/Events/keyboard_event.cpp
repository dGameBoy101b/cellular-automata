#include "keyboard_event.hpp"
#include <ctime>
#include <stdexcept>

using namespace CellularAutomata::SDL::Events;

KeyboardEvent::KeyboardEvent(const Event& event)
{
	switch (event.getType())
	{
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		this->event = event.getEvent();
		break;
	default:
		throw std::invalid_argument("Event is not a keyboard event");
	}
}

KeyboardEvent::KeyboardEvent(const SDL_KeyboardEvent& event)
{
	this->event.type = event.type;
	this->event.key = event;
}

KeyboardEvent::KeyboardEvent(const SDL_Keycode& key, bool is_down, uint16_t modifiers, bool is_repeat)
{
	this->event.type = is_down ? SDL_KEYDOWN : SDL_KEYUP;
	this->event.key.timestamp = (uint32_t)std::time(nullptr);
	this->event.key.windowID = SDL_GetWindowID(SDL_GetKeyboardFocus());
	this->event.key.state = is_down == is_repeat ? SDL_PRESSED : SDL_RELEASED;
    this->event.key.repeat = is_repeat;
    this->event.key.keysym.scancode = SDL_GetScancodeFromKey(key);
    this->event.key.keysym.sym = key;
    this->event.key.keysym.mod = modifiers;
}

SDL_Keycode KeyboardEvent::getKey() const
{
	return this->event.key.keysym.sym;
}

uint16_t KeyboardEvent::getModifiers() const
{
	return this->event.key.keysym.mod;
}

bool KeyboardEvent::isRepeat() const
{
	return this->event.key.repeat != 0;
}

bool KeyboardEvent::isDown() const
{
	return this->event.type == SDL_KEYDOWN;
}

bool KeyboardEvent::operator==(const KeyboardEvent& other) const
{
	return this->isDown() == other.isDown()
	&& this->isRepeat() == other.isRepeat()
	&& this->getKey() == other.getKey()
	&& this->getModifiers() == other.getModifiers();
}

bool KeyboardEvent::operator!=(const KeyboardEvent& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const KeyboardEvent& event)
{
	time_t stamp = event.getTimestamp();
	output << std::ctime(&stamp) << " Key " << (event.isDown() ? "Down" : "Up") << ": ";
	if ((event.getModifiers() & KMOD_LSHIFT) != 0)
	{
		output << "LShift + ";
	}
	if ((event.getModifiers() & KMOD_RSHIFT) != 0)
	{
		output << "RShift + ";
	}
	if ((event.getModifiers() & KMOD_LCTRL) != 0)
	{
		output << "LCtrl + ";
	}
	if ((event.getModifiers() & KMOD_RCTRL) != 0)
	{
		output << "RCtrl + ";
	}
	if ((event.getModifiers() & KMOD_LALT) != 0)
	{
		output << "LAlt + ";
	}
	if ((event.getModifiers() & KMOD_RALT) != 0)
	{
		output << "RAlt + ";
	}
	if ((event.getModifiers() & KMOD_LGUI) != 0)
	{
		output << "LGui + ";
	}
	if ((event.getModifiers() & KMOD_RGUI) != 0)
	{
		output << "RGui + ";
	}
	if ((event.getModifiers() & KMOD_NUM) != 0)
	{
		output << "NumLock + ";
	}
	if ((event.getModifiers() & KMOD_CAPS) != 0)
	{
		output << "CapsLock + ";
	}
	if ((event.getModifiers() & KMOD_MODE) != 0)
	{
		output << "AltGr + ";
	}
	return output << SDL_GetKeyName(event.getKey());
}
