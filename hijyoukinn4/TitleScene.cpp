#include "TitleScene.h"
#include<Dxlib.h>
#include"GamePlayingScene.h"
#include"Input.h"
#include"SceneManager.h"
#include<cassert>

void TitleScene::FadeInupdate(Input&)
{
	frame++;
	if (frame >= 60)
	{
		manager_.ChangeScene(std::make_shared<GamePlayingScene>(manager_));
		manager_.ChangeScene(std::shared_ptr<GamePlayingScene>(new GamePlayingScene (manager_)));
	}
}

void TitleScene::FadeDraw()
{
	//通常の描画
	DrawString(100, 100, "TitleScene", 0xffffff);
	DrawGraph(100, 100, handle_, true);

	//フェード
	int alpha = ((float)frame / 60.0f);
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 640, 480, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::NormalDraw()
{
	DrawString(100, 100, "TitleScene", 0xffffff);
	DrawGraph(100, 100, handle_, true);
}

void TitleScene::NoramalUpdate(Input& input)
{
}

void TitleScene::FadeOutDraw(Input&)
{
	frame--;
	if (frame <= 0)
	{
		updateFunc_ = &TitleScene::NoramalUpdate;
		drawFunc_ = &TitleScene::NormalDraw;
	}
}

TitleScene::TitleScene(SceneManager& manager) : Scene(manager)
{
	handle_ = LoadGraph("img/卵.png");
	assert(handle_ >= 0);
	frame = 0;
	updateFunc_ = &TitleScene::FadeInupdate;
	drawFunc_ = &TitleScene::FadeDraw;
}

TitleScene::~TitleScene()
{
	OutputDebugString("タイトルシーンがdeleteされました\n");
	DeleteGraph(handle_);
}

void TitleScene::Update(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		manager_.ChangeScene(std::make_shared<GamePlayingScene>(manager_));
	}
	(this->*updateFunc_)(input);
}

void TitleScene::Draw()
{
	(this->*drawFunc_)();

}
