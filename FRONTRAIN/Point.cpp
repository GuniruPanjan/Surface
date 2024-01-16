#include "Point.h"
#include "GraphMode.h"
#include "DxLib.h"


Point::Point():
	PointNow(0),
	WenemyPoint(0),
	SenemyPoint(0),
	DenemyPoint(0)
{

}

Point::~Point()
{
}

void Point::InitPoint()
{
	WenemyPoint = 0;
	SenemyPoint = 0;
	DenemyPoint = 0;
}

void Point::UpdatePoint()
{
}

void Point::DrawPoint(int ScrollX)
{
	DrawFormatString(300, 460, GetColor(255, 255, 255), "�|�C���g:%d", PointNow + WenemyPoint + SenemyPoint + DenemyPoint);
}
