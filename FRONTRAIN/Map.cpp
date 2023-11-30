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
			//1�̓u���b�N��\���Ă��邩��1�̂Ƃ��낾���`��
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
	//�����l�֕ϊ�
	x = (int)X / MAPCHIP_WIDTH;
	y = (int)Y / MAPCHIP_HEIGHT;

	//�}�b�v����͂ݏo�Ă�����0��Ԃ�
	//if (x >= MAP_SIZE_WIDTH || y >= MAP_SIZE_HEIGHT || x < 0 || y < 0) return 0;
	
	//�w��̍��W�ɊY������}�b�v�̏���Ԃ�
	return g_MapChipFirst[y][x];
}

int Map::GetChipUnder(float Y)
{
	int y;
	//�����l�֕ϊ�
	y = (int)Y / MAPCHIP_HEIGHT;

	//�}�b�v����͂ݏo�Ă�����0��Ԃ�
	//if ( y < 0) return 0;

	for (int i = 0; i < MAP_SIZE_WIDTH; i++)
	{
		return g_MapChipFirst[y][i];
	}
	
}
