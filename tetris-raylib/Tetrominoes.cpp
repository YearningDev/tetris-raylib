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
