#include "SceneGoal.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneGoal::SceneGoal():
	Map(0),
	Player(0),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	PlayerX(0.0f),
	PlayerY(0.0f),
	PlayerZ(0.0f),
	SceneChange(false)
{
}

SceneGoal::~SceneGoal()
{
}

void SceneGoal::Init()
{
	//�t�F�[�h�̏�����
	fedo->Init();

	//�w�i�摜�ǂݍ���
	GoalBack = LoadGraph("data/cloudy.png");

	//3D���f���ǂݍ���
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{
	//�t�F�[�h���s��
	fedo->Update();

	//���͂ŃV�[���J��
	if (CheckHitKeyAll())
	{
		//�t�F�[�h�A�E�g���s��
		fedo->Fedo = true;

		SceneChange = true;
	}

	//�V�[���J��
	if (fedo->Start <= 0 && SceneChange == true)
	{
		return std::make_shared<SceneTitle>();
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneGoal::Draw()
{
	//�w�i�摜�`��
	DrawGraph(0, 0, GoalBack, false);

	//�t�F�[�h
	fedo->Draw();
}

void SceneGoal::End()
{
	//�摜���
	DeleteGraph(GoalBack);
}
