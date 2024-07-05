#include "SceneGame.h"

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
	player->SetCameraAngle(camera->GetAngleY());
	player->Update();
	camera->Update(*player);

	return shared_from_this();  //自身のポインタを返す
}

void SceneGame::Draw()
{
	player->Draw();
	camera->Draw();
}

void SceneGame::End()
{
	player->End();
	camera->End();
}
