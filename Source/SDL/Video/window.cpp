#include "window.hpp"
#include <stdexcept>

using namespace CellularAutomata::SDL::Video;

Window::Window(SDL_Window* window)
{
	this->window = window;
}

SDL_Window* Window::getWindow() const
{
	return this->window;
}

Window::Window(const CellularAutomata::Data::Position<int>& size, const std::string& title, const CellularAutomata::Data::Position<int>& position, const uint32_t& flags)
{
	this->window = nullptr;
	this->create(size, title, position, flags);
}

Window::~Window()
{
	if (this->window != nullptr)
	{
		this->destroy();
	}
}

void Window::create(const CellularAutomata::Data::Position<int>& size, const std::string& title, const CellularAutomata::Data::Position<int>& position, const uint32_t& flags)
{
	if (this->window != nullptr)
	{
		throw std::domain_error("Window already exists");
	}
	this->window = SDL_CreateWindow(title.c_str(), position.getX(), position.getY(), size.getX(), size.getY(), flags);
	if (this->window == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

bool Window::doesExist() const
{
	return this->window != nullptr;
}

void Window::existCheck() const
{
	if (this->window == nullptr)
	{
		throw std::domain_error("Window does not exist");
	}
}

void Window::destroy()
{
	this->existCheck();
	SDL_DestroyWindow(this->window);
	this->window = nullptr;
}

bool Window::hasFlag(const SDL_WindowFlags& flag) const
{
	return (SDL_GetWindowFlags(this->window) & flag) != 0;
}

void Window::flashOnce()
{
	this->existCheck();
	if (SDL_FlashWindow(this->window, SDL_FLASH_BRIEFLY) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

void Window::startFlashing()
{
	this->existCheck();
	if (SDL_FlashWindow(this->window, SDL_FLASH_UNTIL_FOCUSED) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

void Window::stopFlashing()
{
	this->existCheck();
	if (SDL_FlashWindow(this->window, SDL_FLASH_CANCEL) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

std::string Window::getTitle() const
{
	this->existCheck();
	return std::string(SDL_GetWindowTitle(this->window));
}

void Window::setTitle(const std::string& title)
{
	this->existCheck();
	SDL_SetWindowTitle(this->window, title.c_str());
}

CellularAutomata::Data::Position<int> Window::getPosition() const
{
	this->existCheck();
	int x, y;
	SDL_GetWindowPosition(this->window, &x, &y);
	return CellularAutomata::Data::Position<int>(x, y);
}

void Window::setPosition(const CellularAutomata::Data::Position<int>& position)
{
	this->existCheck();
	SDL_SetWindowPosition(this->window, position.getX(), position.getY());
}

CellularAutomata::Data::Position<int> Window::getSize() const
{
	this->existCheck();
	int width, height;
	SDL_GetWindowSize(this->window, &width, &height);
	return CellularAutomata::Data::Position<int>(width, height);
}

void Window::setSize(const CellularAutomata::Data::Position<int>& size)
{
	this->existCheck();
	SDL_SetWindowSize(this->window, size.getX(), size.getY());
}

CellularAutomata::Data::Bounds<CellularAutomata::Data::Position<int>> Window::getSizeBounds() const
{
	this->existCheck();
	int min_width, min_height, max_width, max_height;
	SDL_GetWindowMinimumSize(this->window, &min_width, &min_height);
	SDL_GetWindowMaximumSize(this->window, &max_width, &max_height);
	return CellularAutomata::Data::Bounds<CellularAutomata::Data::Position<int>>({min_width, min_height}, {max_width, max_height});
}

void Window::setSizeBounds(const CellularAutomata::Data::Bounds<CellularAutomata::Data::Position<int>>& bounds)
{
	this->existCheck();
	SDL_SetWindowMinimumSize(this->window, bounds.getMin().getX(), bounds.getMin().getY());
	SDL_SetWindowMaximumSize(this->window, bounds.getMax().getX(), bounds.getMax().getY());
}

float Window::getOpacity() const
{
	this->existCheck();
    float opacity;
	if (SDL_GetWindowOpacity(this->window, &opacity) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
	return opacity;
}

void Window::setOpacity(const float& opacity)
{
	this->existCheck();
	if (opacity < 0)
	{
		throw std::invalid_argument("Opacity cannot be lesser than 0");
	}
	if (opacity > 1)
	{
		throw std::invalid_argument("Opacity cannot be greater than 1");
	}
	if (SDL_SetWindowOpacity(this->window, opacity) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

void Window::hide()
{
	this->existCheck();
	SDL_HideWindow(this->window);
}

void Window::show()
{
	this->existCheck();
	SDL_ShowWindow(this->window);
}

void Window::raise()
{
	this->existCheck();
	SDL_RaiseWindow(this->window);
}

void Window::maximise()
{
	this->existCheck();
	SDL_MaximizeWindow(this->window);
}

void Window::minimise()
{
	this->existCheck();
	SDL_MinimizeWindow(this->window);
}

void Window::restore()
{
	this->existCheck();
	SDL_RestoreWindow(this->window);
}

uint32_t Window::getFullscreen() const
{
	this->existCheck();
	return SDL_GetWindowFlags(this->window) & (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Window::setFullscreen(const uint32_t& mode)
{
	this->existCheck();
	switch (mode)
	{
	case SDL_WINDOW_FULLSCREEN:
	case SDL_WINDOW_FULLSCREEN_DESKTOP:
	case 0u:
		if (SDL_SetWindowFullscreen(this->window, mode) != 0)
		{
			throw std::runtime_error(SDL_GetError());
		}
		break;
	default:
		throw std::invalid_argument("Invalid fulscreen mode");
	}
}

bool Window::hasGrabbedMouse() const
{
	this->existCheck();
	return SDL_GetWindowMouseGrab(this->window) == SDL_TRUE;
}

void Window::grabMouse()
{
	this->existCheck();
	SDL_SetWindowMouseGrab(this->window, SDL_TRUE);
}

void Window::releaseMouse()
{
	this->existCheck();
	SDL_SetWindowMouseGrab(this->window, SDL_FALSE);
}
bool Window::hasGrabbedKeyboard() const
{
	this->existCheck();
	return SDL_GetWindowKeyboardGrab(this->window) == SDL_TRUE;
}

void Window::grabKeyboard()
{
	this->existCheck();
	SDL_SetWindowKeyboardGrab(this->window, SDL_TRUE);
}

void Window::releaseKeyboard()
{
	this->existCheck();
	SDL_SetWindowKeyboardGrab(this->window, SDL_FALSE);
}

bool Window::hasBorder() const
{
	this->existCheck();
	return (SDL_GetWindowFlags(this->window) & SDL_WINDOW_BORDERLESS) == 0;
}

void Window::addBorder()
{
	this->existCheck();
	SDL_SetWindowBordered(this->window, SDL_TRUE);
}

void Window::removeBorder()
{
	this->existCheck();
	SDL_SetWindowBordered(this->window, SDL_FALSE);
}

bool Window::isResizable() const
{
	this->existCheck();
	return (SDL_GetWindowFlags(this->window) & SDL_WINDOW_RESIZABLE) != 0;
}

void Window::enableResizing()
{
	this->existCheck();
	SDL_SetWindowResizable(this->window, SDL_TRUE);
}

void Window::disableResizing()
{
	this->existCheck();
	SDL_SetWindowResizable(this->window, SDL_FALSE);
}
