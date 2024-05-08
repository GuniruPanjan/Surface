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
	PlayerZ(0.0f)
{
}

SceneGoal::~SceneGoal()
{
}

void SceneGoal::Init()
{
	//�w�i�摜�ǂݍ���
	GoalBack = LoadGraph("data/cloudy.png");

	//3D���f���ǂݍ���
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{
	//���͂ŃV�[���J��
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneTitle>();
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneGoal::Draw()
{
	//�w�i�摜�`��
	DrawGraph(0, 0, GoalBack, false);
}

void SceneGoal::End()
{
	//�摜���
	DeleteGraph(GoalBack);
}
