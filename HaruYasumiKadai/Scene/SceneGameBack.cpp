#include "SceneGameBack.h"
#include "DxLib.h"
#include "Player/Player.h"
#include "SceneGoal.h"
#include "SceneDead.h"
#include "Map/Map.h"
#include "Map/BlackHole.h"
#include<memory>

SceneGameBack::SceneGameBack()
{
}

SceneGameBack::~SceneGameBack()
{
}

void SceneGameBack::Init()
{
	//Player��Init
	Play.InitBack();

	//Map��Init
	map.Init();

	//Black��Init
	blackhole.Init();

	//�w�i�摜��ǂݍ���
	GameSceneGraph = LoadGraph("date/�w�i�摜.png");
}

std::shared_ptr<SceneBase> SceneGameBack::Update()
{
	//Player��Update
	Play.UpdateBack();

	//Map��Update
	map.Update();

	//BlackHole��Update
	blackhole.Update(Play);

	//�S�[��������
	if (map.MapGoal == true)
	{
		map.MapGoal = false;

		return std::make_shared<SceneGoal>();
	}

	//�}�b�v�ł��񂾂�
	if (map.MapDead == true || blackhole.BlackDead == true)
	{
		map.MapDead = false;

		blackhole.BlackDead = false;

		return std::make_shared<SceneDead>();
	}


	return shared_from_this(); //���g��shared_ptr��Ԃ�
}

void SceneGameBack::Draw()
{
	DrawString(0, 0, "SceneGame", 0xffffff);

	//�w�i�摜��`��
	DrawGraph(0, 0, GameSceneGraph, false);

	//Map��`��
	//map->Draw(Play);
	map.DrawBack(Play);


	//Player��`��
	//player->Draw();
	Play.DrawBack();

	//BlackHole��`��
	blackhole.Draw();
}

void SceneGameBack::End()
{
}
