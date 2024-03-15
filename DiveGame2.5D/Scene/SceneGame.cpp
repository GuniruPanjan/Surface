#include "SceneGame.h"
#include "Player.h"
#include "SceneTitle.h"
#include "DxLib.h"

Player player;

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	player.Init();

}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	//右クリックだとSceneTitle
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		return std::make_shared<SceneTitle>();
	}

	player.Update();


	return shared_from_this();  //自身のshared_ptrを返す
}

void SceneGame::Draw()
{
	DrawString(0, 0, "SceneGame", 0xffffff);

	DrawFormatString(400, 16, 0xffffff, "右クリックだとSceneTitle");

	player.Draw();
}

void SceneGame::End()
{
}
