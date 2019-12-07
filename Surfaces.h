#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

static struct Surfaces {

	

	 SDL_Surface* _GrassSurface;
	 SDL_Surface* _PathSurface;
	 SDL_Surface* _FrameSurface;


	bool init() {
		if (!(_GrassSurface = IMG_Load("../res/grasstile.png"))) {
			std::cerr << "Failed to initialise _GrassSurface! SDL Error: " << SDL_GetError() << std::endl;
			return 0;
		}


		if (!(_PathSurface = IMG_Load("../res/pathtile.png"))) {
			std::cerr << "Failed to initialise _PathSurface! SDL Error: " << SDL_GetError() << std::endl;
			return 0;
		}

		

		if (!(_FrameSurface = IMG_Load("../res/frame.png"))) {
			std::cerr << "Failed to initialise _FrameSurface! SDL Error: " << SDL_GetError() << std::endl;
			return 0;
		}

	}

};