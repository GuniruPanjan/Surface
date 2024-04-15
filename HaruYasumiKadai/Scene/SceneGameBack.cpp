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
	//Player‚ÌInit
	Play.InitBack();

	//Map‚ÌInit
	map.Init();

	//Black‚ÌInit
	blackhole.Init();

	//”wŒi‰æ‘œ‚ğ“Ç‚İ‚İ
	GameSceneGraph = LoadGraph("date/”wŒi‰æ‘œ.png");
}

std::shared_ptr<SceneBase> SceneGameBack::Update()
{
	//Player‚ÌUpdate
	Play.UpdateBack();

	//Map‚ÌUpdate
	map.Update();

	//BlackHole‚ÌUpdate
	blackhole.Update(Play);

	//ƒS[ƒ‹‚µ‚½‚ç
	if (map.MapGoal == true)
	{
		map.MapGoal = false;

		return std::make_shared<SceneGoal>();
	}

	//ƒ}ƒbƒv‚Å‚µ‚ñ‚¾‚ç
	if (map.MapDead == true || blackhole.BlackDead == true)
	{
		map.MapDead = false;

		blackhole.BlackDead = false;

		return std::make_shared<SceneDead>();
	}


	return shared_from_this(); //©g‚Ìshared_ptr‚ğ•Ô‚·
}

void SceneGameBack::Draw()
{
	DrawString(0, 0, "SceneGame", 0xffffff);

	//”wŒi‰æ‘œ‚ğ•`‚­
	DrawGraph(0, 0, GameSceneGraph, false);

	//Map‚ğ•`‚­
	//map->Draw(Play);
	map.DrawBack(Play);


	//Player‚ğ•`‚­
	//player->Draw();
	Play.DrawBack();

	//BlackHole‚ğ•`‚­
	blackhole.Draw();
}

void SceneGameBack::End()
{
}
