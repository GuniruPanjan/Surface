#include "GameOverScene.h"
#include<Dxlib.h>
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"

void GameOverScene::FadeInUpdate(Input& input)
{
	frame_--;
	if (frame_ <= 0)
	{
		updateFunc_ = &GameOverScene::NormalUpdate;
		drawFunc_ = &GameOverScene::NormalDraw;
	}
}

void GameOverScene::NormalUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		updateFunc_ = &GameOverScene::FadeOutUpdate;
		drawFunc_ = &GameOverScene::FadeDraw;
	}
}

void GameOverScene::FadeOutUpdate(Input& input)
{
	frame_++;
	if (frame_ >= 60)
	{
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void GameOverScene::FadeDraw()
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

void GameOverScene::NormalDraw()
{
	DrawString(100, 100, "GamePlayerScene", 0xffffff);
	DrawGraph(100, 100, handle_, true);
}

GameOverScene::GameOverScene(SceneManager& mgr) : Scene(mgr)
{
}

void GameOverScene::Update(Input& input)
{
	(this->*updateFunc_)(input);
}

void GameOverScene::Draw()
{
	(this->*drawFunc_)();
}
