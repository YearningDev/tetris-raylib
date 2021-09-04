#pragma once
#include <raylib.h>
#include <vector>
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
	
	Board(int screenX, int screenY, int width_in, int height_in, int cellsize_in, int padding);
	void SetCell(int x, int y, Color c);
	void DrawCell(int x, int y) const;
	void Draw() const;
private:
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding;
	int screenX;
	int screenY;
};