#include "Map.h"
// 重力加速度
#define GravitationalAcceleration 9.80665 / 2

Map::Map():
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	MapdistanceX(0.0f),
	MapdistanceY(0.0f),
	MapdistanceZ(0.0f),
	MapWidth(0.0f),
	MapHeight(0.0f),
	MapDepth(0.0f),
	Goal(false)
{
	
}

Map::~Map()
{
}

void Map::Init()
{
	//Mapの初期座標代入
	MapX = 0.0f;
	MapY = -478.0f;
	MapZ = 0.0f;

	//Mapの規則的距離
	MapdistanceX = 500.0f;
	MapdistanceY = 800.0f;
	MapdistanceZ = 500.0f;

	//Mapの当たり判定の大きさ
	MapWidth = 450.0f;
	MapHeight = 220.0f;
	MapDepth = -450.0f;

	//マップの位置を初期化
	obustructmap1->SetPos(VGet(MapX, MapY, MapZ));
	obustructmap2->SetPos(VGet(MapX, MapY - MapdistanceY, MapZ + MapdistanceZ));
	obustructmap3->SetPos(VGet(MapX, MapY - MapdistanceY * 2, MapZ));
	obustructmap4->SetPos(VGet(MapX - MapdistanceX, MapY - MapdistanceY * 3, MapZ));
	obustructmap5->SetPos(VGet(MapX - MapdistanceX, MapY - MapdistanceY * 4, MapZ - MapdistanceZ));
	obustructmap6->SetPos(VGet(MapX, MapY - MapdistanceY * 5, MapZ - MapdistanceZ));
	obustructmap7->SetPos(VGet(MapX, MapY - MapdistanceY * 6, MapZ));
	obustructmap8->SetPos(VGet(MapX + MapdistanceX, MapY - MapdistanceY * 7, MapZ));
	obustructmap9->SetPos(VGet(MapX, MapY - MapdistanceY * 8, MapZ));
	obustructmap10->SetPos(VGet(MapX, MapY - MapdistanceY * 9, MapZ - MapdistanceZ));
}

void Map::Update(Player& player)
{
	//マップの当たり判定をとる
	m_colrect.SetCenter(-230.0f, -220.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect2.SetCenter(-230.0f, -1023.0f, 720.0f, MapWidth, MapHeight, MapDepth);
	m_colrect3.SetCenter(-230.0f, -1822.5f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect4.SetCenter(-730.0f, -2623.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect5.SetCenter(-730.0f, -3423.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_colrect6.SetCenter(-230.0f, -4223.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_colrect7.SetCenter(-230.0f, -5023.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect8.SetCenter(270.0f, -5823.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect9.SetCenter(-230.0f, -6623.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect10.SetCenter(-230.0f, -7422.0f, -280.0f, MapWidth, MapHeight, MapDepth);


	//障害物制御
	obustructmap1->Update();
	obustructmap2->Update();
	obustructmap3->Update();
	obustructmap4->Update();
	obustructmap5->Update();
	obustructmap6->Update();
	obustructmap7->Update();
	obustructmap8->Update();
	obustructmap9->Update();
	obustructmap10->Update();

	//プレイヤーに当たっていると
	if (m_colrect.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect2.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect3.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect4.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect5.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect6.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect7.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect8.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	else if (m_colrect9.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
	}
	//ゴール
	else if (m_colrect10.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		Goal = true;
	}
	//プレイヤーに当たってないと
	else if (m_colrect.IsCollision(player.m_colrect) == false || m_colrect2.IsCollision(player.m_colrect) == false)
	{
		player.PlayerGravity = player.Playerweight * GravitationalAcceleration;
	}
	
}

void Map::Draw(Player& player)
{

	//障害物描画
	obustructmap1->Draw();
	obustructmap2->Draw();
	obustructmap3->Draw();
	obustructmap4->Draw();
	obustructmap5->Draw();
	obustructmap6->Draw();
	obustructmap7->Draw();
	obustructmap8->Draw();
	obustructmap9->Draw();
	obustructmap10->Draw();



	//当たり判定を描画する
	m_colrect.Draw(GetColor(255, 0, 0), false);
	m_colrect2.Draw(GetColor(255, 0, 0), false);
	m_colrect3.Draw(GetColor(255, 0, 0), false);
	m_colrect4.Draw(GetColor(255, 0, 0), false);
	m_colrect5.Draw(GetColor(255, 0, 0), false);
	m_colrect6.Draw(GetColor(255, 0, 0), false);
	m_colrect7.Draw(GetColor(255, 0, 0), false);
	m_colrect8.Draw(GetColor(255, 0, 0), false);
	m_colrect9.Draw(GetColor(255, 0, 0), false);
	m_colrect10.Draw(GetColor(255, 0, 0), false);




	//プレイヤーに当たっていると
	if (m_colrect.IsCollision(player.m_colrect) == true)
	{
		DrawString(200, 130, "当たっている", GetColor(255, 255, 255));
	}
}

void Map::End()
{
	//モデルのアンロード
	obustructmap1->~ObstructMap();
	obustructmap2->~ObstructMap();
	obustructmap3->~ObstructMap();
	obustructmap4->~ObstructMap();
	obustructmap5->~ObstructMap();
	obustructmap6->~ObstructMap();
	obustructmap7->~ObstructMap();
	obustructmap8->~ObstructMap();
	obustructmap9->~ObstructMap();
	obustructmap10->~ObstructMap();

}
