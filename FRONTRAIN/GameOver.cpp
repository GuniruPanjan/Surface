#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Scenefedo;

Rect m_colRect;
Rect Mouse;

int GameOverColor, GameOverWhite, GameOverYello;

static int mimageHandle;  //画像ハンドル格納用変数

static int GameOverHandle;  //画像ハンドル格納用変数

bool gameover;

//マウスの座標を取得するための変数
int  gmMouseX, gmMouseY;

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
	GameOverWhite = GetColor(255, 255, 255);
	GameOverYello = GetColor(255, 255, 0);

	gmMouseX = 0;
	gmMouseY = 0;

	gameover = false;

	SoundGameOver = LoadSoundMem("BGM/英霊の墓.mp3");

	SEClickGameOver = LoadSoundMem("SE/決定ボタンを押す40.mp3");
}

//終了処理
void GameOver_Finalize()
{
	DeleteGraph(mimageHandle);   //画像の解放

	DeleteGraph(GameOverHandle);  //画像の解放
}

//更新
void GameOver_Update()
{
	Scenefedo.UpdateIn();

	//SPACEキーが押されていたら
	//if (CheckHitKey(KEY_INPUT_SPACE) != 0)
	if(gameover == true)
	{
		SceneMgr_ChageScene(eScene_Config);//シーンをメニューに変更

		DeleteSoundMem(SoundGameOver);

		DeleteSoundMem(SEClickGameOver);
	}

	//マウスの座標取得
	GetMousePoint(&gmMouseX, &gmMouseY);

	if (m_colRect.IsCollision(Mouse) == true)
	{
		GameOverColor = GameOverYello;
		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			PlaySoundMem(SEClickGameOver, DX_PLAYTYPE_BACK, FALSE);

			gameover = true;
		}
	}
	else if (m_colRect.IsCollision(Mouse) == false)
	{
		GameOverColor = GameOverWhite;
	}

	PlaySoundMem(SoundGameOver, DX_PLAYTYPE_LOOP, FALSE);

}

void GameOver_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);

	DrawGraph(70, 0, GameOverHandle, true);

	//マウスの当たり判定取得
	Mouse.SetCenter(gmMouseX, gmMouseY + 5, 10, 10);

	//DrawString(0, 0, "ゲームオーバー画面です", GetColor(255, 255, 255));
	m_colRect.SetCenter(63, 410, 50, 25);
	DrawString(40, 400, "記録", GameOverColor);

	/*m_colRect.Draw(GetColor(255, 0, 0), false);
	Mouse.Draw(GetColor(255, 0, 0), false);*/
}
