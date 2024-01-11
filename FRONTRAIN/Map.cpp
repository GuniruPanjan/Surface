#include "Map.h"
#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"

//Player player;

Map::Map():
	ScrollX(0),
	ScrollY(0),
	i(0),
	j(0),
	MapDrawPointX(0),
	MapDrawPointY(0),
	DrawMapChipNumX(0),
	DrawMapChipNumY(0),
	DrawW(0),
	DrawH(0),
	DrawMapGraph(0),
	FiveMasu(-1),
	FourMasu(-1),
	SixMasu(-1),
	Five(false),
	Four(true),
	Six(true),
	MapDistanceFive(0),
	MapDistanceFour(0),
	MapDistanceSix(0),
	MapSelection(true),
	MapSeparator(637)
{
}

Map::~Map()
{
}

void Map::InitMap()
{
	
}

void Map::UpdateMap(int ScrollX)
{
	MAP_SIZE_WIDTH + ScrollX;

	if (Five == false)
	{
		FiveMasu = GetRand(2);

		MapDistanceFive = 640 - ScrollX;
	}
	if (Four == false)
	{
		FourMasu = GetRand(1);

		MapDistanceFour = 640 - ScrollX;
	}
	if (Six == false)
	{
		SixMasu = GetRand(2);

		MapDistanceSix = 640 - ScrollX;
	}

	if (MapSeparator + ScrollX <= 0)
	{
		MapSelection = false;

		if (MapSelection == false)
		{
			MapSeparator += 640;
		}
	}


}

void Map::DrawMap(int ScrollX, Shot& shot,Player& player,WalkEnemyStruct Wenemy[])
{
	maped.Block = LoadGraph("date/ブロック.png");

	//描画するマップチップの数をセット
	DrawMapChipNumX = STAGE_WIDTH / MAPCHIP_WIDTH;
	DrawMapChipNumY = STAGE_HEIGHT / MAPCHIP_HEIGHT;

	//画面左上に描画するマップ座標をセット
	MapDrawPointX = player.PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = player.PlayerY - (DrawMapChipNumY / 2 - 1);

	//マップを描く
	for (i = 0; i < DrawMapChipNumY; i++)
	{
		for (j = 0; j < DrawMapChipNumX; j++)
		{
			//画面からはみ出た位置なら描画しない
			/*if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_SIZE_WIDTH || i + MapDrawPointY >= MAP_SIZE_HEIGHT) continue;*/

			//マップデータが１だったらブロックを描画する
			if (g_MapChipFirst[i][j] == 1)
			{
				DrawGraph(j * MAPCHIP_WIDTH + ScrollX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

				//当たり判定の更新
				m_colRect.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX,i * MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH,MAPCHIP_HEIGHT);

				//マップチップの当たり判定の表示
				m_colRect.Draw(GetColor(255, 255, 255), false);
				

				//shotの当たり判定false
				if (m_colRect.IsCollision(shot.m_colRect) == false)
				{
					//shotが壁に当たってない時
				}
				else if (m_colRect.IsCollision(shot.m_colRect) == true)
				{
					//shotが壁に当たった時弾の存在を消す
					shot.Flag = 0;
				}

				if (m_colRect.IsCollision(player.m_colRect) == true)
				{
					//ブロックに当たっていたら壁を上る
					player.PlayerY -= 0.15f;
					//地面に触れると重力が0になる
					//player.Gravity = 0;
				}

				for (int g = 0; g < ENEMY_NOW; g++)
				{
					if (m_colRect.IsCollision(Wenemy[g].m_colRect) == true)
					{
						//ブロックに当たっていたら壁を上る
						Wenemy[g].WalkEnemyY -= 0.04f;
					}
				}
				
			}
			//マップが端に到達したとき
			if (g_MapChipFirst[i][j] == 2)
			{
				//当たり判定の更新
				m_colBlockRect2.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX, i * MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH, MAPCHIP_HEIGHT);

				//マップチップの当たり判定の表示
				m_colBlockRect2.Draw(GetColor(0, 255, 255), false);

				if (m_colBlockRect2.IsCollision(player.m_colRect) == true)
				{
					//プレイヤーを落とす
					player.PlayerY += 0.1f;
				}

				for (int g = 0; g < ENEMY_NOW; g++)
				{
					if (m_colBlockRect2.IsCollision(Wenemy[g].m_colRect) == true)
					{
						//エネミーを落とす
						Wenemy[g].WalkEnemyY += 0.05f;
						DrawString(200, 200, "降りた", GetColor(255, 255, 255));
					}
				}
			}

			//↓はランダム配置のマップ形成
			//FiveMasuが0だった場合
			if (FiveMasu == 0)
			{
				if (g_MapChip_1[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceFive, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Five = true;
				
				if (MapSelection == false)
				{
					Four = false;
				}
				MapSelection = true;
				
			}
			
			//FiveMasuが1だった場合
			if (FiveMasu == 1)
			{
				if (g_MapChip_4[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceFive, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Five = true;
				

				if (MapSelection == false)
				{
					Four = false;
				}
				MapSelection = true;
				
			}
			//FiveMasuが2だった場合
			if (FiveMasu == 2)
			{
				if (g_MapChip_8[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceFive, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Five = true;

				if (MapSelection == false)
				{
					Six = false;
				}
				MapSelection = true;
				
			}


			//FourMasuが0だった場合
			if (FourMasu == 0)
			{
				if (g_MapChip_2[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceFour, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Four = true;

				if (MapSelection == false)
				{
					Six = false;
				}
				MapSelection = true;
				
			}
			//FourMasuが１だった場合
			if (FourMasu == 1)
			{
				if (g_MapChip_5[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceFour, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Four = true;

				if (MapSelection == false)
				{
					Six = false;
				}
				MapSelection = true;
				
			}


			//SixMasuが0だった場合
			if (SixMasu == 0)
			{
				if (g_MapChip_3[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceSix, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Six = true;

				if (MapSelection == false)
				{
					Five = false;
				}
				MapSelection = true;
				
			}
			//SixMasuが1だった場合
			if (SixMasu == 1)
			{
				if (g_MapChip_6[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceSix, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Six = true;

				if (MapSelection == false)
				{
					Four = false;
				}
				MapSelection = true;
				
			}
			//SixMasuが2だった場合
			if (SixMasu == 2)
			{
				if (g_MapChip_9[i][j] == 1)
				{
					DrawGraph(j * MAPCHIP_WIDTH + ScrollX + MapDistanceSix, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);
				}
				Six = true;


				if (MapSelection == false)
				{
					Five = false;
				}
				MapSelection = true;
				
			}
			
		}
	}
}

int Map::GetChipParm(float X, float Y)
{
	int x, y;
	//整数値へ変換
	x = (int)X / MAPCHIP_WIDTH;
	y = (int)Y / MAPCHIP_HEIGHT;

	//マップからはみ出ていたら0を返す
	//if (x >= MAP_SIZE_WIDTH || y >= MAP_SIZE_HEIGHT || x < 0 || y < 0) return 0;
	
	//指定の座標に該当するマップの情報を返す
	return g_MapChipFirst[y][x];
}

int Map::GetChipUnder(float Y)
{
	int y;
	//整数値へ変換
	y = (int)Y / MAPCHIP_HEIGHT;

	//マップからはみ出ていたら0を返す
	//if ( y < 0) return 0;

	for (int i = 0; i < MAP_SIZE_WIDTH; i++)
	{
		return g_MapChipFirst[y][i];
	}
	
}
