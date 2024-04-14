#include "SceneGame.h"
#include "DxLib.h"
#include "Player/Player.h"
#include "SceneGoal.h"
#include "SceneDead.h"
#include "Map/Map.h"
#include "Map/BlackHole.h"
#include<memory>

//Player���Ǘ�����|�C���^
//std::shared_ptr<Player> player = std::make_shared<Player>();
Player Play;

//BlackHole���Ǘ�����|�C���^
//std::shared_ptr<BlackHole> blackhole = std::make_shared<BlackHole>();
BlackHole blackhole;

//�}�b�v���Ǘ�����|�C���^
//std::shared_ptr<Map> map = std::make_shared<Map>();
Map map;

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	//Player��Init
	Play.Init();

	//Map��Init
	map.Init();

	//Black��Init
	blackhole.Init();

	//�w�i�摜��ǂݍ���
	GameSceneGraph = LoadGraph("date/�w�i�摜.png");
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	//Player��Update
	Play.Update();

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

void SceneGame::Draw()
{
	DrawString(0, 0, "SceneGame", 0xffffff);

	//�w�i�摜��`��
	DrawGraph(0, 0, GameSceneGraph, false);

	//Map��`��
	//map->Draw(Play);
	map.Draw(Play);

	//Player��`��
	//player->Draw();
	Play.Draw();

	//BlackHole��`��
	blackhole.Draw();
}

void SceneGame::End()
{
}
