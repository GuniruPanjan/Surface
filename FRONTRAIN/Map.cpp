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
	MapSeparator(637),
	maped(),
	MapFiveX(0),
	MapFourX(0),
	MapSixX(0),
	MapReset(1277),
	FiveCount(0),
	FourCount(0),
	SixCount(0)
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
	//�}�b�v���[�ɂ�����
	if (MapSeparator + ScrollX <= 0)
	{
		if (MapReset + ScrollX <= 0)
		{
			if (FiveCount > 0)
			{
				FiveMasu = -1;
				FiveCount = 0;
			}
			if (FourCount > 0)
			{
				FourMasu = -1;
				FourCount = 0;
			}
			if (SixCount > 0)
			{
				SixMasu = -1;
				SixCount = 0;
			}
			MapReset += 640;
		}

		MapSelection = false;

		MapSeparator += 640;
		
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

			//MapFive��X
			MapFiveX = j * MAPCHIP_WIDTH + ScrollX + MapDistanceFive;
			//MapFour��X
			MapFourX = j * MAPCHIP_WIDTH + ScrollX + MapDistanceFour;
			//MapSix��X
			MapSixX = j * MAPCHIP_WIDTH + ScrollX + MapDistanceSix;

			//���̓����_���z�u�̃}�b�v�`��
			//FiveMasu��0�������ꍇ
			if (FiveMasu == 0)
			{
				

				if (g_MapChip_1[i][j] == 1)
				{
					DrawGraph(MapFiveX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					//�����蔻��̍X�V
					m_colRect.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX + MapDistanceFive, i * MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH, MAPCHIP_HEIGHT);

					//�}�b�v�`�b�v�̓����蔻��̕\��
					m_colRect.Draw(GetColor(0, 255, 255), false);

					DrawFormatString(300, 100, GetColor(255, 255, 255), "Five0���������ꂽ");
				}
				Five = true;
				
				if (MapSelection == false)
				{

					Four = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Four��false���ꂽ");

					FiveCount = 1;

				}
				MapSelection = true;
				
			}
			
			//FiveMasu��1�������ꍇ
			if (FiveMasu == 1)
			{
				if (g_MapChip_4[i][j] == 1)
				{
					DrawGraph(MapFiveX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					//�����蔻��̍X�V
					m_colRect.SetCenter(j * MAPCHIP_WIDTH + 10 + ScrollX + MapDistanceFive, i * MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH, MAPCHIP_HEIGHT);

					//�}�b�v�`�b�v�̓����蔻��̕\��
					m_colRect.Draw(GetColor(0, 255, 255), false);

					DrawFormatString(300, 120, GetColor(255, 255, 255), "Five1���������ꂽ");
				}
				Five = true;

				if (MapSelection == false)
				{

					Four = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Four��false���ꂽ");

					FiveCount = 1;

				}
				MapSelection = true;
				
			}
			//FiveMasu��2�������ꍇ
			if (FiveMasu == 2)
			{
				if (g_MapChip_8[i][j] == 1)
				{
					DrawGraph(MapFiveX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					//�����蔻��̍X�V
					m_colRect.SetCenter(j* MAPCHIP_WIDTH + 10 + ScrollX + MapDistanceFive, i* MAPCHIP_HEIGHT + 10, MAPCHIP_WIDTH, MAPCHIP_HEIGHT);

					//�}�b�v�`�b�v�̓����蔻��̕\��
					m_colRect.Draw(GetColor(0, 255, 255), false);

					DrawFormatString(300, 140, GetColor(255, 255, 255), "Five2���������ꂽ");
				}
				Five = true;

				if (MapSelection == false)
				{

					Six = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Six��false���ꂽ");

					FiveCount = 1;

				}
				MapSelection = true;
				
			}


			//FourMasu��0�������ꍇ
			if (FourMasu == 0)
			{
				if (g_MapChip_2[i][j] == 1)
				{
					DrawGraph(MapFourX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					DrawFormatString(300, 160, GetColor(255, 255, 255), "Four0���������ꂽ");
				}
				Four = true;

				if (MapSelection == false)
				{

					Six = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Six��false���ꂽ");

					FourCount = 1;

				}
				MapSelection = true;
				
			}
			//FourMasu���P�������ꍇ
			if (FourMasu == 1)
			{
				if (g_MapChip_5[i][j] == 1)
				{
					DrawGraph(MapFourX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					DrawFormatString(300, 180, GetColor(255, 255, 255), "Four1���������ꂽ");
				}
				Four = true;

				if (MapSelection == false)
				{

					Six = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Six��false���ꂽ");

					FourCount = 1;


				}
				MapSelection = true;
				
			}


			//SixMasu��0�������ꍇ
			if (SixMasu == 0)
			{
				if (g_MapChip_3[i][j] == 1)
				{
					DrawGraph(MapSixX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					DrawFormatString(300, 200, GetColor(255, 255, 255), "Six0���������ꂽ");
				}
				Six = true;

				if (MapSelection == false)
				{

					Five = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Five��false���ꂽ");

					SixCount = 1;

				}
				MapSelection = true;
				
			}
			//SixMasu��1�������ꍇ
			if (SixMasu == 1)
			{
				if (g_MapChip_6[i][j] == 1)
				{
					DrawGraph(MapSixX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					DrawFormatString(300, 220, GetColor(255, 255, 255), "Six1���������ꂽ");
				}
				Six = true;

				if (MapSelection == false)
				{

					Four = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Four��false���ꂽ");

					SixCount = 1;


				}
				MapSelection = true;
				
			}
			//SixMasu��2�������ꍇ
			if (SixMasu == 2)
			{
				if (g_MapChip_9[i][j] == 1)
				{
					DrawGraph(MapSixX, i * MAPCHIP_HEIGHT + ScrollY, maped.Block, TRUE);

					DrawFormatString(300, 240, GetColor(255, 255, 255), "Six2���������ꂽ");
				}
				Six = true;

				if (MapSelection == false)
				{

					Five = false;

					DrawFormatString(100, 100, GetColor(255, 255, 255), "Five��false���ꂽ");

					SixCount = 1;


				}
				MapSelection = true;
				
			}
			
		}
	}

	//�}�b�v�̒[�\��
	DrawCircle(MapSeparator + ScrollX, 100, 5, GetColor(0, 0, 0), true);
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
