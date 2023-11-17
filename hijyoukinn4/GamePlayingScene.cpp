#include "GamePlayingScene.h"
#include<Dxlib.h>
#include"Input.h"
#include"GameOverScene.h"
#include"SceneManager.h"
#include "PauseScene.h"
#include <cassert>

void GamePlayingScene::FadeInUpdate(Input& input)
{
	frame_--;
	if (frame_ <= 0)
	{
		updateFunc_ = &GamePlayingScene::NormalUpdate;
		drawFunc_ = &GamePlayingScene::NormalDraw;
	}
}

void GamePlayingScene::NormalUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		updateFunc_ = &GamePlayingScene::FadeOutUpdate;
		drawFunc_ = &GamePlayingScene::FadeDraw;
	}
	else if (input.IsTriggered("pause"))
	{
		manager_.PushScene(std::make_shared<PauseScene>(manager_));
	}
}

void GamePlayingScene::FadeOutUpdate(Input& input)
{
	frame_++;
	if (frame_ >= 60)
	{
		manager_.ChangeScene(std::make_shared<GameOverScene>(manager_));
	}
	
}

void GamePlayingScene::FadeDraw()
{
	//通常の描画
	DrawString(100, 100, "TitleScene", 0xffffff);
	DrawGraph(100, 100, handle_, true);

	//フェード
	int alpha = ((float)frame_ / 60.0f);
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 640, 480, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GamePlayingScene::NormalDraw()
{
	DrawString(100, 100, "GamePlayerScene", 0xffffff);
	DrawGraph(100, 100, handle_, true);
	DrawFormatString(10, 10, 0xffffff, "fps=%2.2f", fps_);
}

GamePlayingScene::GamePlayingScene(SceneManager& mgr) : Scene(mgr)
{
	handle_ = LoadGraph("img/game.png");
	assert(handle_ > 0);
	updateFunc_ = &GamePlayingScene::FadeInUpdate;
	drawFunc_ = &GamePlayingScene::FadeDraw;
	frame_ = 60;
}

void GamePlayingScene::Update(Input& input)
{
	fps_ = GetFPS();
	(this->*updateFunc_)(input);
}

void GamePlayingScene::Draw()
{
	
}
