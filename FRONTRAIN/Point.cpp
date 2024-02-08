#include "Point.h"
#include "GraphMode.h"
#include "DxLib.h"


Point::Point():
	PointNow(0),
	WenemyPoint(0),
	SenemyPoint(0),
	DenemyPoint(0),
	MovePoint(0),
	PlayerMove(0),
	DistancePoint(0),
	PointPoint(0)
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
	PlayerMove = 1;
	MovePoint = 0;

	DistancePoint = 0;
	PointPoint = 0;
}

void Point::UpdatePoint(Player& player,int ScrollX)
{
	if (-ScrollX == 1000 * PlayerMove)
	{
		MovePoint += 10;

		PlayerMove++;
	}
}

void Point::DrawPoint(Player& player,int ScrollX)
{
	DistancePoint = -ScrollX / 100;

	PointPoint = PointNow + WenemyPoint + SenemyPoint + DenemyPoint + MovePoint;

	//影落とし
	DrawFormatString(432, 32, GetColor(0, 0, 0), "移動距離 : %dm", DistancePoint);
	DrawFormatString(430, 30, GetColor(255, 255, 255), "移動距離 : %dm", DistancePoint);
	
	//影落とし
	DrawFormatString(232, 62, GetColor(0, 0, 0), "ポイント : %d", PointPoint);
	DrawFormatString(230, 60, GetColor(255, 255, 255), "ポイント : %d", PointPoint);
}
