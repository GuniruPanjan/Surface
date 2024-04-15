#include "Map.h"
#include "Scene/SceneGoal.h"
#include "Scene/SceneChoice.h"

std::shared_ptr<SceneChoice> choice = std::make_shared<SceneChoice>();

Map::Map() :
	m_Graph(0),
	Time(0),
	MapTime(0),
	Scroll(0),
	MapGoal(false),
	MapDead(false),
	Scale(0.0f)
{
}

Map::~Map()
{
	DeleteGraph(m_Graph);

	MV1DeleteModel(Model);
}

void Map::Init()
{
	//マップのロード
	m_Graph = LoadGraph("date/Tail.png");

	//スクロールを初期化処理する
	Scroll = 0;

	//現在時間を得る
	Time = GetNowCount();

	MapGoal = false;

	MapDead = false;

	Scale = 2.0f;

	//3Dmodel読み込み
	Model = MV1LoadModel("date/Doar.mv1");

	//ポジション設定
	posmodel = VGet(200, 300, 0);
}

void Map::Update()
{
	//3DModelポジション設定
	MV1SetPosition(Model, posmodel);

	//3DModelのスケール設定
	MV1SetScale(Model, VGet(Scale, Scale, Scale));

	//経過時間を得る
	MapTime = (GetNowCount() - Time) / 1000;

	//時間が立つとスクロールする
	if (MapTime >= 10)
	{
		Scroll -= 1;
	}

}

void Map::Draw(Player& player)
{
	//3Dモデル描画
	MV1DrawModel(Model);

	//マップを描く
	for (int i = 0; i < MAP_SIZE_WIDTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_HEIGHT; j++)
		{
			//マップデータが1だったら描画する
			if (First_Map[j][i] == 1)
			{
				DrawGraph(i * MAPCHIP_WIDTH + Scroll, j * MAPCHIP_HEIGHT, m_Graph, true);
			}

			//マップデータが2だったらゴールを描画する
			if (First_Map[j][i] == 2)
			{
				DrawGraph(i * MAPCHIP_WIDTH + Scroll, j * MAPCHIP_HEIGHT, m_Graph, true);

				//当たり判定をつける
				m_colRectGoal.SetCenter(static_cast<float>(i * MAPCHIP_WIDTH + 15 + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_WIDTH), static_cast<float>(MAPCHIP_HEIGHT));

				//当たり判定描画
				m_colRectGoal.Draw(GetColor(255, 255, 255), false);

				//Playerがゴールしたら
				if (m_colRectGoal.IsCollision(player.m_colrect) == true)
				{
					MapGoal = true;
				}
			}

			//マップデータが0だったら当たり判定をつける
			if (First_Map[j][i] == 0)
			{
				m_colRect.SetCenter(static_cast<float>((i * MAPCHIP_WIDTH + 15) + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_FALLX), static_cast<float>(MAPCHIP_FALLY));

				//当たり判定描画
				//m_colRect->Draw(GetColor(255, 255, 255), false);

				//マップで死んだら
				if (m_colRect.IsCollision(player.m_colrect) == true)
				{
					MapDead = true;
				}
			}
		}
	}

	

}

void Map::DrawBack(Player& player)
{
	//3Dモデル描画
	MV1DrawModel(Model);

	//マップを描く
	for (int i = 0; i < MAP_SIZE_WIDTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_HEIGHT; j++)
		{
			//マップデータが1だったら描画する
			if (First_Mapback[j][i] == 1)
			{
				DrawGraph(i * MAPCHIP_WIDTH + Scroll, j * MAPCHIP_HEIGHT, m_Graph, true);
			}

			//マップデータが3だったら描画する
			if (First_Mapback[j][i] == 3)
			{
				m_colRect.SetCenter(static_cast<float>((i * MAPCHIP_WIDTH + 15) + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_WIDTH), static_cast<float>(MAPCHIP_HEIGHT));
			}

			if (First_Mapback[j][i] == 2)
			{
				//当たり判定をつける
				m_colRectGoal.SetCenter(static_cast<float>(i * MAPCHIP_WIDTH + 15 + Scroll), static_cast<float>(j * MAPCHIP_HEIGHT + 15), static_cast<float>(MAPCHIP_WIDTH), static_cast<float>(MAPCHIP_HEIGHT));

				//当たり判定描画
				m_colRectGoal.Draw(GetColor(255, 255, 255), false);

				//Playerがゴールしたら
				if (m_colRectGoal.IsCollision(player.m_colrect) == true)
				{
					MapGoal = true;
				}
			}
		}
	}
}

