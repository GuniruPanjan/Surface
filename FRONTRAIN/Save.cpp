#include "Save.h"
#include "DxLib.h"
#include<stdio.h>
#include<time.h>

Save::Save():
	Start(false),
	name(0),
	White(0),
	end(false),
	Soundname(0),
	hiscore(0),
	NameSave(),
	NameDisplay(),
	String(),
	save_date(),
	save_hiscore()
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

	save_hiscore = { point.DistancePoint, point.PointPoint, timecount.SaveTime };

	NameSave = { String };

	NameDisplay = { String };

	hiscore = GetHiScore();

	FILE* fp;
	FILE* HiFp;
	FILE* HiUp;
	FILE* FName;
	FILE* FNameDis;

	//ファイル読み込み
	fopen_s(&fp, "save.txt", "wb");

	fopen_s(&HiUp, "HiUp.txt", "r");

	fopen_s(&FNameDis, "NameDis.txt", "w");

	if (fp == NULL)
	{
		//ファイル読み込みエラー
		MessageBox(NULL, "ファイル読み込み失敗", "", MB_OK);
	}
	if (HiUp != NULL)
	{
		fscanf_s(HiUp, "%d", &hiscore);
		fclose(HiUp);
	}
	//ファイルへの書き込みを行う
	if (HiUp == NULL || hiscore < point.PointPoint)
	{
		fopen_s(&HiUp, "HiUp.txt", "w");
		fprintf(HiUp, "%d", point.PointPoint);
		fclose(HiUp);
		//fopen_s(&HiFp, "Hiscore.txt", "wb");
		fopen_s(&HiFp, "Hiscore.txt", "wb");
		fopen_s(&FName, "Name.txt", "w");

		fwrite(&save_hiscore, sizeof(save_hiscore), 1, HiFp);    //save_date構造体の中身を出力
		fprintf_s(FName, String);

		fclose(HiFp);
		fclose(FName);
		
	}

	fwrite(&save_date, sizeof(save_date), 1, fp);   //save_date構造体の中身を出力

	fprintf_s(FNameDis, String);        //名前を記入する

	fclose(fp);

	fclose(FNameDis);

	
}

int Save::GetHiScore(void)
{
	FILE* HiUp;

	//ファイル読み込み
	fopen_s(&HiUp, "HiUp.txt", "r");

	if (HiUp == NULL)
		return 0;

	//ハイスコア読み込み
	fscanf_s(HiUp, "%d", &hiscore);
	fclose(HiUp);
	return hiscore;
	
}

void Save::SaveInput()
{

	DrawFormatString(50, 100, White, "アルファベットで8文字以内で名前を入力してください");

	//名前を入力
	DrawKeyInputModeString(640, 480);
	DrawKeyInputString(250, 150, name);

	DrawFormatString(100, 300, White, "決まったらエンターキーを押してください");

	//エンターキーが押されたら
	if(CheckHitKey(KEY_INPUT_RETURN))
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

void Save::NameOutPut()
{

	//入力された文字列を取得
	GetKeyInputString(String, name);
}

void Save::SaveLoad()
{
	FILE* fp;
	FILE* FNameDis;

	//ファイルの読み込み
	fopen_s(&fp, "save.txt", "rb");
	fopen_s(&FNameDis, "NameDis.txt", "r");

	if (fp == NULL)
	{
		//ファイル読み込みエラー
		MessageBox(NULL, "ファイル読み込み失敗", "", MB_OK);
	}

	fread(&save_date, sizeof(save_date), 1, fp);
	fread(&NameDisplay, sizeof(NameDisplay), 1, FNameDis);

	//ファイルのデータを出力
	DrawFormatString(100, 60, GetColor(255,255,255), "%s", NameDisplay.NameDisplay);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "スコア:%d", save_date.Point);
	DrawFormatString(100, 150, GetColor(255, 255, 255), "タイム:%d秒", save_date.Time);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "距離:%dm", save_date.Distance);

	fclose(fp);
	fclose(FNameDis);

}

void Save::SaveHiscoreLoad()
{
	FILE* HiFp;
	FILE* FName;

	//ファイル読み込み
	fopen_s(&HiFp, "Hiscore.txt", "rb");
	fopen_s(&FName, "Name.txt", "r");

	if (HiFp == NULL)
	{
		//ファイル読み込みエラー
		MessageBox(NULL, "ファイル読み込み失敗", "", MB_OK);
	}

	fread(&save_hiscore, sizeof(save_hiscore), 1, HiFp);
	fread(&NameSave, sizeof(NameSave), 1, FName);

	//ファイルのデータを出力
	DrawFormatString(400, 60, GetColor(255, 255, 255), "%s", NameSave.Name);
	DrawFormatString(400, 100, GetColor(255, 255, 255), "ハイスコア:%d", save_hiscore.Point);
	DrawFormatString(400, 150, GetColor(255, 255, 255), "タイム:%d秒", save_hiscore.Time);
	DrawFormatString(400, 200, GetColor(255, 255, 255), "距離:%dm", save_hiscore.Distance);

	fclose(HiFp);
	fclose(FName);
}
