#include "SceneGame.h"
#include "DxLib.h"
#include "Player/Player.h"
#include "SceneGoal.h"
#include "SceneDead.h"
#include "Map/Map.h"
#include "Map/BlackHole.h"
#include<memory>

//Playerを管理するポインタ
//std::shared_ptr<Player> player = std::make_shared<Player>();
Player Play;

//BlackHoleを管理するポインタ
//std::shared_ptr<BlackHole> blackhole = std::make_shared<BlackHole>();
BlackHole blackhole;

//マップを管理するポインタ
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
	//PlayerのInit
	Play.Init();

	//MapのInit
	map.Init();

	//BlackのInit
	blackhole.Init();

	//背景画像を読み込み
	GameSceneGraph = LoadGraph("date/背景画像.png");
}

std::shared_ptr<SceneBase> SceneGame::Update()
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
}

void SceneGame::End()
{
}
