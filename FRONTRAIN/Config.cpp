#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Save.h"
#include "Rect.h"

SceneFedo settingfedo;

Save savedate;

Point savepoint;
TimeCount savetime;

Rect m_Rect;
Rect m_Mouse;

static int mimageHandle[9];   //画像ハンドル格納用変数

static int AnimCount;   //アニメーションカウント

static int Time;  //アニメーションタイム

static bool Plus, Mainas;

// マウスの座標を取得するための変数
int CMouseX, CMouseY;

int CColor, CWhite, CYello;

bool CRecord;

//初期化
void Config_Initialize()
{
	//mimageHandle = LoadGraph("date/Menu画面.png");//画像のロード

	LoadDivGraph("date/DanceMoveto.png", 9, 3, 3, 853, 480, mimageHandle);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;

	CMouseX = 0;
	CMouseY = 0;

	CColor = 0;
	CWhite = GetColor(255, 255, 255);
	CYello = GetColor(255, 255, 0);

	CRecord = false;
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
	//if (CheckHitKey(KEY_INPUT_Z) != 0)
	if(CRecord == true)
	{
		SceneMgr_ChageScene(eScene_Menu);//シーンをメニューに変更
	}

	//マウスの座標取得
	GetMousePoint(&CMouseX, &CMouseY);

	if (m_Rect.IsCollision(m_Mouse) == false)
	{
		CColor = CWhite;
	}
	else if (m_Rect.IsCollision(m_Mouse) == true)
	{
		CColor = CYello;
		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			CRecord = true;
		}
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

	//DrawString(100, 240, "記録画面ですまだできてませんすいません", GetColor(255, 255, 255));

	m_Mouse.SetCenter(CMouseX, CMouseY + 5, 10, 10);

	m_Rect.SetCenter(330, 290, 150, 30);
	DrawString(260, 280, "メニュー画面", CColor);

	/*m_Rect.Draw(GetColor(255, 0, 0), false);
	m_Mouse.Draw(GetColor(255, 0, 0), false);*/
}
