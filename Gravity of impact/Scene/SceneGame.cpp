#include "SceneGame.h"
#include "SceneGoal.h"
#include "DxLib.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
	//ƒƒ‚ƒŠ‰ğ•ú
	DeleteSoundMem(SoundGame);
}

void SceneGame::Init()
{
	player->Init();

	camera->Init();

	map->Init();

	enemy->Init();

	//”wŒi‚Ì‰æ‘œ“Ç‚İ‚İ
	GameBack = LoadGraph("data/cloudy.png");

	//”wŒiBGM“Ç‚İ‚İ
	SoundGame = LoadSoundMem("BGMESE/Garden_Farm.mp3");
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->SetCameraAngle(camera->cameraAngle.y);
	player->Update();

	camera->Update(*player);

	map->Update(*player, *enemy);

	//ƒvƒŒƒCƒ„[‚ª€‚ñ‚¾‚ç
	if (player->PlayerDead == true)
	{
		enemy->Init();  //‰Šú‰»

		player->PlayerDead = false;  //Player‚Ì€–S”»’è‚ğfalse‚É–ß‚·
	}
	//ƒvƒŒƒCƒ„[‚ª¶‚«‚Ä‚¢‚½‚ç
	else if (player->PlayerDead == false)
	{
		enemy->Update(*player);
	}
	

	//ƒTƒEƒ“ƒhÄ¶
	PlaySoundMem(SoundGame, DX_PLAYTYPE_LOOP, FALSE);

	//ƒS[ƒ‹ƒV[ƒ“‚É‘JˆÚ‚·‚é
	if (map->Goal == true)
	{
		return std::make_shared<SceneGoal>();
	}

	return shared_from_this();
}

void SceneGame::Draw()
{
	//”wŒi‚ğ•`‰æ
	DrawGraph(0, 0, GameBack, false);

	map->Draw(*player, *enemy);

	player->Draw();

	enemy->Draw();

	camera->Draw();
}

void SceneGame::End()
{
	//“Ç‚İ‚ñ‚¾‰æ‘œƒf[ƒ^‰ğ•ú
	DeleteGraph(GameBack);

	map->End();

	player->End();

	enemy->End();

	camera->End();
}
