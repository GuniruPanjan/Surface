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

	TimeWhiteColor = GetColor(255, 255, 255);
	TimeBlackColor = GetColor(0, 0, 0);
}

void TimeCount::UpdateTime(Point& point)
{
	//�o�ߎ��Ԃ𓾂�
	timenow = (GetNowCount() - time) / 1000;

	if (GetNowCount() - time <= 1000)
	{
		flg = true;
	}

	point.PointNow = timenow * 10;

	//�G�l�~�[���o�����鎞�Ԃ��v��
	EnemyTime = ((GetNowCount() - time) / 1000);
	
}

void TimeCount::DrawTime()
{
	//���Ԃ�ۑ����邽�߂̑��
	SaveTime = (GetNowCount() - time) / 1000;

	//�e���Ƃ�
	DrawFormatString(242, 12, TimeBlackColor, "�^�C�� : %d", SaveTime);
	DrawFormatString(240, 10, TimeWhiteColor, "�^�C�� : %d", SaveTime);

}
