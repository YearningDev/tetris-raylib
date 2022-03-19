#pragma once
#include "raylibCpp.h"
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
		bool Exists() const;
		Color GetColor() const;
	private:
		bool bExists;
		Color c;
	};
public:
	
	Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellsize_in, int padding);
	void SetCell(Vec2<int> pos, Color c);
	void DrawCell(Vec2<int> pos) const;
	void DrawCell(Vec2<int> pos, Color color) const;
	void DrawBorder() const;
	void Draw() const;
	bool CellExists(Vec2<int> pos) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding;
	Vec2<int> screenPos;
};