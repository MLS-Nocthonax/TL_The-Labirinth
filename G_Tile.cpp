#include "G_Tile.h"




G_Tile::G_Tile(Surfaces*surf, W_Window* _Window, TileType type, int RectSize[6]) :
	surf(surf),Window(_Window),type(type)
{

	if (!init(RectSize)) {
		std::cerr << "Failed to initialise Tile class! SDL Error: " << SDL_GetError() << std::endl; 
	}
	else {
		prepareTexture();
	}

}

G_Tile::G_Tile() {

}




bool G_Tile::init(int RectSize[]) {

	
	if (!(_TempSurface = IMG_Load("../res/blitter.png"))) {
		std::cerr << "Failed to initialise _TempSurface! SDL Error: " << SDL_GetError() << std::endl;
		return 0;
	}


	_DestinationRect = {RectSize[0], RectSize[1], RectSize[2], RectSize[3] };
	_Rect = { 0,0, RectSize[4], RectSize[5] };

	

	switch (type) {


	case T_LINE:
	{int matrix1[3][3] = { {0,0,0}, {1,1,1}, {0,0,0} };
	memcpy(tileMatrix, matrix1, sizeof(matrix1)); }
		break;
	case T_TURN:
	{int matrix2[3][3] = { {0,0,0}, {1,1,0}, {0,1,0} };
	memcpy(tileMatrix, matrix2, sizeof(matrix2)); }
		break;
	case T_PLUS:
	{int matrix3[3][3] = { {0,1,0}, {1,1,1}, {0,1,0} };
	memcpy(tileMatrix, matrix3, sizeof(matrix3)); }
		break;
	case T_TSHAPE:
	{int matrix4[3][3] = { {0,0,0}, {1,1,1}, {0,1,0} };
	memcpy(tileMatrix, matrix4, sizeof(matrix4)); }
		break;

	};


	for (int i = 0; i < rotation; ++i) {
		rotate();
	}

	return 1;
}

void G_Tile::prepareTexture()
{

	

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {

			_Rect.x = _Rect.w * j;
			_Rect.y = _Rect.h * i;


			if(tileMatrix[i][j]==1){
				SDL_BlitSurface(surf->_PathSurface, NULL, _TempSurface, &_Rect);
			}
			else if (tileMatrix[i][j] == 0) {
				SDL_BlitSurface(surf->_GrassSurface, NULL, _TempSurface, &_Rect);
			}
			

		}
	}

	SDL_BlitSurface(surf->_FrameSurface, NULL, _TempSurface, NULL);

}

void G_Tile::rotate()
{
	//swap 1st and 3rd row, transpose
	int temp;
	int trans[3][3];

	for (int j = 0; j < 3; ++j) {
		temp = tileMatrix[0][j];
		tileMatrix[0][j] = tileMatrix[2][j];
		tileMatrix[2][j] = temp;
	}

	for (int i = 0; i < 3; ++i) {
		for (int z = 0; z < 3; ++z)
		{
			trans[z][i] = tileMatrix[i][z];
		}
	}

	rotation += 1;
	if (rotation > 3) {
		rotation = 0;
	}

	memcpy(tileMatrix, trans, sizeof(trans));

}

void G_Tile::draw() {

	SDL_Texture* _TileTexture = nullptr;

	_TileTexture = SDL_CreateTextureFromSurface(Window->getRend(), _TempSurface);

	if (_TileTexture == nullptr) {
		std::cerr << "Failed to initialise _TileTexture! SDL Error: " << SDL_GetError() << std::endl;
	}

	SDL_RenderCopy(Window->getRend(), _TileTexture, NULL, &_DestinationRect);
	SDL_DestroyTexture(_TileTexture);
	

}

void G_Tile::moveRendDest(int xOffset, int yOffset)
{

	_DestinationRect.x = xOffset;
	_DestinationRect.y = yOffset;
}

void G_Tile::destroy()
{
	SDL_FreeSurface(_TempSurface);
}