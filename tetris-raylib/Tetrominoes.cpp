#include "Tetrominoes.h"

Tetromino::Tetromino(const bool* shape, int dimension, Color color, const Board& board)
	:
	shape(shape),
	dimension(dimension),
	color(color),
	boardPos(board.GetWidth()/2 - dimension/2, 0),
	board(board)
{
}

void Tetromino::Draw() const
{
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			bool cell = shape[y * dimension + x];
			if (cell)
			{
				board.DrawCell(boardPos + Vec2<int>{x,y});
			}
		}
	}
}
