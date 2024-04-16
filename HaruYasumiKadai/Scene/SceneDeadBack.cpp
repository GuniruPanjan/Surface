#include "SceneDeadBack.h"
#include "DxLib.h"
#include "SceneGameBack.h"
#include "SceneChoice.h"

SceneDeadBack::SceneDeadBack():
	SelectX(0),
	SelectY(0),
	SelectWidth(0),
	SelectHight(0),
	Up(false),
	Down(false)
{
}

SceneDeadBack::~SceneDeadBack()
{
}

void SceneDeadBack::Init()
{
	SelectX = 235;
	SelectY = 237;

	SelectWidth = 8;
	SelectHight = 8;

	Up = true;
	Down = false;
}

std::shared_ptr<SceneBase> SceneDeadBack::Update()
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
			return std::make_shared<SceneGameBack>();
		}

		if (Down == true)
		{
			return std::make_shared<SceneChoice>();
		}

	}

	return shared_from_this();
}

void SceneDeadBack::Draw()
{
	DrawCircle(SelectX, SelectY, SelectWidth, GetColor(255, 255, 255), true);

	DrawString(280, 120, "YOU DIED", GetColor(255, 0, 0));

	DrawString(250, 230, "Retry", GetColor(255, 255, 255));

	DrawString(250, 250, "Home", GetColor(255, 255, 255));
}

void SceneDeadBack::End()
{
}
