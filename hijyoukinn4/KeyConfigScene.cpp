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
	if (input.IsTriggered("OK"))
	{
		if (currentLineIndex_ < keyCommandTable_.size())
		{
			isEditRequestButton_ = true;
			isEditingNow_ = !isEditingNow_;
			updateFunc_ = &KeyConfigScene::NoramalUpdate;

			return;
		}
		else
		{
			CommitCurrentKeySetting();
			updateFunc_ = &KeyConfigScene::DisappearUpdate;
			drawFunc_ = &KeyConfigScene::NormalDraw;
			return;
		}
		
	}

	if (isEditRequestButton_)
	{
		if (input.IsReleased("OK"))
		{
			isEditingNow_ = !isEditingNow_;
			updateFunc_ = &KeyConfigScene::EditUpdate;
			isEditRequestButton_ = false;
			return;
		}
	}

	if(isEditingNow_)
	{
		return;
	}
		
	if (input.IsTriggered("pause"))
	{
		updateFunc_ = &KeyConfigScene::DisappearUpdate;
		drawFunc_ = &KeyConfigScene::NormalDraw;
		frame_ = appear_interval;
	}
	auto size = keyCommandTable_.size() + 1;
	if (input.IsTriggered("up"))
	{
		--currentLineIndex_ = (currentLineIndex_+ size - 1) % size;
	}
	if (input.IsTriggered("down"))
	{
		++currentLineIndex_ = (currentLineIndex_ +1) % size;
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

void KeyConfigScene::EditUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		isEditingNow_ = !isEditingNow_;
		updateFunc_ = &KeyConfigScene::NoramalUpdate;

		return;
	}

	char keystate[256];
	GetHitKeyStateAll(keystate);
	int padstate = GetJoypadInputState(DX_INPUT_PAD1);


	auto strItem = menuItems_[currentLineIndex_];
	auto& cmd = keyCommandTable_[strItem];
	
	for (int i = 0; i < 256; ++i)
	{
		if (keystate[i])
		{
			cmd[InputType::keybd] = i;
			break;
		}
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

	float rate = static_cast<float>(frame_) / static_cast<float>(appear_interval); //現在の時間の割合
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
	constexpr int line_height = 20;
	const auto& cmadTable = input_.GetCommandTable();
	
	int y = menu_margin + 50 + 10;
	int idx = 0;
	constexpr unsigned int default_color = 0xffffff;
	for (const auto& item : menuItems_)
	{
		auto& cmd = keyCommandTable_[item];
	
		int x = menu_margin + 50;
		unsigned int lineColor = default_color;
		std::wstring cmdName = StringUtility::StringToWString(item);
		
		if (idx == currentLineIndex_)
		{
			DrawString(x - 20, y, "→", 0xff0000);
			x += 10;
			if (isEditingNow_)
			{
				lineColor = 0xffaa00;
				x += 5;
			}
		}
		auto keyname = GetKeyName(cmd.at(InputType::keybd));
		DrawFormatString(x, y, 0xffffff, _T("%s : keybd=%s , pad=%03d"), cmdName.c_str(), keyname.c_str, cmd.second.at(InputType::pad)); //化ける
		
		y += line_height;
		++idx;
	}
	y += line_height;
	int x = menu_margin + 250;
	unsigned int lineColor = default_color;
	if (currentLineIndex_ == keyCommandTable_.size())
	{
		x += 10;
		DrawString(x - 20, y, _T("→"), 0xff0000);
	}
	DrawString(x, y, _T("確定"), lineColor);
	
	
}

void KeyConfigScene::CommitCurrentKeySetting()
{
	//input本体のキー情報書き換えている
	for (const auto& cmd : keyCommandTable_)
	{
		input_.commandTable_[cmd.first] = cmd.second;
	}
}

std::string KeyConfigScene::GetKeyName(int keycode)
{
	wchar_t name[16];
	//mapのfindはイテレータを返す
	auto it = keynameTable_.find(keycode);

	//なかったらイテレータはend()になる
	if (it == keynameTable_.end())
	{
		wsprintf(name, "%02f", keycode);
		return name;
	}
	//見つかったら返す
	return(it->second);
}

KeyConfigScene::KeyConfigScene(SceneManager& manage,Input& input) : Scene(manage),input_(input)
{
	keyCommandTable_ = input.GetCommandTable();
	updateFunc_ = &KeyConfigScene::AppearInupdate;
	drawFunc_ = &KeyConfigScene::NormalDraw;

	menuItems_ =
	{
		"jump",
		"attack",
		"OK",
		"cancel",
		"pause",
		"keyconf"

	};
}

void KeyConfigScene::Update(Input& input)
{
	(this->*updateFunc_)(input);
}

void KeyConfigScene::Draw()
{

	(this->*drawFunc_)();

}
