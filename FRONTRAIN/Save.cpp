#include "Save.h"
#include "DxLib.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Save::Save()
{
}

Save::~Save()
{
}

void Save::SaveDraw(Point& point,TimeCount& timecount)
{
	FILE *fp;

	fopen_s(&fp,"test.txt", "W");

	fprintf(fp, "�X�R�A:%d\n�^�C��:%d\n����:%d", point.PointPoint, timecount.SaveTime, point.DistancePoint);

	fclose(fp);
}
