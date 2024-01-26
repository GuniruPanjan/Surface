#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Save.h"

SceneFedo settingfedo;

Save savedate;

Point savepoint;
TimeCount savetime;

static int mimageHandle[9];   //画像ハンドル格納用変数

static int AnimCount;   //アニメーションカウント

static int Time;  //アニメーションタイム

static bool Plus, Mainas;

//初期化
void Config_Initialize()
{
	//mimageHandle = LoadGraph("date/Menu画面.png");//画像のロード

	LoadDivGraph("date/DanceMoveto.png", 9, 3, 3, 853, 480, mimageHandle);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;
}

//終了処理
void Config_Finalize()
{
	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(mimageHandle[i]);//画像の解放
	}
	
}

//更新
void Config_Update(Point& point,TimeCount& timecount)
{
	settingfedo.UpdateInSetting();

	//save.SaveDate(point, timecount);

	//Zキーが押されていたら
	if (CheckHitKey(KEY_INPUT_Z) != 0)
	{
		SceneMgr_ChageScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Config_Draw(Point& point,TimeCount& timecount)
{
	Time++;
	if (Time >= 5)
	{
		if (Plus == true)
		{
			AnimCount++;

			if (AnimCount >= 9)
			{
				Plus = false;

				Mainas = true;
			}
		}
		if (Mainas == true)
		{
			AnimCount--;

			if (AnimCount <= 0)
			{
				Mainas = false;

				Plus = true;
			}
		}

		Time = 0;
	}

	

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(-106, 0, mimageHandle[AnimCount], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 125);

	savedate.SaveLoad();

	/*DrawFormatString(100, 100,GetColor(255, 255, 255), "スコア:%d", point.PointPoint);
	DrawFormatString(100, 150, GetColor(255, 255, 255), "タイム:%d秒", timecount.SaveTime);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "距離:%dm", point.DistancePoint);*/

	//DrawString(100, 240, "記録画面ですまだできてませんすいません", GetColor(255, 255, 255));
	DrawString(100, 280, "Zキーを押すとメニュー画面に戻ります", GetColor(255, 255, 255));
}
