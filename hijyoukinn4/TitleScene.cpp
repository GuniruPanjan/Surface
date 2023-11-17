#include "TitleScene.h"
#include<Dxlib.h>
#include"GamePlayingScene.h"
#include"Input.h"
#include"SceneManager.h"
#include<cassert>
#include<sstream>
#include<iomanip>

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
	int x = abs((frame + 2) % (640 * 2) - 640);
	DrawCircle(x, 240, 10, 0xffaaaa, true);
}

void TitleScene::NoramalUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		updateFunc_ = &TitleScene::FadeOutDraw;
		drawFunc_ = &TitleScene::FadeDraw;
		frame = 0;
	}
	frame = frame + 8;
	//GetJoypadInputState();

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
	frame = 60;
	updateFunc_ = &TitleScene::FadeInupdate;
	drawFunc_ = &TitleScene::FadeDraw;

	std::ostringstream oss; //文字列がossに入る
	                               //後ろを１６進数にする  //１６進数から戻す
	oss << "TitleScene handle = " << std::hex << handle_ << std::dec << std::setfill('0') << std::setw(4) <<
		" , frame = " << frame << " , FPS =" << std::fixed << std::setprecision(2) <<
		GetFPS() << std::endl;
    
	OutputDebugStringA(oss.str().c_str());
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
