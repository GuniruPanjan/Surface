#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Save.h"
#include "Rect.h"

SceneFedo settingfedo;

//Save savedate;
Save savedate;

Point savepoint;
TimeCount savetime;

Rect m_Rect;
Rect m_Mouse;

static int mimageHandle[9];   //画像ハンドル格納用変数

static int AnimCount;   //アニメーションカウント

static int Time;  //アニメーションタイム

static bool Plus, Mainas;

static bool ContinueInit;

static int Botton;   //ボタンの画像格納用変数

static int b;   //画像透過用変数

// マウスの座標を取得するための変数
int CMouseX, CMouseY;

int CColor, Cblack, CYello;

bool CRecord;

int SceneTime;

//スコアの場所表示
int ScoreX, ScoreY, HiScoreX;

//マウスの当たり判定の幅
int MouseDecisionX, MouseDecisionY;

//背景を暗くするための変数
int Darken;

//サウンド用格納変数
int SoundConfig;

//SE用格納変数
int SEClickConfig;

//白色を入れる変数
int WhiteColor;

//初期化
void Config_Initialize()
{

	LoadDivGraph("date/DanceMoveto.png", 9, 3, 3, 853, 480, mimageHandle);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;

	ContinueInit = false;

	CMouseX = 0;
	CMouseY = 0;

	CColor = 0;
	Cblack = GetColor(0, 0, 0);
	CYello = GetColor(255, 255, 0);

	Botton = LoadGraph("date/ボタン.png");

	b = 255;

	CRecord = false;

	SceneTime = 0;

	SoundConfig = LoadSoundMem("BGM/優しい窓辺.mp3");

	SEClickConfig = LoadSoundMem("SE/決定ボタンを押す40.mp3");

	ScoreX = 100;

	ScoreY = 20;

	HiScoreX = 400;

	MouseDecisionX = 10;
	MouseDecisionY = 10;

	Darken = 125;

	WhiteColor = GetColor(255, 255, 255);

}

//終了処理
void Config_Finalize()
{
	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(mimageHandle[i]);//画像の解放
	}

	DeleteSoundMem(SoundConfig);

	DeleteSoundMem(SEClickConfig);

	DeleteGraph(Botton);

	settingfedo.FinalizeFedo();
	
}

//更新
void Config_Update(Point& point,TimeCount& timecount)
{

	SceneTime++;

	//シーン遷移の演出
	settingfedo.UpdateInSetting();


	//クリックされたらシーンを変更
	if(CRecord == true)
	{

		SceneMgr_ChageScene(eScene_Menu);//シーンをメニューに変更

	}

	//マウスの座標取得
	GetMousePoint(&CMouseX, &CMouseY);

	//ボタンに触れていないとき
	if (m_Rect.IsCollision(m_Mouse) == false)
	{
		CColor = Cblack;

		b = 255;
	}
	//ボタンに触れているとき
	else if (m_Rect.IsCollision(m_Mouse) == true)
	{
		CColor = CYello;

		b = 120;
		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			if (SceneTime >= 20)
			{
				PlaySoundMem(SEClickConfig, DX_PLAYTYPE_BACK, FALSE);

				CRecord = true;

				SceneTime = 0;
			}
			
		}
	}

	PlaySoundMem(SoundConfig, DX_PLAYTYPE_LOOP, FALSE);

}

//描画
void Config_Draw(Point& point,TimeCount& timecount)
{
	//画面背景でのアニメーションタイム
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

	
	//背景描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Darken);
	DrawGraph(-106, 0, mimageHandle[AnimCount], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Darken);

	//セーブデータの読み込み
	savedate.SaveLoad();
	//ハイスコアの読み込み
	savedate.SaveHiscoreLoad();

	DrawFormatString(ScoreX, ScoreY, WhiteColor, "今回のスコア");

	DrawFormatString(HiScoreX, ScoreY, WhiteColor, "ハイスコア");

	m_Mouse.SetCenter(static_cast<float>(CMouseX), static_cast<float>(CMouseY + 5.0f), static_cast<float>(MouseDecisionX), static_cast<float>(MouseDecisionY));

	//ボタンを暗く描画する
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(263, 275, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//ボタンの表示と当たり判定
	m_Rect.SetCenter(323, 290, 120, 30);
	DrawString(276, 276, "タイトル", CColor);
}
