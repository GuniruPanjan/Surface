#include "BlackHole.h"

BlackHole::BlackHole() :
	BlackHole3D(0),
	BlackHoleX(0),
	BlackHoleY(0),
	pos(VGet(0,0,0)),
	BlackHoleWidth(0),
	BlackHoleHight(0),
	BlackDead(false),
	AttakFlag(false),
	Time(0),
	TimeNow(0),
	AttakRandom(0),
	Attakinterval(0)
{
}

BlackHole::~BlackHole()
{
	MV1DeleteModel(BlackHole3D);
}

void BlackHole::Init()
{
	//ブラックホールの初期位置
	BlackHoleX = 0;
	BlackHoleY = 240;

	//3Dのブラックホールの初期位置
	pos = VGet(-420, -290, 0);

	//ブラックホールの幅
	BlackHoleWidth = 150;
	BlackHoleHight = 480;

	BlackDead = false;

	//3Dモデルを読み込む
	BlackHole3D = MV1LoadModel("date/BlackHole.mv1");

	//3Dモデルのポジション設定
	MV1SetPosition(BlackHole3D, pos);

	//3Dモデルのスケール設定
	MV1SetScale(BlackHole3D, VGet(Scale, Scale, Scale));

	Graph = LoadGraph("date/斬撃.png");

	TimeNow = GetNowCount();

	Attakinterval = 1;

}

void BlackHole::InitBack(BlackHoleAttak attak[], int Size)
{
	//ブラックホールの初期位置
	BlackHoleX = 0;
	BlackHoleY = 240;

	//3Dのブラックホールの初期位置
	pos = VGet(-420, -290, 0);

	//ブラックホールの幅
	BlackHoleWidth = 150;
	BlackHoleHight = 480;

	BlackDead = false;

	//3Dモデルを読み込む
	BlackHole3D = MV1LoadModel("date/BlackHole.mv1");

	//3Dモデルのポジション設定
	MV1SetPosition(BlackHole3D, pos);

	//3Dモデルのスケール設定
	MV1SetScale(BlackHole3D, VGet(Scale, Scale, Scale));

	Graph = LoadGraph("date/斬撃.png");

	TimeNow = GetNowCount();

	Attakinterval = 1;

	for (int i = 0; i < Size; i++)
	{
		attak[i].AttakGraph = Graph;

		attak[i].AttakSpeed = 5;

		attak[i].AttakX = -30;

		attak[i].AttakY = -30;

		attak[i].Existence = false;
	}
}

void BlackHole::Update(Player& player)
{

	//当たり判定をつける
	BlackHoleRect.SetCenter(static_cast<float>(BlackHoleX), static_cast<float>(BlackHoleY), static_cast<float>(BlackHoleWidth), static_cast<float>(BlackHoleHight));

	//ブラックホールで死んだ判定
	if (BlackHoleRect.IsCollision(player.m_colrect) == true)
	{
		BlackDead = true;
	}
}

void BlackHole::Draw()
{
	//3Dモデルを描画する
	MV1DrawModel(BlackHole3D);
	//当たり判定を描画する
	//BlackHoleRect.Draw(GetColor(0, 0, 0), false);

	
}

void BlackHole::DrawBack(BlackHoleAttak attak[], int Size)
{
	//3Dモデルを描画する
	MV1DrawModel(BlackHole3D);

	
	for (int i = 0; i < Size; i++)
	{
		DrawGraph(attak[i].AttakX, attak[i].AttakY, attak[i].AttakGraph, false);

		attak[i].AttakRect.Draw(GetColor(255, 255, 255), false);
	}
}

void BlackHole::Attak(Player& player,BlackHoleAttak attak[], int Size)
{
	//現在時間を得る
	Time = (GetNowCount() - TimeNow) / 1000;

	if (Time >= 1 * Attakinterval)
	{
		AttakRandom = GetRand(1);

		if (AttakRandom == 0)
		{
			//攻撃しない
		}
		//攻撃する
		if (AttakRandom == 1)
		{
			for (int i = 0; i < Size; i++)
			{
				attak[i].AttakX = 50 + player.PlayerScroll;
				attak[i].AttakY = 320;

				attak[i].Existence = true;

				//1回だしたからループから抜ける
				break;
			}
		}

		Attakinterval += 1;
	}

	for (int i = 0; i < Size; i++)
	{
		if (attak[i].Existence == true)
		{
			attak[i].AttakX += attak[i].AttakSpeed;

			attak[i].AttakRect.SetCenter(static_cast<float>(attak[i].AttakX), static_cast<float>(attak[i].AttakY), static_cast<float>(40), static_cast<float>(40));
		}
	}

}
