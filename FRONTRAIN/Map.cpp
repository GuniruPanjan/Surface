#include "Map.h"
#include "Player.h"
#include "DxLib.h"

Player player;

void Map::InitMap()
{
	
}

void Map::UpdateMap()
{
	maped.width_chip_num = (int)maped.W / MAPCHIP_WIDTH;
	maped.height_chip_num = (int)maped.H / MAPCHIP_HEIGHT;

	for (int i = 0; i < MAP_SIZE_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_SIZE_WIDTH; j++)
		{
			maped.chip_id = g_MapChipFirst[i][j];

			maped.chip_pos_x = (float)(maped.chip_id % maped.width_chip_num) * MAPCHIP_WIDTH;
			maped.chip_pos_y = (float)(maped.chip_id / maped.height_chip_num) * MAPCHIP_HEIGHT;
			if (maped.chip_id == 0)
			{
				continue;
			}

			maped.position_x = MAPCHIP_WIDTH * j;
			maped.position_y = MAPCHIP_HEIGHT * i;
		}
	}

}

void Map::DrawMap()
{
	int i, j;
	for (j = 0; j < MAP_SIZE_HEIGHT; j++)
	{
		for (i = 0; i < MAP_SIZE_WIDTH; i++)
		{
			//1はブロックを表しているから1のところだけ描画
			if (g_MapChipFirst[j][i] == 1)
			{
					DrawGraph(i * MAPCHIP_HEIGHT, j * MAPCHIP_WIDTH, maped.Block, true);
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
