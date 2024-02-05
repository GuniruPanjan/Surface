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

//サウンド格納用変数
int SoundMenu;

//SE格納用変数
int SEClickShot;

//マウスの座標を取得するための変数
int MouseX, MouseY;

int StartColor, StartWhite, StartYello;
int ExplanationColor, ExplanationWhite, ExplanationYello;
int RecordColor, RecordWhite, RecordYello;


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

	MouseX = 0;
	MouseY = 0;

	StartColor = 0;
	ExplanationColor = 0;
	RecordColor = 0;

	SoundMenu = LoadSoundMem("BGM/朝露.mp3");

	StartWhite = GetColor(255, 255, 255);
	ExplanationWhite = GetColor(255, 255, 255);
	RecordWhite = GetColor(255, 255, 255);

	StartYello = GetColor(255, 255, 0);
	ExplanationYello = GetColor(255, 255, 0);
	RecordYello = GetColor(255, 255, 0);

	SEClickShot = LoadSoundMem("SE/狙撃銃発射.mp3");

	ClickShot = LoadGraph("date/Destruction.png");
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
	if (fedo.end == 1 && fedo.Explanation == true)
	{

		ContinueInit = true;

		SceneMgr_ChageScene(eScene_Explanation); //シーンを説明画面に変更
	}
	//設定画面
	if (fedo.end == 1 && fedo.Setting == true)
	{

		/*DeleteSoundMem(SoundMenu);

		DeleteSoundMem(SEClickShot);

		DeleteGraph(mimageHandle);

		for (int i = 0; i < 9; i++)
		{
			DeleteGraph(Graph[i]);
		}*/

		ContinueInit = true;

		SceneMgr_ChageScene(eScene_Config);//シーンを設定画面に変更

	}



	//Aキーが押されていたら
	//if (CheckHitKey(KEY_INPUT_A) != 0)
	//クリックされたら
	if(Start == true)
	{

		fedo.Out = 1;
		
		fedo.Start = true;

	}
	//Bキーが押されていたら
	//if (CheckHitKey(KEY_INPUT_B) != 0)
	//クリックされたら
	if(Explanaion == true)
	{
		fedo.Out = 1;

		fedo.Explanation = true;
	}
	//Cキーが押されていたら
	//if (CheckHitKey(KEY_INPUT_C) != 0)
	//クリックされたら
	if(Record == true)
	{
		fedo.Out = 1;

		fedo.Setting = true;
		
	}

	//マウスの座標取得
	GetMousePoint(&MouseX, &MouseY);

	//ボタンとの当たり判定
	if (m_colRectStart.IsCollision(m_colRectMouse) == true)
	{
		StartColor = StartYello;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Start = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);
		}
	}
	else if (m_colRectStart.IsCollision(m_colRectMouse) == false)
	{
		StartColor = StartWhite;
	}

	if (m_colRectExplanation.IsCollision(m_colRectMouse) == true)
	{
		ExplanationColor = ExplanationYello;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Explanaion = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);

		}
	}
	else if (m_colRectExplanation.IsCollision(m_colRectMouse) == false)
	{
		ExplanationColor = ExplanationWhite;
	}

	if (m_colRectRecord.IsCollision(m_colRectMouse) == true)
	{
		RecordColor = RecordYello;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			Record = true;

			PlaySoundMem(SEClickShot, DX_PLAYTYPE_BACK, FALSE);

		}
	}
	else if (m_colRectRecord.IsCollision(m_colRectMouse) == false)
	{
		RecordColor = RecordWhite;
	}

	PlaySoundMem(SoundMenu, DX_PLAYTYPE_LOOP, FALSE);

}

//描画
void Menu_Draw()
{
	fedo.Draw();

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
	m_colRectMouse.SetCenter(MouseX, MouseY + 5, 10, 10);

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

	ChangeFont("アプリ明朝", DX_CHARSET_DEFAULT);
	//DrawBox(248, 310, 390, 340, GetColor(255, 0, 0),false);
	m_colRectStart.SetCenter(323, 320, 120, 30);
	DrawString(285, 310, "START", StartColor);

	//DrawBox(248, 400, 405, 365, GetColor(255, 0, 0), false);
	m_colRectExplanation.SetCenter(323, 380, 120, 30);
	DrawString(280, 370, "操作説明", ExplanationColor);

	//DrawBox(248, 460, 360, 425, GetColor(255, 0, 0), false);
    m_colRectRecord.SetCenter(323, 440, 120, 30);
	DrawString(300, 430, "記録", RecordColor);

	fedo.StartUpdate();


	/*m_colRectStart.Draw(GetColor(255, 0, 0), false);
	m_colRectExplanation.Draw(GetColor(255, 0, 0), false);
	m_colRectRecord.Draw(GetColor(255, 0, 0), false);
	m_colRectMouse.Draw(GetColor(255, 255, 0), false);*/
}
