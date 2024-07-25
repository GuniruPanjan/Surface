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
	enemy->Init();
	camera->Init();
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->SetCameraAngle(camera->GetAngleY());
	player->Update();
	enemy->Update(*player);
	camera->Update(*player, *enemy);

	player->IsCapsuleHit(enemy->GetCol());
	enemy->isSphereHit(player->GetSphereCol(), player->GetDamage());
	enemy->isSeachHit(player->GetCapsuleCol());

	return shared_from_this();  //自身のポインタを返す
}

void SceneGame::Draw()
{
	player->Draw();
	enemy->Draw();
	camera->Draw();
}

void SceneGame::End()
{
	player->End();
	enemy->End();
	camera->End();
}
