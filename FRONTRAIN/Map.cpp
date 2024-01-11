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
	maped.Block = LoadGraph("date/�u���b�N.png");

	//�`�悷��}�b�v�`�b�v�̐����Z�b�g
	DrawMapChipNumX = STAGE_WIDTH / MAPCHIP_WIDTH;
	DrawMapChipNumY = STAGE_HEIGHT / MAPCHIP_HEIGHT;

	//��ʍ���ɕ`�悷��}�b�v���W���Z�b�g
	MapDrawPointX = player.PlayerX - (DrawMapChipNumX / 2 - 1);
	MapDrawPointY = player.PlayerY - (DrawMapChipNumY / 2 - 1);

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
				m_colRect.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX,i * MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH,MAPCHIP_HEIGHT);

				//�}�b�v�`�b�v�̓����蔻��̕\��
				m_colRect.Draw(GetColor(255, 255, 255), false);
				

				//shot�̓����蔻��false
				if (m_colRect.IsCollision(shot.m_colRect) == false)
				{
					//shot���ǂɓ������ĂȂ���
				}
				else if (m_colRect.IsCollision(shot.m_colRect) == true)
				{
					//shot���ǂɓ����������e�̑��݂�����
					shot.Flag = 0;
				}

				if (m_colRect.IsCollision(player.m_colRect) == true)
				{
					//�u���b�N�ɓ������Ă�����ǂ����
					player.PlayerY -= 0.15f;
					//�n�ʂɐG���Əd�͂�0�ɂȂ�
					//player.Gravity = 0;
				}

				for (int g = 0; g < ENEMY_NOW; g++)
				{
					if (m_colRect.IsCollision(Wenemy[g].m_colRect) == true)
					{
						//�u���b�N�ɓ������Ă�����ǂ����
						Wenemy[g].WalkEnemyY -= 0.04f;
					}
				}
				
			}
			//�}�b�v���[�ɓ��B�����Ƃ�
			if (g_MapChipFirst[i][j] == 2)
			{
				//�����蔻��̍X�V
				m_colBlockRect2.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX, i * MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH, MAPCHIP_HEIGHT);

				//�}�b�v�`�b�v�̓����蔻��̕\��
				m_colBlockRect2.Draw(GetColor(0, 255, 255), false);

				if (m_colBlockRect2.IsCollision(player.m_colRect) == true)
				{
					//�v���C���[�𗎂Ƃ�
					player.PlayerY += 0.1f;
				}

				for (int g = 0; g < ENEMY_NOW; g++)
				{
					if (m_colBlockRect2.IsCollision(Wenemy[g].m_colRect) == true)
					{
						//�G�l�~�[�𗎂Ƃ�
						Wenemy[g].WalkEnemyY += 0.05f;
						DrawString(200, 200, "�~�肽", GetColor(255, 255, 255));
					}
				}
			}

			//���̓����_���z�u�̃}�b�v�`��
			//FiveMasu��0�������ꍇ
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
			
			//FiveMasu��1�������ꍇ
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
			//FiveMasu��2�������ꍇ
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


			//FourMasu��0�������ꍇ
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
			//FourMasu���P�������ꍇ
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


			//SixMasu��0�������ꍇ
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
			//SixMasu��1�������ꍇ
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
			//SixMasu��2�������ꍇ
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
