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
	goal->Init();
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->SetCameraAngle(camera->cameraAngle.y);
	player->Update();
	enemy->IsHit(player->GetCol());
	player->IsHitSearch(machine->GetCol());
	player->IsHit(enemy->GetCol());
	obj->IsHit(player->GetCol());
	machine->IsHit(player->GetCol());
	camera->Update(*player);
	enemy->Update();
	machine->Update();
	ground->Update();
	obj->Update();
	goal->Update();

	return shared_from_this();
}

void SceneGame::Draw()
{
	player->Draw();
	enemy->Draw();
	machine->Draw();
	ground->Draw();
	obj->Draw();
	goal->Draw();

}

void SceneGame::End()
{
	player->End();
	enemy->End();
	machine->End();
	ground->End();
	obj->End();
	goal->End();
}
