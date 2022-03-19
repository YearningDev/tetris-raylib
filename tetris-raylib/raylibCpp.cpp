#include "raylibCpp.h"
#include <assert.h>
void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
		   pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //If assertion triggers : Trying to draw outisde of the screen
	DrawRectangle(pos.GetX(),pos.GetY(),widthHeight.GetX(),widthHeight.GetY(),color);
}

void raycpp::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, int lineThick, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
		pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //If assertion triggers : Trying to draw outisde of the screen
	assert(lineThick > 0); //If assertion triggers : line thickness is less than 1
	DrawRectangleLinesEx({(float)pos.GetX(),(float)pos.GetY(), (float)widthHeight.GetX(), (float)widthHeight.GetY()}, (float)lineThick, color);
}
