#include "TimeCount.h"
#include "DxLib.h"

TimeCount::TimeCount():
	cnt(0),
	test(0)
{
	time = GetNowCount();    //���ݎ��Ԃ𓾂�
	
}

TimeCount::~TimeCount()
{
}

void TimeCount::InitTime()
{
	WalkEnemyTime = 0;
	time = 0;
	time = GetNowCount(); //���ݎ��Ԃ𓾂�
}

void TimeCount::UpdateTime(Point& point)
{
	WalkEnemyTime = (GetNowCount() - time) / 1000;

	timenow = (GetNowCount() - time) / 1000;

	if (GetNowCount() - time <= 1000)
	{
		flg = true;
	}

	point.PointNow = timenow * 10;
}

void TimeCount::DrawTime()
{
	if (flg)
	{
		//DrawFormatString(300, 0, GetColor(0, 0, 0), "�o�ߎ���:%d", (GetNowCount() - time) / 1000);
	}
	DrawFormatString(300, 0, GetColor(0, 0, 0), "�o�ߎ���:%d", (GetNowCount() - time) / 1000);

}
