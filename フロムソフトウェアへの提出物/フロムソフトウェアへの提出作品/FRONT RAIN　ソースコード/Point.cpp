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
	PointPoint(0),
	PointShop(0),
	ScoreWhiteColor(0),
	ScoreBlackColor(0),
	AdditionMove(0)
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
	PointShop = 0;

	ScoreWhiteColor = GetColor(255, 255, 255);
	ScoreBlackColor = GetColor(0, 0, 0);

	AdditionMove = 100;
}

void Point::UpdatePoint(Player& player,int ScrollX)
{
	//�v���C���[�̈ړ������̎Z�o
	if (-ScrollX == 500 * PlayerMove)
	{
		MovePoint += AdditionMove;

		PlayerMove++;
	}

	DistancePoint = -ScrollX / 50;

	//�����|�C���g
	PointPoint = PointNow + WenemyPoint + SenemyPoint + DenemyPoint + MovePoint + PointShop;
}

void Point::DrawPoint(Player& player,int ScrollX)
{

	//�e���Ƃ�
	DrawFormatString(432, 32, ScoreBlackColor, "�ړ����� : %dm", DistancePoint);
	DrawFormatString(430, 30, ScoreWhiteColor, "�ړ����� : %dm", DistancePoint);
	
	//�e���Ƃ�
	DrawFormatString(232, 62, ScoreBlackColor, "�|�C���g : %d", PointPoint);
	DrawFormatString(230, 60, ScoreWhiteColor, "�|�C���g : %d", PointPoint);
}
