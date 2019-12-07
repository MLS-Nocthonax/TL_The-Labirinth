#pragma once

#include "W_Window.h"
#include "G_Board.h"
#include <iostream>


class E_PollEvents
{

private:
	W_Window* Window;
	G_Board* Board;

	int mouseX, mouseY;

public:

	E_PollEvents(W_Window* window, G_Board* Board);
	void globalEvents();

};

