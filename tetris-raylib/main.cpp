#include "Game.h"
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{screenWidth,screenHeight,60, "Tetris Raylib"};

    while (!game.GameShouldClose())
    {
        game.Tick();
    }
    return 0;
}