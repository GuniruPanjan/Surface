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

void Save::SaveDate(Point& point,TimeCount& timecount)
{
	save_date = { point.DistancePoint, point.PointPoint, timecount.SaveTime };

	FILE *fp;

	fopen_s(&fp,"save.txt", "wb");

	if (fp == NULL)
	{
		//ファイル読み込みエラー
		MessageBox(NULL, "ファイル読み込み失敗", "", MB_OK);
	}

	//fprintf(fp, "スコア:%d\nタイム:%d秒\n距離:%dm", point.PointPoint, timecount.SaveTime, point.DistancePoint);

	fwrite(&save_date, sizeof(save_date), 1, fp);   //save_date構造体の中身を出力

	fclose(fp);
}

void Save::SaveLoad()
{
	FILE *fp;

	fopen_s(&fp, "save.txt", "rb");

	if (fp == NULL)
	{
		//ファイル読み込みエラー
		MessageBox(NULL, "ファイル読み込み失敗", "", MB_OK);
	}
	fread(&save_date, sizeof(save_date), 1, fp);

	fclose(fp);

	DrawFormatString(100, 100, GetColor(255, 255, 255), "スコア:%d", save_date.Point);
	DrawFormatString(100, 150, GetColor(255, 255, 255), "タイム:%d秒", save_date.Time);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "距離:%dm", save_date.Distance);

}
