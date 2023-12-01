#include "Map.h"
#include "Player.h"
#include "DxLib.h"

Player player;

void Map::InitMap()
{
	
}

void Map::UpdateMap(int ScrollX, int ScrollY)
{
	MAP_SIZE_WIDTH + ScrollX;
}

void Map::DrawMap(int ScrollX, int ScrollY)
{
	

	//描画するマップチップの数をセット
	DrawMapChipNumX = STAGE_WIDTH / MAPCHIP_WIDTH;
	DrawMapChipNumY = STAGE_HEIGHT / MAPCHIP_HEIGHT;

	//画面左上に描画するマップ座標をセット
	MapDrawPointX = player.PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = player.PlayerY - (DrawMapChipNumY / 2 - 1);

	//for (j = 0; j < MAP_SIZE_HEIGHT; j++)
	//{
	//	for (i = 0; i < MAP_SIZE_WIDTH; i++)
	//	{
	//		DrawW = i * MAPCHIP_WIDTH;
	//		DrawH = j * MAPCHIP_HEIGHT;
	//		//1はブロックを表しているから1のところだけ描画
	//		if (g_MapChipFirst[j][i] == 1)
	//		{
	//			DrawMapGraph = DrawGraph(DrawW + ScrollX, DrawH + ScrollY, maped.Block, true);
	//		}
	//	}
	//}

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
			}
		}
	}
	
	

	GetGraphSize(maped.Block, &maped.W, &maped.H);
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
