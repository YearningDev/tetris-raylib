#pragma once
#include "Vec2.h"
namespace settings
{
	//Window settings
	inline constexpr int screenWidth = 800;
	inline constexpr int screenHeight = 600;
	inline constexpr int fps = 60;

	//Board settings
	inline constexpr int cellSize = 23;
	inline constexpr int padding = 2;
	inline constexpr Vec2<int> boardPosition{ 250,70 };
	inline constexpr Vec2<int> boardWidthHeight{ 10,20 };
}