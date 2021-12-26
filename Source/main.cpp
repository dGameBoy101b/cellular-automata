#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL/Video/window.hpp"
#include "SDL/Events/event_queue.hpp"
#include "SDL/Events/event.hpp"
#include "SDL/Events/quit_event.hpp"
#include "SDL/Events/keyboard_event.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace CellularAutomata;

/** The main window */
SDL::Video::Window main_window;

/** Check if the given event should close the application
\param event The event to process
\return True if the application should now exit
*/
bool shouldQuit(const SDL::Events::Event& event)
{
	return event.getType() == SDL_QUIT
		|| (event.getType() == SDL_KEYDOWN
			&& SDL::Events::KeyboardEvent(event).getKey() == SDLK_ESCAPE);
}

/** Quit the application */
void quit()
{
	std::cout << "Exiting..." << std::endl;
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

/** Check if the given event should trigger a fullscreen toggle
\param event The event to check
\return True when the application should now toggle it fullscreen
*/
bool shouldToggleFullscreen(const SDL::Events::Event& event)
{
	return (event.getType() == SDL_KEYDOWN && SDL::Events::KeyboardEvent(event).getKey() == SDLK_f);
}

/** Toggle between fullscreen for the main window */
void toggleFullscreen()
{
	if (main_window.isFullscreen())
	{
		std::cout << "Exiting fullscreen..." << std::endl;
	}
	else
	{
		std::cout << "Entering fullscreen..." << std::endl;
	}
	main_window.toggleFullscreen();
}

int main(int argc, char** argv)
{
	SDL_SetMainReady();
	int error = SDL_InitSubSystem(SDL_INIT_VIDEO);
	if (error != 0)
	{
		std::cout << SDL_GetError();
		SDL_Quit();
		return error;
	}

	try
	{
		main_window.create({1280, 720}, "Cellular Automata", {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
	}
	catch (const std::runtime_error& x)
	{
		std::cout << x.what() << std::endl;
		SDL_Quit();
		return -1;
	}

	SDL::Events::Event event;
	while (true)
	{
		if (SDL::Events::isEventQueued())
		{
			try
			{
				event = SDL::Events::pollNextEvent();
			}
			catch (const std::exception& x)
			{
				std::cout << x.what() << std::endl;
				continue;
			}
			if (shouldQuit(event))
			{
				quit();
			}
			if (shouldToggleFullscreen(event))
			{
				toggleFullscreen();
			}
		}
	}
}
