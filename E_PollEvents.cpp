#include "E_PollEvents.h"


E_PollEvents::E_PollEvents(W_Window* Window, G_Board* Board): 
	Window(Window), Board(Board)
{
	std::cout << "Event poll created" << std::endl;
}


void E_PollEvents::globalEvents()
{

	SDL_Event _Event;

	//load a queue of system breaks from machine (inputs), store them in _Event
	if (SDL_PollEvent(&_Event)) {


		//if X button of window is pressed 
		if (_Event.type == SDL_QUIT) {

			Window->setB_Closed(1);
		}

		//do different actions for different types of events
		switch (_Event.type) {


		//if any key on keyboard is pressed, ANY
		case SDL_KEYDOWN:


			if (_Event.key.keysym.sym == SDLK_r) {
				Board->checkRotation(mouseX, mouseY);
			}
			std::cout << "I MANAGED TO READ PRESSED BUTTON" << std::endl;
			break;


		case SDL_MOUSEMOTION:
			mouseX = _Event.motion.x;
			mouseY = _Event.motion.y;

			break;


		case SDL_MOUSEBUTTONDOWN:

				if (_Event.button.button == SDL_BUTTON_LEFT) {
					Board->shiftManager(mouseX, mouseY);
				}
				break;

		}
	}
}