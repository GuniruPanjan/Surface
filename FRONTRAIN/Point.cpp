#include "Point.h"
#include "GraphMode.h"
#include "DxLib.h"


Point::Point():
	PointNow(0)
{

}

Point::~Point()
{
}

void Point::InitPoint()
{
}

void Point::UpdatePoint()
{
}

void Point::DrawPoint()
{
	DrawFormatString(300, 460, GetColor(255, 255, 255), "ƒ|ƒCƒ“ƒg:%d", PointNow);
}
