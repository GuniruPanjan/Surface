#include "PauseScene.h"
#include <Dxlib.h>
#include "Input.h"
#include "Application.h"
#include "SceneManager.h"

constexpr int appear_interval = 30;

void PauseScene::AppearInupdate(Input&)
{
	frame_++;
	if (frame_ == appear_interval)
	{
		updateFunc_ = &PauseScene::NoramalUpdate;
		drawFunc_ = &PauseScene::NormalDraw;
	}
}

void PauseScene::NoramalUpdate(Input& input)
{
	if (input.IsTriggered("pause"))
	{
		updateFunc_ = &PauseScene::DisappearUpdate;
		drawFunc_ = &PauseScene::NormalDraw;
		frame_ = appear_interval;
	}
	else if (input.IsTriggered("keyconf"))
	{
	
	}
}

void PauseScene::DisappearUpdate(Input&)
{
	frame_--;
	if (frame_ == 0)
	{
		manager_.PopScene();
	}
}

void PauseScene::FadeOutDraw(Input&)
{
}

void PauseScene::FadeDraw()
{
}

void PauseScene::NormalDraw()
{
	Application& app = Application::GetInstance();
	const auto& size = app.GetWindowSize();

	int halfHeight = (size.h - 100) / 2;
	int centerY = size.h / 2;

	float rate = static_cast<float>(frame_) / static_cast<float>(appear_interval); //Œ»Ý‚ÌŽžŠÔ‚ÌŠ„‡
	int currentHeight = rate * halfHeight;

	SetDrawBlendMode(DX_BLENDMODE_MUL, 235);
	//
	DrawBox(50, centerY - currentHeight, size.w - 50, centerY + currentHeight, 0x888888, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawString(100, 100, "Pause Scene", 0xffffff);
	DrawBox(50, centerY - currentHeight, size.w - 50, centerY + currentHeight, 0xffffff, false);
}

PauseScene::PauseScene(SceneManager& manager) :Scene(manager)
{
	updateFunc_ = &PauseScene::AppearInupdate;
	drawFunc_ = &PauseScene::NormalDraw;
}

void PauseScene::Update(Input& input)
{
	(this->*updateFunc_)(input);
}

void PauseScene::Draw()
{

	(this->*drawFunc_)();

}
