#include "KeyConfigScene.h"
#include <Dxlib.h>
#include "Input.h"
#include "Application.h"
#include "SceneManager.h"
#include "StringUtility.h"

constexpr int appear_interval = 30;
constexpr int menu_margin = 60;

void KeyConfigScene::AppearInupdate(Input&)
{
	frame_++;
	if (frame_ == appear_interval)
	{
		updateFunc_ = &KeyConfigScene::NoramalUpdate;
		drawFunc_ = &KeyConfigScene::NormalDraw;
	}
}

void KeyConfigScene::NoramalUpdate(Input& input)
{
	if (input.IsTriggered("pause"))
	{
		updateFunc_ = &KeyConfigScene::DisappearUpdate;
		drawFunc_ = &KeyConfigScene::NormalDraw;
		frame_ = appear_interval;
	}
	else if (input.IsTriggered("keyconf"))
	{

	}
}

void KeyConfigScene::DisappearUpdate(Input&)
{
	frame_--;
	if (frame_ == 0)
	{
		manager_.PopScene();
	}
}

void KeyConfigScene::FadeOutDraw(Input&)
{
}

void KeyConfigScene::FadeDraw()
{
}

void KeyConfigScene::NormalDraw()
{
	Application& app = Application::GetInstance();
	const auto& size = app.GetWindowSize();

	int halfHeight = (size.h - 100) / 2;
	int centerY = size.h / 2;

	float rate = static_cast<float>(frame_) / static_cast<float>(appear_interval); //Œ»Ý‚ÌŽžŠÔ‚ÌŠ„‡
	int currentHeight = rate * halfHeight;

	SetDrawBlendMode(DX_BLENDMODE_MUL, 235);
	//
	DrawBox(50, centerY - currentHeight, size.w - menu_margin, centerY + currentHeight, 0x888888, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawString(100, 100, "KeyConfig Scene", 0xffffff);
	DrawBox(50, centerY - currentHeight, size.w - menu_margin, size.h - menu_margin, 0xffffff, false);

	DrawCommandList();
}

void KeyConfigScene::DrawCommandList()
{
	const auto& cmadTable = input_.GetCommandTable();
	int x = menu_margin + 50;
	int y = menu_margin + 50 + 10;
	for (const auto& cmd : cmadTable)
	{
		std::wstring cmdName = StringUtility::StringToWString(cmd.first);
		DrawFormatString(x, y, 0xffffff, "%s", cmd.first.c_str());
		y += 20;
	}
}

KeyConfigScene::KeyConfigScene(SceneManager& manage,Input& input) : Scene(manage),input_(input)
{
	updateFunc_ = &KeyConfigScene::AppearInupdate;
	drawFunc_ = &KeyConfigScene::NormalDraw;
}

void KeyConfigScene::Update(Input& input)
{
	(this->*updateFunc_)(input);
}

void KeyConfigScene::Draw()
{

	(this->*drawFunc_)();

}
