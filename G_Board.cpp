#include "G_Board.h"


G_Board::G_Board(W_Window* Window): Window(Window)
{
	surf.init();
	srand(time(NULL));
	init(); 

}



void G_Board::init() 
{
	
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {


			

			size[0] = size[2] * j;
			size[1] = size[3] * i;

			G_Tile Tile(&surf, Window, tileTypeSelect(rand() % 3 + 0), size);
			Tile.setRotation(rand() % 3 + 0);

			Board[i][j].destroy();
			Board[i][j] = Tile;
		}
	}

	draw();

}

TileType G_Board::tileTypeSelect(int random)
{

	switch (random) {

	case 0:
		return T_TURN;
		
	case 1: 
		return T_LINE;

	case 2: 
		return T_TSHAPE;

	case 3: 
		return T_PLUS;
	}
	
}


void G_Board::checkRotation(int mousex, int mousey)
{


	std::cout << "X|Y: " << mousex << "|" << mousey << std::endl << mousex / size[2] << "|" <<mousey / size[2] << std::endl;
	Board[mousey / size[2]][mousex / size[2]].rotate();
	Board[mousey / size[2]][mousex / size[2]].prepareTexture();
	Board[mousey / size[2]][mousex / size[2]].draw();
}

void G_Board::draw()
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			Board[i][j].draw();
		}
	}
}


void G_Board::shiftManager(int mousex, int mousey)
{


	xShift = mousex / size[2];
	yShift = mousey / size[3];

	if (yShift != 0 && yShift != 7) {
		if (xShift == 0) {
			std::cout << "X|Y: " << mousex << "|" << mousey << std::endl << mousex / size[2] << std::endl;
			shiftRow(1);
		}
		else if (xShift == 7) {
			std::cout << "X|Y: " << mousex << "|" << mousey << std::endl << mousex / size[2] << std::endl;
			shiftRow(0);
		}
	}

	if (xShift != 0 && xShift != 7) {
		if (yShift == 0) {
			shiftColumn(1);
		}
		else if (yShift == 7) {
			shiftColumn(0);
		}
	}


}

void G_Board::subInit()
{


	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {

			size[0] = size[2] * j;
			size[1] = size[3] * i;

			G_Tile Tile(&surf, Window, Board[i][j].getType(), size);
			Tile.setRotation(Board[i][j].getRotation());

			Board[i][j].destroy();
			Board[i][j] = Tile;
		}
	}

	draw();

}

void G_Board::shiftRow(bool right)
{

	   G_Tile Temp;


	   if (right) {
		   Temp = Board[yShift][7];
		   for (int i = 7; i > 0; --i) {
			   std::cout << "X|Y: " << i << "|" << yShift << std::endl;

			   Board[yShift][i] = Board[yShift][i - 1];

		   }
		   Board[yShift][0] = Temp;
	   }
	   else {

		   Temp = Board[yShift][0];
		   for (int i = 0; i < 7; ++i) {
			   std::cout << "X|Y: " << i << "|" << yShift << std::endl;

			   Board[yShift][i] = Board[yShift][i+1];

		   }
		   Board[yShift][7] = Temp;

	   }

	   

		subInit();
}

void G_Board::shiftColumn(bool down) {

	G_Tile Temp;

	if (down) {

		Temp = Board[7][xShift];
		for (int i = 7; i > 0; --i) {
			std::cout << "X|Y: " << i << "|" << yShift << std::endl;

			Board[i][xShift] = Board[i-1][xShift];

		}
		Board[0][xShift] = Temp;
	}
	else {

		Temp = Board[0][xShift];
		for (int i = 0; i < 7; ++i) {
			std::cout << "X|Y: " << i << "|" << yShift << std::endl;

			Board[i][xShift] = Board[i+1][xShift];

		}
		Board[7][xShift] = Temp;

	}

	subInit();


}