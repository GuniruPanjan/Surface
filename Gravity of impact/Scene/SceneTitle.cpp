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
	//�^�C�g�����S��ǂݍ���
	Titlelogo = LoadGraph("data/GravityImpact���S.png");
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//���͂ŃV�[���J��
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneTitle::Draw()
{
	//�^�C�g�����S�̏����ʒu
	int Titlelogox, Titlelogoy;

	Titlelogox = 0;
	Titlelogoy = -100;

	DrawString(205, 300, "Push Any Button", GetColor(255, 255, 255));

	//�^�C�g�����S������
	DrawGraph(Titlelogox, Titlelogoy, Titlelogo, true);
}

void SceneTitle::End()
{
}
