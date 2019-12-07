#pragma once

#include <iostream>
#include "G_TypeEnum.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Surfaces.h"


#include "W_Window.h"

class G_Tile
{

private:

	W_Window* Window = nullptr;

	SDL_Surface* _TempSurface;

	SDL_Rect _Rect;
	SDL_Rect _DestinationRect;

	Surfaces* surf; 


	int tileMatrix[3][3];

	int rotation=0; 
	TileType type; 

public:


private:
	
	bool init(int _DestRect[]);
	
	

public:

	G_Tile(Surfaces* surf, W_Window* _Window, TileType type, int RectSize[6]);
	G_Tile();

	void draw(); 
	void rotate();
	void prepareTexture();
	void moveRendDest(int xOffset, int yOffset); 
	int getRenderDestX() { return _DestinationRect.x; }
	int getRenderDestY() { return _DestinationRect.y; }
	TileType getType() { return type; }
	void destroy();


	void setRotation(int rot) { rotation = rot; }
	int getRotation() { return rotation; }

};

