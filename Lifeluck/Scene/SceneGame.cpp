#include "SceneGame.h"
#include "SceneGoal.h"

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
	//player->IsHitSearch(machine->GetCol());
	obj->IsHit(player->GetCol());
	machine->IsHit(player->GetCol(),*player);
	machine->IsHitCapsule(player->GetCol(), *player);
	camera->Update(*player);
	enemy->Update();
	machine->Update();
	ground->Update();
	obj->Update();
	goal->Update();
	goal->IsHit(player->GetCol());
	goal->IsHitWall(player->GetCol());

	//ƒS[ƒ‹ƒV[ƒ“‚É‘JˆÚ‚·‚é
	if (goal->GetGoal() == true)
	{
		return std::make_shared<SceneGoal>();
	}

	return shared_from_this();
}

void SceneGame::Draw()
{
	player->Draw();
	enemy->Draw();
	ground->Draw();
	obj->Draw();
	goal->Draw();
	machine->Draw();

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
