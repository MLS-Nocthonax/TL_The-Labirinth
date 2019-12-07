#include "W_Window.h"

W_Window::W_Window(const std::string title, int width, int length) :
	title(title), width(width), length(length)
{

	//initialisating and checking for initialisation success

	if (!windowSetup()) {
		b_closed = 1;
	}

	std::cout << "Window "<< title <<" constructed" << std::endl;

}



bool W_Window::windowSetup()
{
	//base function for creating windows, look up flags in the documentation
	_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, length, SDL_WINDOW_SHOWN);
	
	//check if window was initialised correctly
	if (_Window == nullptr) {
		std::cout << "Failed to create Window! " << title << " \nSDL_Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	//mark window as open (since it's initalised)
	b_closed = 0;

	//creates renderer for this window
	_Renderer = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_PRESENTVSYNC);

	//initialisation success check
	if (_Renderer == nullptr) {
		std::cout << "Failed to create Window! " << title << " \nSDL_Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	return 1;
}
