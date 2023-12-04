#include "Map.h"
#include "Player.h"
#include "DxLib.h"

Player player;

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
	DrawMapGraph(0)
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
}

void Map::DrawMap(int ScrollX)
{
	

	//�`�悷��}�b�v�`�b�v�̐����Z�b�g
	DrawMapChipNumX = STAGE_WIDTH / MAPCHIP_WIDTH;
	DrawMapChipNumY = STAGE_HEIGHT / MAPCHIP_HEIGHT;

	//��ʍ���ɕ`�悷��}�b�v���W���Z�b�g
	MapDrawPointX = player.PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = player.PlayerY - (DrawMapChipNumY / 2 - 1);

	//for (j = 0; j < MAP_SIZE_HEIGHT; j++)
	//{
	//	for (i = 0; i < MAP_SIZE_WIDTH; i++)
	//	{
	//		DrawW = i * MAPCHIP_WIDTH;
	//		DrawH = j * MAPCHIP_HEIGHT;
	//		//1�̓u���b�N��\���Ă��邩��1�̂Ƃ��낾���`��
	//		if (g_MapChipFirst[j][i] == 1)
	//		{
	//			DrawMapGraph = DrawGraph(DrawW + ScrollX, DrawH + ScrollY, maped.Block, true);
	//		}
	//	}
	//}

	//�}�b�v��`��
	for (i = 0; i < DrawMapChipNumY; i++)
	{
		for (j = 0; j < DrawMapChipNumX; j++)
		{
			//��ʂ���͂ݏo���ʒu�Ȃ�`�悵�Ȃ�
			/*if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_SIZE_WIDTH || i + MapDrawPointY >= MAP_SIZE_HEIGHT) continue;*/

			//�}�b�v�f�[�^���P��������u���b�N��`�悷��
			if (g_MapChipFirst[i][j] == 1)
			{
				DrawGraph(j * MAPCHIP_WIDTH + ScrollX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

				//�����蔻��̍X�V
				m_colRect.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX,i * MAPCHIP_HEIGHT + 10 + ScrollY, MAPCHIP_WIDTH,MAPCHIP_HEIGHT);

				//�}�b�v�`�b�v�̓����蔻��̕\��
				m_colRect.Draw(GetColor(255, 255, 255), false);
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
