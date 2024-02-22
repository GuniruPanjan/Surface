#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Scenefedo;

Rect m_colRect;
Rect Mouse;

int GameOverColor, GameOverblack, GameOverYello;

static int mimageHandle;  //画像ハンドル格納用変数

static int GameOverHandle;  //画像ハンドル格納用変数

static int Botton;   //ボタン画像格納用変数

static int b;   //画像透過用変数

bool gameover;

//マウスの座標を取得するための変数
int  gmMouseX, gmMouseY;

//マウスの当たり判定の幅
int GameOverMouseDecisionX, GameOverMouseDecisionY;

//GameOver文字出力する場所変数
int GameOverX, GameOverY;

//サウンド用格納変数
int SoundGameOver;

//SE用格納変数
int SEClickGameOver;

//初期化
void GameOver_Initialize()
{
	mimageHandle = LoadGraph("date/ゲームオーバー画面.png");  //画像のロード

	GameOverHandle = LoadGraph("date/Game Over.png");  //画像ロード

	Scenefedo.Init();

	GameOverColor = 0;
	GameOverblack = GetColor(0, 0, 0);
	GameOverYello = GetColor(255, 255, 0);

	gmMouseX = 0;
	gmMouseY = 0;

	gameover = false;

	Botton = LoadGraph("date/ボタン.png");

	b = 255;

	SoundGameOver = LoadSoundMem("BGM/英霊の墓.mp3");

	SEClickGameOver = LoadSoundMem("SE/決定ボタンを押す40.mp3");

	GameOverMouseDecisionX = 10;
	GameOverMouseDecisionY = 10;

	GameOverX = 70;
	GameOverY = 0;
}

//終了処理
void GameOver_Finalize()
{
	DeleteGraph(mimageHandle);   //画像の解放

	DeleteGraph(GameOverHandle);  //画像の解放

	DeleteSoundMem(SoundGameOver);

	DeleteSoundMem(SEClickGameOver);

	DeleteGraph(Botton);

	Scenefedo.FinalizeFedo();
}

//更新
void GameOver_Update()
{
	Scenefedo.UpdateIn();

	if (Scenefedo.a >= 255)
	{
		Scenefedo.Update();
	}
	
	//クリックされるとシーン変更
	if (Scenefedo.end == 1 && Scenefedo.Setting == true)
	{
		SceneMgr_ChageScene(eScene_Config);//シーンを記録に変更
	}

	
	if(gameover == true)
	{
		Scenefedo.Out = 1;

		Scenefedo.Setting = true;
	}

	//マウスの座標取得
	GetMousePoint(&gmMouseX, &gmMouseY);

	//ボタンに触れているとき
	if (m_colRect.IsCollision(Mouse) == true)
	{
		GameOverColor = GameOverYello;

		b = 120;
		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			PlaySoundMem(SEClickGameOver, DX_PLAYTYPE_BACK, FALSE);

			gameover = true;
		}
	}
	//ボタンに触れていないとき
	else if (m_colRect.IsCollision(Mouse) == false)
	{
		GameOverColor = GameOverblack;

		b = 255;
	}

	PlaySoundMem(SoundGameOver, DX_PLAYTYPE_LOOP, FALSE);

}

void GameOver_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);

	DrawGraph(GameOverX, GameOverY, GameOverHandle, true);

	//マウスの当たり判定取得
	Mouse.SetCenter(static_cast<float>(gmMouseX), static_cast<float>(gmMouseY + 5), static_cast<float>(GameOverMouseDecisionX), static_cast<float>(GameOverMouseDecisionY));

	//ボタンの表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(40, 400, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetFontSize(22);

	m_colRect.SetCenter(100, 415, 120, 30);
	DrawString(65, 402, "スコア", GameOverColor);

}
