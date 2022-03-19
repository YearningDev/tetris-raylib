#include "Tetrominoes.h"

Tetromino::Tetromino(const bool* shape, int dimension, Color color, const Board& board)
	:
	shape(shape),
	dimension(dimension),
	color(color),
	boardPos(board.GetWidth()/2 - dimension/2, 0),
	board(board),
	currentRotation(Rotation::UP)
{
}

void Tetromino::RotateClockwise()
{
	currentRotation = Rotation((int(currentRotation) + 1) % 4);
}

void Tetromino::RotateCounterClockwise()
{
	if (currentRotation == Rotation::UP)
	{
		currentRotation = Rotation::LEFT;
	}
	else
	{
		currentRotation = Rotation(int(currentRotation) - 1);
	}
}

void Tetromino::Draw() const
{
	for (int y = 0; y < dimension; ++y)
	{
		for (int x = 0; x < dimension; ++x)
		{
			bool cell = false;
			switch (currentRotation)
			{
			case Tetromino::Rotation::UP:
				cell = shape[y * dimension + x];
				break;
			case Tetromino::Rotation::RIGHT:
				cell = shape[dimension * (dimension - 1) - dimension * x + y];
				break;
			case Tetromino::Rotation::DOWN:
				cell = shape[(dimension * dimension - 1) - dimension * y - x];
				break;
			case Tetromino::Rotation::LEFT:
				cell = shape[dimension - 1 + dimension * x - y];
				break;
			default:
				break;
			}
			if (cell)
			{
				board.DrawCell(boardPos + Vec2<int>{x,y}, color);
			}
		}
	}
}
