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
	//PlayerのInit
	Play.Init();

	//MapのInit
	map.Init();

	//BlackのInit
	blackhole.Init();

	//背景画像を読み込み
	GameSceneGraph = LoadGraph("date/背景画像.png");

	Time = 0;

	TimeNow = GetNowCount();
	
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	//経過時間を得る
	Time = (GetNowCount() - TimeNow) / 1000;

	if (Time >= 8)
	{
		//PlayerのUpdate
		Play.Update();

		//MapのUpdate
		map.Update();

		//BlackHoleのUpdate
		blackhole.Update(Play);

		//ゴールしたら
		if (map.MapGoal == true)
		{
			map.MapGoal = false;

			return std::make_shared<SceneGoal>();
		}

		//マップでしんだら
		if (map.MapDead == true || blackhole.BlackDead == true)
		{
			map.MapDead = false;

			blackhole.BlackDead = false;

			return std::make_shared<SceneDead>();
		}
	}

	return shared_from_this(); //自身のshared_ptrを返す
}

void SceneGame::Draw()
{
	DrawString(0, 0, "SceneGame", 0xffffff);

	//背景画像を描く
	DrawGraph(0, 0, GameSceneGraph, false);

	//Mapを描く
	//map->Draw(Play);
	map.Draw(Play);
	

	//Playerを描く
	//player->Draw();
	Play.Draw();

	//BlackHoleを描く
	blackhole.Draw();

	SetFontSize(35);
	//始まるカウントダウン
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

