#include "WalkEnemy.h"

#include "DxLib.h"


WalkEnemy::WalkEnemy():
	WalkEnemyGraph(0),
	WalkEnemyX(610),
	WalkEnemyY(230),
	WalkEnemyW(0),
	WalkEnmeyH(0)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init()
{
	

	

}

void WalkEnemy::Update()
{
	for (int i = 0; i < SHOT; i++)
	{
		if (shot[i].Flag == 1)
		{
			//敵とのあたり判定
			if (((shot[i].X > WalkEnemyX && shot[i].X < WalkEnemyX + WalkEnemyW) ||
				(WalkEnemyX > shot[i].X && WalkEnemyX < shot[i].X + shot[i].Width)) &&
				((shot[i].Y > WalkEnemyY && shot[i].Y < WalkEnemyY + WalkEnmeyH) ||
					(WalkEnemyY > shot[i].Y && WalkEnemyY < shot[i].Y + shot[i].Height)))
			{
				//接触している場合は当たった弾の存在を消す
				shot[i].Flag = 0;
			}
		}
	}
}

void WalkEnemy::Draw()
{
	WalkEnemyGraph = LoadGraph("date/エネミー(仮).png");
	//エネミーの大きさ取得
	GetGraphSize(WalkEnemyGraph, &WalkEnemyW, &WalkEnmeyH);

	DrawGraph(WalkEnemyX, WalkEnemyY, WalkEnemyGraph, true);
	//WalkEnemyGraph = DrawBox(WalkEnemyX, WalkEnemyY, 630, 250, GetColor(255, 255, 0), true);
}
