#include "SceneGame.h"
#include "DxLib.h"
#include "Player/Player.h"
#include "SceneGoal.h"
#include "SceneDead.h"
#include "Map/Map.h"
#include "Map/BlackHole.h"
#include<memory>



SceneGame::SceneGame():
	Time(0),
	TimeNow(0)
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

	Time = 0;

	TimeNow = GetNowCount();
	
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	//�o�ߎ��Ԃ𓾂�
	Time = (GetNowCount() - TimeNow) / 1000;

	if (Time >= 8)
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

	SetFontSize(35);
	//�n�܂�J�E���g�_�E��
	if (Time == 2)
	{
		DrawString(300, 200, "3", GetColor(255, 0, 0));
	}
	else if (Time == 4)
	{
		DrawString(300, 200, "2", GetColor(255, 0, 0));
	}
	else if (Time == 6)
	{
		DrawString(300, 200, "1", GetColor(255, 0, 0));
	}
	SetFontSize(25);
}

void SceneGame::End()
{
}

