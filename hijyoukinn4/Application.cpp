#include "Application.h"
#include<Dxlib.h>
#include "SceneManager.h"
#include "TitleScene.h"
#include "Input.h"
#include<cassert>

//cpp����namespace{�ϐ�}�Ə������ꍇ�A�u����namespace�v�Ƃ����đ���cpp�Ɩ��O�����Ԃ�Ȃ��悤�ɂ�����̂ł�
//����namespace��()�ɂ�����ꂽ���̂�
namespace
{
	constexpr int screen_width = 640;
	constexpr int screen_height = 480;
}

int MyLoadGraph(const TCHAR* path)
{
	int handle = LoadGraph(path);
	assert(handle > 0);
	return handle;
}

void Application::Terminate()
{
	DxLib_End();
}

Application::Application()
{
	windowSize_ = { screen_width, screen_height };
}

bool Application::Init()
{
	ChangeWindowMode(true);
	SetGraphMode(windowSize_.w, windowSize_.h, 32);
	SetWindowText(L"�݂�݂�");
	if (DxLib_Init() == -1)
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void Application::Run()
{
	SceneManager manager;
	manager.ChangeScene(std::make_shared<TitleScene>(manager));
	Input input;
	while (ProsessMessage() != -1)
	{
		ClearDrawScreen();
		manager.Update(input);
		manager.Draw();
		ScreenFlip();
	}
	Terminate();
}

const Size& Application::GetWindowSize() const
{
	return windowSize_;
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}
