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
	//�E�N���b�N����SceneTitle
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		return std::make_shared<SceneTitle>();
	}

	player.Update();


	return shared_from_this();  //���g��shared_ptr��Ԃ�
}

void SceneGame::Draw()
{
	DrawString(0, 0, "SceneGame", 0xffffff);

	DrawFormatString(400, 16, 0xffffff, "�E�N���b�N����SceneTitle");

	player.Draw();
}

void SceneGame::End()
{
}
