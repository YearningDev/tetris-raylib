#include "Board.h"
#include <assert.h>
Board::Cell::Cell()
	:
	bExists(false),
	c(WHITE)
{
}

void Board::Cell::SetColor(Color c_in)
{
	c = c_in;
	bExists = true;
}

void Board::Cell::Remove()
{
	bExists = false;
}

Color Board::Cell::GetColor() const
{
	return c;
}

Board::Board(int screenX, int screenY, int width_in, int height_in, int cellsize_in, int padding)
	:
	screenX(screenX),
	screenY(screenY),
	width(width_in),
	height(height_in),
	cellSize(cellsize_in),
	padding(padding)
{
	assert(width > 0 && height > 0); //If assertion triggers : The width or height is smaller than 1
	assert(cellSize > 0); //If assertion triggers : The cell size is smaller than 1
	cells.resize(width*height);
}

void Board::SetCell(int x, int y, Color c)
{
	assert(x >= 0 && y >= 0 && x < width && y < height);//If assertion triggers : x or y is out of bounds
	cells[y * width + x].SetColor(c);
}

void Board::DrawCell(int x, int y) const
{
	assert(x >= 0 && x < width && y >= 0 && y < height); //If assertion triggers : x or y is out of bounds
	Color c = cells[y * width + x].GetColor();
	DrawRectangle(screenX + x * cellSize + padding,
				screenY + y * cellSize + padding,
				cellSize - padding,
				cellSize - padding,c);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; ++iY)
	{
		for (int iX = 0; iX < width; ++iX)
		{
			DrawCell(iX,iY);
		}
	}
}
