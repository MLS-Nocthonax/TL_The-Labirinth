#include <iostream>


#include <SDL.h>
#include <SDL_image.h>

#include "W_Window.h"
#include "E_PollEvents.h"
#include "G_Board.h"


bool SDLSetup(); 

int main(int argc, char **args) {


	if (!SDLSetup()) {
		return 0;
	}

	//construct objects
	W_Window Window("TL_The Labirinth", 480, 480);
	G_Board Board(&Window);

	E_PollEvents poll(&Window, &Board);
	
	/*
	-~~~~~~~~~~~~~~~//!!oOo!!// GAME LOOP //!!oOo!!//~~~~~~~~~~~~~~~-
	*/

	while (!Window.getB_Closed()) {

		poll.globalEvents(); //check inputs
		Window.draw(); //render everything in windows renderer
	}


	SDL_Quit();

	return 0; 
}

bool SDLSetup() {


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Failed to initialise SDL2_EVERYTHING!  SDL Error: " << SDL_GetError() << std::endl;
		return 0;
	}
	else {
		std::cout << "Sucessfully initialised SDL2 " << std::endl;

	}

	if (IMG_Init(IMG_INIT_PNG) < 0) {
		std::cout << "FAILED initialising SDL2_Image! SDL_Error: " << SDL_GetError() << std::endl;
		return 0;
	}
	else {
		std::cout << "Succesfull SDL2_Image init" << std::endl;
	}

	return 1;
}