#include "TimeCount.h"
#include "DxLib.h"

TimeCount::TimeCount():
	cnt(0),
	test(0),
	EnemyTime(0),
	timenow(0),
	SaveTime(0),
	TimeWhiteColor(0),
	TimeBlackColor(0)
{
	time = GetNowCount();    //現在時間を得る
	
}

TimeCount::~TimeCount()
{
}

void TimeCount::InitTime()
{
	EnemyTime = 0;
	time = 0;
	time = GetNowCount(); //現在時間を得る
	timenow = 0;
	SaveTime = 0;

	TimeWhiteColor = GetColor(255, 255, 255);
	TimeBlackColor = GetColor(0, 0, 0);
}

void TimeCount::UpdateTime(Point& point)
{
	//経過時間を得る
	timenow = (GetNowCount() - time) / 1000;

	if (GetNowCount() - time <= 1000)
	{
		flg = true;
	}

	point.PointNow = timenow * 10;

	//エネミーが出現する時間を計測
	EnemyTime = ((GetNowCount() - time) / 1000);
	
}

void TimeCount::DrawTime()
{
	//時間を保存するための代入
	SaveTime = (GetNowCount() - time) / 1000;

	//影落とし
	DrawFormatString(242, 12, TimeBlackColor, "タイム : %d", SaveTime);
	DrawFormatString(240, 10, TimeWhiteColor, "タイム : %d", SaveTime);

}
