#include "SceneGameBack.h"
#include "DxLib.h"
#include "Player/Player.h"
#include "SceneGoal.h"
#include "SceneDeadBack.h"
#include "Map/Map.h"
#include "Map/BlackHole.h"
#include<memory>

BlackHoleAttak attak[ATTAK];

SceneGameBack::SceneGameBack():
	Time(0),
	TimeNow(0)
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
	blackhole.InitBack(attak,ATTAK);

	//”wŒi‰æ‘œ‚ğ“Ç‚İ‚İ
	GameSceneGraph = LoadGraph("date/”wŒi‰æ‘œ.png");

	Time = 0;

	TimeNow = GetNowCount();
}

std::shared_ptr<SceneBase> SceneGameBack::Update()
{
	//Œo‰ßŠÔ‚ğ“¾‚é
	Time = (GetNowCount() - TimeNow) / 1000;

	if (Time >= 8)
	{
		//Player‚ÌUpdate
		Play.UpdateBack();

		//Map‚ÌUpdate
		map.Update();

		//BlackHole‚ÌUpdate
		blackhole.Update(Play);

		blackhole.Attak(Play, attak, ATTAK);

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

			return std::make_shared<SceneDeadBack>();
		}

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
	blackhole.DrawBack(attak, ATTAK);
	

	SetFontSize(35);
	//n‚Ü‚éƒJƒEƒ“ƒgƒ_ƒEƒ“
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

void SceneGameBack::End()
{
}
