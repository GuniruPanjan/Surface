#include "WalkEnemy.h"
#include "DxLib.h"


WalkEnemy::WalkEnemy():
	WalkEnemyGraph(0),
	WalkEnemyX(610.00f),
	WalkEnemyY(360.00f),
	WalkEnemyWidth(20),
	WalkEnemyHeight(20),
	WalkEnemyW(0),
	WalkEnmeyH(0),
	WalkEnemySpeed(0.03f)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init()
{
	

	

}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemy& enemy)
{
	//敵の移動処理
	if (player.PlayerX - player.ScrollX <= enemy.WalkEnemyX)
	{
		enemy.WalkEnemyX -= enemy.WalkEnemySpeed;
	}
	else if (player.PlayerX - player.ScrollX > enemy.WalkEnemyX)
	{
		enemy.WalkEnemyX += enemy.WalkEnemySpeed;
	}

	//当たり判定の更新
	m_colRect.SetCenter(enemy.WalkEnemyX + 10 + player.ScrollX, enemy.WalkEnemyY + 10, enemy.WalkEnemyWidth, enemy.WalkEnemyHeight);


	if (shot.Flag == 1)
	{
		//敵との当たり判定
		if (m_colRect.IsCollision(shot.m_colRect) == false)
		{

		}
		else if (m_colRect.IsCollision(shot.m_colRect) == true)
		{
			DrawString(500, 0, "当たった", GetColor(255, 255, 255));
			HP -= shot.Damage;
			//接触している場合は当たった弾の存在を消す
			shot.Flag = 0;
		}

	}
}

void WalkEnemy::Draw(int ScrollX)
{
	

	WalkEnemyGraph = LoadGraph("date/エネミー(仮).png");
	//エネミーの大きさ取得
	GetGraphSize(WalkEnemyGraph, &WalkEnemyW, &WalkEnmeyH);

	DrawGraph(WalkEnemyX + ScrollX, WalkEnemyY, WalkEnemyGraph, true);

	//エネミーの当たり判定の表示
	m_colRect.Draw(GetColor(255, 0, 0), false);
	//WalkEnemyGraph = DrawBox(WalkEnemyX, WalkEnemyY, 630, 250, GetColor(255, 255, 0), true);

	//敵が死んだ時
	if (HP <= 0)
	{
		DeleteGraph(WalkEnemyGraph);
		point.PointNow += 100;
	}
}
