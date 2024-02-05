#include "Save.h"
#include "DxLib.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Save::Save():
	Start(false),
	name(0),
	White(0),
	end(false),
	Soundname(0)
{
}

Save::~Save()
{
}

void Save::FinalizeSave()
{
	DeleteSoundMem(Soundname);
}

void Save::SaveInit()
{
	Start = false;
	end = false;

	White = GetColor(255, 255, 255); //白色を代入

	name = MakeKeyInput(8, TRUE, FALSE, FALSE);
	SetActiveKeyInput(name);

	Soundname = LoadSoundMem("BGM/水面影絵.mp3");
}

void Save::SaveDate(Point& point,TimeCount& timecount)
{
	save_date = { point.DistancePoint, point.PointPoint, timecount.SaveTime };

	FILE *fp;

	fopen_s(&fp, "save.txt", "wb");

	if (fp == NULL)
	{
		//ファイル読み込みエラー
		MessageBox(NULL, "ファイル読み込み失敗", "", MB_OK);
	}

	//fprintf(fp, "スコア:%d\nタイム:%d秒\n距離:%dm", point.PointPoint, timecount.SaveTime, point.DistancePoint);

	fwrite(&save_date, sizeof(save_date), 1, fp);   //save_date構造体の中身を出力

	fclose(fp);
}

void Save::SaveInput()
{
	DrawFormatString(120, 100, White, "8文字以内で名前を入力してください");

	DrawKeyInputModeString(640, 480);
	DrawKeyInputString(250, 150, name);

	DrawFormatString(100, 300, White, "決まったらマウス右クリックしてください");

	//マウスの右クリックが押されたら
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		if (name == NULL)
		{
			DrawFormatString(120, 250, White, "名前を入力してください");
		}
		else
		{
			Start = true;

			DeleteSoundMem(Soundname);
		}
		
	}

	PlaySoundMem(Soundname, DX_PLAYTYPE_LOOP, FALSE);

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
