#include "TimeCount.h"
#include "DxLib.h"

TimeCount::TimeCount():
	cnt(0),
	test(0),
	EnemyTime(0),
	timenow(0),
	SaveTime(0)
{
	time = GetNowCount();    //���ݎ��Ԃ𓾂�
	
}

TimeCount::~TimeCount()
{
}

void TimeCount::InitTime()
{
	EnemyTime = 0;
	time = 0;
	time = GetNowCount(); //���ݎ��Ԃ𓾂�
	timenow = 0;
	SaveTime = 0;
}

void TimeCount::UpdateTime(Point& point)
{
	timenow = (GetNowCount() - time) / 1000;

	if (GetNowCount() - time <= 1000)
	{
		flg = true;
	}

	point.PointNow = timenow * 10;

	EnemyTime = ((GetNowCount() - time) / 1000);
	
}

void TimeCount::DrawTime()
{
	SaveTime = (GetNowCount() - time) / 1000;

	//�e���Ƃ�
	DrawFormatString(242, 12, GetColor(0, 0, 0), "�^�C�� : %d", SaveTime);
	DrawFormatString(240, 10, GetColor(255, 255, 255), "�^�C�� : %d", SaveTime);

}
