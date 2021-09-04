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

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellsize_in, int padding)
	:
	screenPos(screenPos),
	width(widthHeight.GetX()),
	height(widthHeight.GetY()),
	cellSize(cellsize_in),
	padding(padding)
{
	assert(width > 0 && height > 0); //If assertion triggers : The width or height is smaller than 1
	assert(cellSize > 0); //If assertion triggers : The cell size is smaller than 1
	cells.resize(width*height);
}

void Board::SetCell(Vec2<int> pos, Color c)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height);//If assertion triggers : x or pos.GetY() is out of bounds
	cells[pos.GetY() * width + pos.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> pos) const
{
	assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height); //If assertion triggers : pos.GetX() or pos.GetY() is out of bounds
	Color c = cells[pos.GetY() * width + pos.GetX()].GetColor();
	Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
	DrawRectangle(topLeft.GetX(),
				topLeft.GetY(),
				cellSize - padding,
				cellSize - padding,c);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; ++iY)
	{
		for (int iX = 0; iX < width; ++iX)
		{
			DrawCell({iX,iY});
		}
	}
}
