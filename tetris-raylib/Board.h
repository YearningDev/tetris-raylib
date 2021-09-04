#pragma once
#include <raylib.h>
#include <vector>
#include "Vec2.h"
class Board
{
private:
	class Cell
	{
	public:
		Cell();
		void SetColor(Color c_in);
		void Remove();

		Color GetColor() const;
	private:
		bool bExists;
		Color c;
	};
public:
	
	Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellsize_in, int padding);
	void SetCell(Vec2<int> pos, Color c);
	void DrawCell(Vec2<int> pos) const;
	void Draw() const;
private:
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding;
	Vec2<int> screenPos;
};