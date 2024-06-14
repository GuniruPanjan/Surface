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
	enemy->Init();
	machine->Init();
	ground->Init();
	obj->Init();
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->SetCameraAngle(camera->cameraAngle.y);
	player->Update();
	camera->Update(*player);
	enemy->Update();
	machine->Update();
	ground->Update();
	obj->Update();

	return shared_from_this();
}

void SceneGame::Draw()
{
	player->Draw();
	enemy->Draw();
	machine->Draw();
	ground->Draw();
	obj->Draw();

}

void SceneGame::End()
{
	player->End();
	enemy->End();
	machine->End();
	ground->End();
	obj->End();
}
