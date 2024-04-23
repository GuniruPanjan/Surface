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

	camera->Update(Play);

	return shared_from_this();
}

void SceneGame::Draw()
{
	//DrawString(0, 0, "SceneGame", GetColor(255, 255, 255));

	player->Draw();

	camera->Draw();
}

void SceneGame::End()
{
	player->End();

	camera->End();
}
