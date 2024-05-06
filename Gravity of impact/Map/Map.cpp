#include "Map.h"


Map::Map():
	MapObject(0),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	MapScale(0.0f)
{
	MapPosition = VGet(0.0f, 0.0f, 0.0f);
}

Map::~Map()
{
}

void Map::Init()
{
	//Mapの初期座標代入
	MapX = 0.0f;
	MapY = -470.0f;
	MapZ = 0.0f;

	//Mapの大きさ設定
	MapScale = 12.0f;

	//3Dモデル読み込み
	MapObject = MV1LoadModel("data/MapCube.mv1");

	//Mapの大きさを変える
	MV1SetScale(MapObject, VGet(MapScale, MapScale, MapScale));

	//マップの初期配置
	MapPosition = VGet(MapX, MapY, MapZ);
}

void Map::Update(Player& player)
{
	//マップの当たり判定をとる
	m_colrect.SetCenter(-230.0f, -225.0f, 220.0f, 450.0f, 220.0f, -450.0f);
}

void Map::Draw(Player& player)
{
	//3Dマップの設置をする
	MV1SetPosition(MapObject, MapPosition);

	//3Dモデルを描画する
	MV1DrawModel(MapObject);

	//当たり判定を描画する
	m_colrect.Draw(GetColor(255, 0, 0), false);

	//プレイヤーに当たっていると
	if (m_colrect.IsCollision(player.m_colrect) == true)
	{
		DrawString(200, 130, "当たっている", GetColor(255, 255, 255));
	}
}

void Map::End()
{
	MV1DeleteModel(MapObject);
}
