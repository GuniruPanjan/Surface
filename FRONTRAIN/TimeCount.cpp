#include "TimeCount.h"
#include "DxLib.h"

TimeCount::TimeCount():
	cnt(0),
	test(0)
{
	time = GetNowCount();    //Œ»İŠÔ‚ğ“¾‚é
	
}

TimeCount::~TimeCount()
{
}

void TimeCount::InitTime()
{
}

void TimeCount::UpdateTime(Point& point)
{
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
		DrawFormatString(300, 0, GetColor(0, 0, 0), "Œo‰ßŠÔ:%d", (GetNowCount() - time) / 1000);
	}
	
}
