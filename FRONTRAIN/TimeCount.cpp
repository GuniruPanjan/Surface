#include "TimeCount.h"
#include "DxLib.h"

TimeCount::TimeCount():
	cnt(0),
	test(0),
	EnemyTime(0),
	timenow(0),
	SaveTime(0)
{
	time = GetNowCount();    //Œ»İŠÔ‚ğ“¾‚é
	
}

TimeCount::~TimeCount()
{
}

void TimeCount::InitTime()
{

	EnemyTime = 0;
	time = 0;
	time = GetNowCount(); //Œ»İŠÔ‚ğ“¾‚é
	timenow = 0;
	SaveTime = 0;
}

void TimeCount::UpdateTime(Point& point)
{
	EnemyTime = (GetNowCount() - time) / 1000;

	timenow = (GetNowCount() - time) / 1000;

	if (GetNowCount() - time <= 1000)
	{
		flg = true;
	}

	point.PointNow = timenow * 10;
}

void TimeCount::DrawTime()
{
	SaveTime = (GetNowCount() - time) / 1000;

	DrawFormatString(250, 0, GetColor(0, 0, 0), "Œo‰ßŠÔ:%d", SaveTime);

}
