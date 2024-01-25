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

	fprintf(fp, "スコア:%d\nタイム:%d\n距離:%d", point.PointPoint, timecount.SaveTime, point.DistancePoint);

	fclose(fp);
}
