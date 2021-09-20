#pragma once
#include "Vec2.h"
namespace settings
{
	//Window settings
	constexpr int screenWidth = 800;
	constexpr int screenHeight = 600;
	constexpr int fps = 60;

	//Board settings
	constexpr int cellSize = 23;
	constexpr int padding = 2;
	constexpr Vec2<int> boardPosition{ 250,70 };
	constexpr Vec2<int> boardWidthHeight{ 10,20 };
}