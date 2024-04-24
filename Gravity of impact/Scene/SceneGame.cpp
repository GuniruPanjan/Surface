#include "SceneGame.h"
#include "DxLib.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	player->Init();

	camera->Init();
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->Update();

	camera->Update(*player);

	return shared_from_this();
}

void SceneGame::Draw()
{
	//DrawString(0, 0, "SceneGame", GetColor(255, 255, 255));

	player->Draw();

	camera->Draw();

	for (int x = -50; x <= 50; x += 10)
	{
		DrawLine3D(VGet(static_cast<float>(x), 0, -50), VGet(static_cast<float>(x), 0, 50), 0xffff00);
	}
	for (int z = -50; z <= 50; z += 10)
	{
		DrawLine3D(VGet(-50, 0, static_cast<float>(z)), VGet(50, 0, static_cast<float>(z)), 0xff0000);
	}
}

void SceneGame::End()
{
	player->End();

	camera->End();
}
