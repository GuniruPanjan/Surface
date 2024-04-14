#include "SceneDead.h"
#include "DxLib.h"
#include "SceneGame.h"
#include "SceneChoice.h"

SceneDead::SceneDead():
	SelectX(0),
	SelectY(0),
	SelectWidth(0),
	SelectHight(0),
	Up(false),
	Down(false)
{
}

SceneDead::~SceneDead()
{
}

void SceneDead::Init()
{
	SelectX = 235;
	SelectY = 237;

	SelectWidth = 8;
	SelectHight = 8;

	Up = true;
	Down = false;
}

std::shared_ptr<SceneBase> SceneDead::Update()
{
	//上キーを押す
	if (CheckHitKey(KEY_INPUT_UP))
	{
		SelectY = 237;

		Up = true;
		Down = false;
	}

	//下キーを押す
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		SelectY = 257;

		Up = false;
		Down = true;
	}

	//エンタキー入力でシーン遷移
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		if (Up == true)
		{
			return std::make_shared<SceneGame>();
		}
		
		if (Down == true)
		{
			return std::make_shared<SceneChoice>();
		}
		
	}

	return shared_from_this();
}

void SceneDead::Draw()
{
	DrawCircle(SelectX, SelectY, SelectWidth, GetColor(255, 255, 255), true);

	DrawString(280, 120, "YOU DIED", GetColor(255, 0, 0));

	DrawString(250, 230, "Retry", GetColor(255, 255, 255));

	DrawString(250, 250, "Home", GetColor(255, 255, 255));

}

void SceneDead::End()
{
}
