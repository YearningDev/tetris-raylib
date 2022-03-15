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

bool Board::Cell::Exists() const
{
	return bExists;
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
	raycpp::DrawRectangle(topLeft, Vec2{cellSize,cellSize} - padding,c);
}

void Board::DrawBorder() const
{
	raycpp::DrawRectangleLinesEx(screenPos - (cellSize/2),
								 Vec2{width*cellSize,height*cellSize} + cellSize,
								 cellSize/2,
								 WHITE);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; ++iY)
	{
		for (int iX = 0; iX < width; ++iX)
		{
			if (CellExists({ iX,iY }))
			{
				DrawCell({ iX,iY });
			}
		}
	}
	DrawBorder();
}

bool Board::CellExists(Vec2<int> pos) const
{
	return cells[pos.GetY()*width + pos.GetX()].Exists();
}
