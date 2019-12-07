#pragma once


#include "G_Tile.h"
#include <math.h>
#include <time.h>
#include "Surfaces.h"


class G_Board
{

private: 

	G_Tile Board[8][8];

	W_Window* Window; 
	W_Window* p_win;
	int rotation; 
	int size[6] = {50,50,60,60,20,20};

	int xShift, yShift;


	Surfaces surf;

public:


private:
	void init(); 
	void subInit();
	TileType tileTypeSelect(int random); 


public:

	G_Board(W_Window* Window);
	void checkRotation(int mousex, int mousey); 
	void draw(); 
	void shiftManager(int mousex, int mousey);
	void shiftRow(bool right);
	void shiftColumn(bool down);

};

