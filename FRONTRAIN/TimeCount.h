#pragma once
#include "Point.h"

class Point;

class TimeCount
{
public:
	TimeCount();
	~TimeCount();

	void InitTime();
	void UpdateTime(Point& point);
	void DrawTime();


	int cnt, test;
	bool flg = false;
	bool countflg = true;
	int timenow;
	int time;  //�X�^�[�g�������L�����Ă���
};

