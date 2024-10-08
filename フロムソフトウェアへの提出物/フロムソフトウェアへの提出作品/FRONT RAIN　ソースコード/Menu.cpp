#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneFedo.h"
#include "SceneExplanation.h"
#include "Config.h"

SceneFedo fedo;

//当たり判定の矩形
Rect m_colRectStart;   //Startボタンの判定
Rect m_colRectExplanation;   //説明ボタンの判定
Rect m_colRectRecord;    //記録ボタンの判定

Rect m_colRectMouse;  //マウスの判定

static int mimageHandle;  //画像ハンドル格納用変数

static int Graph[9];   //画像ハンドル格納用変数

static int ClickShot;

static int AnimCount; //アニメーションカウント

static int Time; //アニメーションタイム

static bool Plus, Mainas;

bool ContinueInit; //コンテニューしたときに初期化する

bool Start, Explanaion, Record;

static int Botton;     //Bottonの画像を入れるハンドル

static int b, b2, b3;     //画像透過変数

static int Count;

//サウンド格納用変数
int SoundMenu;

//SE格納用変数
int SEClickShot;

//マウスの座標を取得するための変数
int MouseX, MouseY;

int StartColor, Startblack, StartYello;
int ExplanationColor, Explanationblack, ExplanationYello;
int RecordColor, Recordblack, RecordYello;

//マウスの当たり判定の幅
int TitleMouseDecisionX, TitleMouseDecisionY;

//画像を暗くする変数
int TitleDarken;

//元の画像の明るさ変数
int TitleFormer;

//初期化
void Menu_Initialize()
{
	mimageHandle = LoadGraph("date/スタート画面.png");    //画像ロード

	LoadDivGraph("date/Danceto.png", 9, 3, 3, 160, 90, Graph);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;

	ContinueInit = true;

	Start = false;

	Explanaion = false;

	Record = false;

	b = 255;

	b2 = 255;

	b3 = 255;

	MouseX = 0;
	MouseY = 0;

	StartColor = 0;
	ExplanationColor = 0;
	RecordColor = 0;

	Count = 0;

	Botton = LoadGraph("date/ボタン.png");

	SoundMenu = LoadSoundMem("BGM/朝露.mp3");

	Startblack = GetColor(0, 0, 0);
	Explanationblack = GetColor(0, 0, 0);
	Recordblack = GetColor(0, 0, 0);

	StartYello = GetColor(255, 255, 0);
	ExplanationYello = GetColor(255, 255, 0);
	RecordYello = GetColor(255, 255, 0);

	SEClickShot = LoadSoundMem("SE/狙撃銃発射.mp3");

	ClickShot = LoadGraph("date/Destruction.png");

	TitleMouseDecisionX = 10;
	TitleMouseDecisionY = 10;

	TitleDarken = 120;
	TitleFormer = 255;
}

//終了処理
void Menu_Finalize()
{
	DeleteGraph(mimageHandle); //画像の解放

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(Graph[i]);
	}

	DeleteSoundMem(SoundMenu);

	DeleteSoundMem(SEClickShot);

	DeleteGraph(Botton);

	fedo.Init();

	fedo.FinalizeFedo();
}

//更新
void Menu_Update()
{

	//ContinueInitがtrueなら1回実行する
	if (ContinueInit == true)
	{
		fedo.Init();
	}
	
	ContinueInit = false;


	fedo.Update();

	//ゲームシーン
	if (fedo.end == 1 && fedo.Start == true)
	{

		ContinueInit = true;

		SceneMgr_ChageScene(eScene_Game);//シーンをゲーム画面に変更
	}
	//説明画面
	if (fedo.Explanation == true)
	{
		if (Count >= 60)
		{
			ContinueInit = true;

			SceneMgr_ChageScene(eScene_Explanation); //シーンを説明画面に変更
		}
	}
	//設定画面
	if (fedo.Setting == true)
	{

		if (Count >= 60)
		{
			ContinueInit = true;

			SceneMgr_ChageScene(eScene_Config);//シーンを設定画面に変更
		}
		

	}




	//クリックされたら
	if(Start == true)
	{

		fedo.Out = 1;
		
		fedo.Start = true;

	}

	//クリックされたら
	if(Explanaion == true)
	{
		//fedo.Out = 1;

		Count++;

		fedo.Explanation = true;
	}

	//クリックされたら
	if(Record == true)
	{
		//fedo.Out = 1;

		Count++;

		fedo.Setting = true;
		
	}

	//マウスの座標取得
	GetMousePoint(&MouseX, &MouseY);

	//ボタンとの当たり判定
	if (m_colRectStart.IsCollision(m_colRectMouse) == true)
	{
		StartColor = StartYello;

		b = TitleDarken;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Start = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);
		}
	}
	//ボタンに触れていないとき
	else if (m_colRectStart.IsCollision(m_colRectMouse) == false)
	{
		StartColor = Startblack;

		b = TitleFormer;
	}
	//ボタンに触れているとき
	if (m_colRectExplanation.IsCollision(m_colRectMouse) == true)
	{
		ExplanationColor = ExplanationYello;

		b2 = TitleDarken;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{

			Explanaion = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);

		}
	}
	//ボタンに触れていないとき
	else if (m_colRectExplanation.IsCollision(m_colRectMouse) == false)
	{
		ExplanationColor = Explanationblack;

		b2 = TitleFormer;
	}
	//ボタンに触れているとき
	if (m_colRectRecord.IsCollision(m_colRectMouse) == true)
	{
		RecordColor = RecordYello;

		b3 = TitleDarken;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Record = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);

		}
	}
	//ボタンに触れていないとき
	else if (m_colRectRecord.IsCollision(m_colRectMouse) == false)
	{
		RecordColor = Recordblack;

		b3 = TitleFormer;
	}

	PlaySoundMem(SoundMenu, DX_PLAYTYPE_LOOP, FALSE);

}

//描画
void Menu_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);

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
	

	DrawGraph(0, 50, Graph[AnimCount], true);

	SetFontSize(22);

	//マウスの当たり判定取得
	m_colRectMouse.SetCenter(static_cast<float>(MouseX), static_cast<float>(MouseY + 5), static_cast <float>(TitleMouseDecisionX), static_cast <float>(TitleMouseDecisionY));

	//クリックした時の演出
	if (Start == true)
	{
		DrawGraph(210, 190, ClickShot, true);
	}
	if (Explanaion == true)
	{
		DrawGraph(210, 240, ClickShot, true);
	}
	if (Record == true)
	{
		DrawGraph(210, 300, ClickShot, true);
	}

	//フォント変更
	ChangeFont("アプリ明朝", DX_CHARSET_DEFAULT);
	
	//スタートボタン表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(263, 305, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_colRectStart.SetCenter(323, 320, 120, 30);
	DrawString(285, 307, "START", StartColor);

	//操作説明ボタン表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b2);
	DrawGraph(263, 365, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_colRectExplanation.SetCenter(323, 380, 120, 30);
	DrawString(277, 367, "操作説明", ExplanationColor);

	//スコアボタン表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b3);
	DrawGraph(263, 425, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    m_colRectRecord.SetCenter(323, 440, 120, 30);
	DrawString(290, 428, "スコア", RecordColor);

	fedo.StartUpdate();
}
