#include "SceneChoice.h"
#include "DxLib.h"
#include "SceneGame.h"

SceneChoice::SceneChoice():
	X(0),
	Y(0)
{
}

SceneChoice::~SceneChoice()
{
}

void SceneChoice::Init()
{
	//�w�i�摜��ǂݍ���
	ChoiceSceneGraph = LoadGraph("date/�I���摜.png");

	//����������
	X = 320;
	Y = 240;
}

std::shared_ptr<SceneBase> SceneChoice::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return std::make_shared<SceneGame>();
	}

	return shared_from_this(); //���g��share_ptr��Ԃ�
}

void SceneChoice::Draw()
{
	//�w�i�摜�`��
	DrawGraph(0, 0, ChoiceSceneGraph, true);

	DrawCircle(X - 15, Y + 7, 8, GetColor(255, 255, 255), true);

	DrawString(0, 0, "SceneChoice", 0xffffff);

	DrawString(X, Y, "STAGE 1", 0xffffff);
}

void SceneChoice::End()
{
}
