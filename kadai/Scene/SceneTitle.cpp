#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneChoice.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	//�w�i�摜�ǂݍ���
	TitleSceneGraph = LoadGraph("date/�X�^�[�g���.png");
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//�t�F�[�h������
	if (FeadColor >= 255)
	{
		FeadMinus = true;
		FeadPlus = false;
	}
	else if(FeadColor <= 0)
	{
		FeadPlus = true;
		FeadMinus = false;
	}

	if (FeadPlus == true)
	{
		FeadColor++;
	}
	else if (FeadMinus == true)
	{
		FeadColor--;
	}

	//���͂ŃV�[���J��
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();
}

void SceneTitle::Draw()
{
	//�w�i�摜�`��
	DrawGraph(0, 0, TitleSceneGraph, true);

	DrawString(245, 230, "Push Any Button", GetColor(FeadColor, FeadColor, FeadColor));
}

void SceneTitle::End()
{
}
