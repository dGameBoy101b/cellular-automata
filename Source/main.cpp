#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include <iostream>

/** Check if the given event should close the application
\param event The event to process
\return True if the application should now exit
*/
bool shouldExit(const SDL_Event& event)
{
	return event.type == SDL_QUIT
		|| (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE);
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

	auto main_window = SDL_CreateWindow("Cellular Automata", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
	if (main_window == NULL)
	{
		std::cout << SDL_GetError();
		SDL_Quit();
		return -1;
	}

	SDL_Event event;
	while (true)
	{
		if (SDL_PollEvent(&event) == 1 && shouldExit(event))
		{
			std::cout << "Exiting..." << std::endl;
			SDL_Quit();
			return 0;
		}
	}
}
