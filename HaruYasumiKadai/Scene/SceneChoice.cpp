#include "SceneChoice.h"
#include "DxLib.h"
#include "SceneGame.h"
#include "SceneGameBack.h"

SceneChoice::SceneChoice() :
	X(0),
	Y(0),
	Time(0),
	TimeNow(0),
	Up(false),
	Down(false),
	Select(0),
	front(false),
	back(false)
{
}

SceneChoice::~SceneChoice()
{
}

void SceneChoice::Init()
{
	//背景画像を読み込む
	ChoiceSceneGraph = LoadGraph("date/選択画像.png");

	//初期化処理
	X = 320;
	Y = 240;

	Select = 245;

	Time = 0;

	TimeNow = GetNowCount();  //現在時間を得る

	Up = false;
	Down = true;

	front = true;
	back = false;
}

std::shared_ptr<SceneBase> SceneChoice::Update()
{
	//経過時間を得る
	Time = (GetNowCount() - TimeNow) / 1000;

	if (Time >= 2)
	{
		//上キーを押す
		if (CheckHitKey(KEY_INPUT_UP))
		{
			Select = 205;

			Up = true;
			Down = false;
		}

		//下キーを押す
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			Select = 245;

			Up = false;
			Down = true;
		}



		if (Up == true)
		{
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				front = false;
				back = true;

				return std::make_shared<SceneGameBack>();
			}
		}

		if (Down == true)
		{
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				front = true;
				back = false;

				return std::make_shared<SceneGame>();
			}
		}
		
	}

	return shared_from_this(); //自身のshare_ptrを返す
}

void SceneChoice::Draw()
{
	//背景画像描画
	DrawGraph(0, 0, ChoiceSceneGraph, true);

	DrawCircle(X - 20, Select + 7, 10, GetColor(255, 255, 255), true);

	DrawString(X, Y, "STAGE 1 (表)", 0xffffff);

	DrawString(X, Y - 40, "STAGE 1 (裏)", 0xffffff);
}

void SceneChoice::End()
{
}
