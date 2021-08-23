#include "Game.h"
#include "raylib.h"
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game{screenWidth,screenHeight, "Tetris Raylib"};
    return 0;
}