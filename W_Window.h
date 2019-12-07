#pragma once

#include <SDL.h>
#include <String>

#include <iostream>



class W_Window
{

	//private variables 
private:

	//pointer to window
	SDL_Window* _Window;

	SDL_Renderer* _Renderer;

	//window dimensions and title
	int width, length, xpos, ypos;


	const std::string title;
	bool b_closed;

	//public variables
public:

	//private fucntions

private:

	
	bool windowSetup(); //basic setup 


	//public functions
public:

	//construct & deconstructor
	W_Window(const std::string title, int width, int length);



	SDL_Window* getWindow() { return _Window; }
	SDL_Renderer* getRend() { return _Renderer; };

	
	void setB_Closed(bool state) { b_closed = state; }
	bool getB_Closed() { return b_closed; }
    
	void draw() { SDL_RenderPresent(_Renderer); }//render onto window
	
	
	std::string getTitle() { return title; }


};

