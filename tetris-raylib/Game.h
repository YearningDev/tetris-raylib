#pragma once
#include <string>
#include "Board.h"
#include "Tetrominoes.h"
class Game
{
public:
	Game(int width, int height, int fps, std::string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool GameShouldClose() const;
	void Tick();
private:
	void Update();
	void Draw();

	Board board;
	Jay tetromino;
};