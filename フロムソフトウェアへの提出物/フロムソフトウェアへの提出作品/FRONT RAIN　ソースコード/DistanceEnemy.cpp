#include "DistanceEnemy.h"
#include "DxLib.h"
#include<cmath>
#include<math.h>

DistanceEnemy::DistanceEnemy()
{
}

DistanceEnemy::~DistanceEnemy()
{
}

void DistanceEnemy::FinalizeDistanceEnemy(DistanceEnemyStruct& enemy)
{
	for (int i = 0; i < 14; i++)
	{
		DeleteGraph(enemy.Handle[i]);
	}

	DeleteGraph(enemy.DistanceEnemyGraph);

	DeleteSoundMem(enemy.SEDistanceEnemy);

	DeleteSoundMem(enemy.SEDistanceDead);

	DeleteSoundMem(enemy.SEDistanceDamage);
}

void DistanceEnemy::FinalizeDistanceEnemyShot(EnemyShot shot[])
{
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		DeleteGraph(shot[i].Graph);

		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(shot[i].ShotHitGraphLeft[j]);

			DeleteGraph(shot[i].ShotHitGraphRight[j]);

			DeleteGraph(shot[i].ShotSparkGraphLeft[j]);

			DeleteGraph(shot[i].ShotSparkGraphRight[j]);
		}

		DeleteSoundMem(shot[i].SEDistanceShot);
	}
}

void DistanceEnemy::Init(DistanceEnemyStruct& enemy, DistanceEnemy& Denemy, EnemyLoadDate& date)
{
	Denemy.Attack = 2;
	Denemy.HP = 5;

	enemy.DistanceEnemySpeed = 0.04f;

	enemy.DistanceEnemyX = -30.0f;
	enemy.DistanceEnemyY = -30.0f;
	enemy.DistanceEnemyDeadY = -30.0f;

	enemy.DistanceEnemyDead = false;

	enemy.DistanceShotDead = false;

	enemy.DistanceEnemyflag = false;

	Denemy.DistanceEnemyAppearance = true;

	Denemy.T = 0;

	Denemy.TUP = 15;

	Denemy.TUP2 = 50;

	Denemy.TUP3 = 96;

	Denemy.TUP4 = 150;

	enemy.Time = 0;

	enemy.ShotEnemy = 0;
	enemy.ShotDistance = 1;

	enemy.EnemyShotFlag = true;

	enemy.m_DeadAnimFrame;

	enemy.DeadPoint = date.DistancePoint;
	enemy.DeadPointSE = date.LoadSEPoint;

	enemy.DistanceShotDeadPoint = false;
	enemy.DistanceShotDeadSE = false;

	enemy.DistanceEnemyGraph = date.DistanceEnemyGraph;

	LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, enemy.Handle);

	enemy.AnimCount = 0;

	enemy.AnimTime = 0;

	enemy.SEDistanceEnemy = date.DistanceEnmeySound;

	enemy.SEDistanceDead = date.DistanceEnemyDeadSound;

	enemy.SEDistanceDamage = date.DistanceEnemyDamageSound;

	enemy.SE1 = false;
	enemy.SE2 = false;

	Denemy.HPUP = 8;
	Denemy.HPUP2 = 15;
}

void DistanceEnemy::EnemyShotInit(EnemyShot shot[], EnemyLoadDate& date)
{
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		shot[i].Flag = false;

		shot[i].ShotDamage = 2;

		shot[i].Graph = date.ShotDistance;

		shot[i].ShotHitTime = 0;

		shot[i].ShotHitLeftCount = 0;
		shot[i].ShotHitRightCount = 0;

		LoadDivGraph("date/�����Ԃ�(��)��.png", 2, 2, 1, 5, 5, shot[i].ShotHitGraphLeft);
		LoadDivGraph("date/�����Ԃ�(��)�E.png", 2, 2, 1, 5, 5, shot[i].ShotHitGraphRight);

		shot[i].ShotSparkTime = 0;

		shot[i].ShotSparkLeftCount = 0;
		shot[i].ShotSparkRightCount = 0;

		LoadDivGraph("date/�Ή�(��)��.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphLeft);
		LoadDivGraph("date/�Ή�(��)�E.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphRight);

		shot[i].SEDistanceShot = date.DistanceEnemyShotSound;
	}
}

void DistanceEnemy::Update(Player& player, Shot& shot, DistanceEnemyStruct enemy[], int DenemySize, float ScrollX, TimeCount* time, DistanceEnemy& Denemy,EnemyShot enemyshot[],int EnemyShotSize,Shield& shield)
{
	//���Ԃ����ƓG���o��
	//2���ȉ��������ꍇ
	if (time->EnemyTime < 120)
	{
		if (time->EnemyTime == 60 + (16 * Denemy.T))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.T++;

				for (int i = 0; i < DenemySize; i++)
				{

					if (enemy[i].DistanceEnemyflag == false)
					{

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	//2���������ꍇ�͏o�����A�b�v
	else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
	{
		if (time->EnemyTime == (8 * Denemy.TUP))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.TUP++;

				for (int i = 0; i < DenemySize; i++)
				{
					if (enemy[i].DistanceEnemyflag == false)
					{

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	//5�����Əo�����A�b�v
	else if (time->EnemyTime >= 300 && time->EnemyTime < 480)
	{
		if (time->EnemyTime == (6 * Denemy.TUP2))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.TUP2++;

				for (int i = 0; i < DenemySize; i++)
				{
					if (enemy[i].DistanceEnemyflag == false)
					{

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	//8�����Əo�����A�b�v
	else if (time->EnemyTime >= 480 && time->EnemyTime < 600)
	{
		if (time->EnemyTime == (5 * Denemy.TUP3))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.TUP3++;

				for (int i = 0; i < DenemySize; i++)
				{
					if (enemy[i].DistanceEnemyflag == false)
					{

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	//10�����Əo�����A�b�v
	else if (time->EnemyTime >= 600)
	{
		if (time->EnemyTime == (4 * Denemy.TUP4))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.TUP4++;

				for (int i = 0; i < DenemySize; i++)
				{
					if (enemy[i].DistanceEnemyflag == false)
					{

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	

	for (int i = 0; i < DenemySize; i++)
	{
		if (enemy[i].DistanceEnemyflag == true)
		{
			//�G�������Ă��鎞
			if (enemy[i].HP > 0)
			{
				//�G�̈ړ�����
				//�E����
				if (player.PlayerX - player.ScrollX + 200 < enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed + 0.02f;
				}
				//�E�ɓ�����
				else if (player.PlayerX - player.ScrollX + 200 > enemy[i].DistanceEnemyX && player.PlayerX - player.ScrollX < enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed;
				}
				//������
				if (player.PlayerX - player.ScrollX - 150 > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed + 0.02f;
				}
				//���ɓ�����
				else if (player.PlayerX - player.ScrollX - 150 < enemy[i].DistanceEnemyX && player.PlayerX - player.ScrollX > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed;
			
				}

				//�v���C���[���߂���������U���s�����s
				if (player.PlayerX - ScrollX + 320 >= enemy[i].DistanceEnemyX && player.PlayerX - ScrollX - 320 <= enemy[i].DistanceEnemyX)
				{
					enemy[i].Time++;
					if (enemy[i].Time >= 4000)
					{
						enemy[i].EnemyShotFlag = false;

						for (int j = 0; j < EnemyShotSize; j++)
						{
							enemyshot[j].Flag = false;
						}

						enemy[i].Time = 0;
					}
				}
				



				//�����蔻��̍X�V
				enemy[i].m_colRect.SetCenter(static_cast<float>(enemy[i].DistanceEnemyX + 10 + player.ScrollX), static_cast<float>(enemy[i].DistanceEnemyY + 10), static_cast<float>(enemy[i].DistanceEnemyWidth), static_cast<float>(enemy[i].DistanceEnemyHeight));

				//�v���C���[�̓����蔻��
				if (enemy[i].m_colRect.IsCollision(player.m_colRect) == false)
				{
					//�������ĂȂ�
				}
				//�������Ă���
				else if (enemy[i].m_colRect.IsCollision(player.m_colRect) == true)
				{
					//1�񂾂����s
					if (player.PlayerDamage == false)
					{
						player.HP -= Denemy.Attack;

						player.PlayerDamage = true;
					}

					//�G�����ł�����
					enemy[i].HP = -1;
				}

				if (shot.Flag == 1)
				{
					//�G�Ƃ̓����蔻��
					if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == false)
					{

					}
					else if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == true)
					{
						enemy[i].HP -= shot.Damage;
						
						PlaySoundMem(enemy[i].SEDistanceDamage, DX_PLAYTYPE_BACK, TRUE);

						//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
						shot.Flag = 0;

						if (enemy[i].HP <= 0)
						{
							enemy[i].DistanceShotDead = true;

							enemy[i].DistanceShotDeadPoint = true;
						}

					}

				}
			}
			
		}
	}
}

//�G�̍U���s��
void DistanceEnemy::EnemyShotUpdate(DistanceEnemyStruct enemy[], EnemyShot& shot, int enemySize, Player& player, float ScrollX, Shield& shield)
{
	
	for (int i = 0; i < enemySize; i++)
	{
		if (enemy[i].EnemyShotFlag == false)
		{
			if (shot.Flag == false)
			{
				PlaySoundMem(shot.SEDistanceShot, DX_PLAYTYPE_BACK, TRUE);

				shot.Flag = true;
				shot.X = enemy[i].DistanceEnemyX;
				shot.Y = enemy[i].DistanceEnemyY + enemy[i].DistanceEnemyHeight / 2;

				//�e�̈ړ����x��ݒ肷��
				double sb, sbx, sby, ax, ay, sx, sy;

				sx = shot.X;
				sy = shot.Y;

				//�W�I�̏ꏊ
				ax = player.PlayerX - ScrollX;
				ay = player.PlayerY;

				sbx = ax - sx;
				sby = ay - sy;

				sb = sqrt(sbx * sbx + sby * sby);

				//1�t���[��������5�h�b�g�œ���
				shot.PX = sbx / sb * 5;
				shot.PY = sby / sb * 5;

				//��e���o�����̂Œe���o�����[�v���甲����
				break;
			}
		}
		enemy[i].EnemyShotFlag = true;
	}

	if (shot.Flag == true)
	{

		//���Ƃ̐ڐG����
		if (shield.LeftFlag == true || shield.RightFlag == true)
		{
			//���Ƃ̓����蔻��
			if (shot.m_colRect.IsCollision(shield.m_colRect) == false)
			{
				//�������ĂȂ�

			}
			else if (shot.m_colRect.IsCollision(shield.m_colRect) == true)
			{

				//�ڐG�����e�̑��݂�����
				shot.Flag = false;
			}
		}


		//�v���C���[�Ƃ̓����蔻��
		if (shot.m_colRect.IsCollision(player.m_colRect) == false)
		{

		}
		else if (shot.m_colRect.IsCollision(player.m_colRect) == true)
		{
			//1�񂾂����s
			if (player.PlayerDamage == false)
			{
				player.HP -= shot.ShotDamage;

				player.PlayerDamage = true;
			}

			//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shot.Flag = false;
		}

	}
}

void DistanceEnemy::Draw(float ScrollX, DistanceEnemyStruct& enemy, Point& point, Player& player,int DownAnimGraph,Shot shot[], TimeCount* time)
{
	//�G�l�~�[�������Ă��鎞
	if (enemy.HP > 0)
	{
		if (enemy.SE1 == false)
		{
			PlaySoundMem(enemy.SEDistanceEnemy, DX_PLAYTYPE_BACK, TRUE);

			enemy.SE1 = true;
		}
		//�v���C���[���E�Ȃ�
		if (enemy.DistanceEnemyX + ScrollX > player.PlayerX)
		{
			DrawGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyY - 3), enemy.DistanceEnemyGraph, true);
		}
		//�v���C���[��荶�Ȃ�
		else if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
		{
			DrawTurnGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyY - 3), enemy.DistanceEnemyGraph, true);
		}

		for (int s = 0; s < SHOT; s++)
		{
			//�v���C���[�̒e������������
			if (enemy.m_colRect.IsCollision(shot[s].m_colRect) == true)
			{
				shot[s].ShotSparkTime++;

				//�v���C���[���G�l�~�[���E�ɂ���ꍇ
				if (enemy.DistanceEnemyX + ScrollX > player.PlayerX)
				{
					if (shot[s].ShotSparkTime >= 10)
					{
						shot[s].ShotSparkCountRight++;

						shot[s].ShotSparkTime = 0;
					}
					
				
					DrawGraph(static_cast<int>(shot[s].X), static_cast<int>(shot[s].Y), shot[s].ShotSparkGraphRight[shot[s].ShotSparkCountRight], true);

					if (shot[s].ShotSparkCountRight >= 3)
					{
						shot[s].X = -30;
					}
			
					
				}
				//�v���C���[���G�l�~�[�����ɂ���ꍇ
				if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
				{
					if (shot[s].ShotSparkTime >= 10)
					{
						shot[s].ShotSparkCountLeft++;

						shot[s].ShotAnimTime = 0;
					}

					
					DrawGraph(static_cast<int>(shot[s].X), static_cast<int>(shot[s].Y), shot[s].ShotSparkGraphLeft[shot[s].ShotSparkCountLeft], true);

					if (shot[s].ShotSparkCountLeft >= 3)
					{
						shot[s].X = -30;
					}

				}
			}
			shot[s].ShotSparkCountRight = 0;
			shot[s].ShotSparkCountLeft = 0;
			
		}

	}
	//�G�����񂾎�
	else if (enemy.HP <= 0)
	{	
		//���񂾎��̉��o
		if (enemy.SE2 == false)
		{
			PlaySoundMem(enemy.SEDistanceDead, DX_PLAYTYPE_BACK, TRUE);

			enemy.DistanceEnemyDeadY = enemy.DistanceEnemyY;

			enemy.SE2 = true;
		}

		if (enemy.DistanceEnemyDead == false)
		{
			enemy.AnimTime++;
			if (enemy.AnimTime >= 2)
			{
				enemy.AnimCount++;
				
				enemy.AnimTime = 0;
			}

			DrawGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyY - 3), enemy.Handle[enemy.AnimCount], true);

			//�|�C���g�l���\��
			if (enemy.DistanceShotDeadPoint == true)
			{
				//1�񂾂����s
				if (enemy.DistanceShotDeadSE == false)
				{
					PlaySoundMem(enemy.DeadPointSE, DX_PLAYTYPE_BACK, TRUE);

					enemy.DistanceShotDeadSE = true;
				}
			

				DrawGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyDeadY -= 1.0f), enemy.DeadPoint, true);
			}

			if (enemy.DistanceShotDead == true)
			{
				point.DenemyPoint += 120;

				enemy.DistanceShotDead = false;
			}

			enemy.DistanceEnemyflag = false;

			if (enemy.AnimCount == 13)
			{

				//2���ȉ��������ꍇ
				if (time->EnemyTime < 120)
				{
					enemy.HP = 5;
				}
				//2���������ꍇ�͑ϋv�̓A�b�v
				else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
				{
					enemy.HP = HPUP;
				}
				//5�����Ƒϋv�̓A�b�v
				else if (time->EnemyTime >= 300)
				{
					enemy.HP = HPUP2;
				}
				

				enemy.DistanceEnemyX = -30.0f;
				enemy.DistanceEnemyY = -30.0f;

				//���񂾏ꍇ�����蔻����I��点��
				enemy.m_colRect.SetCenter(0, 0, 0, 0);

				enemy.SE2 = false;

				enemy.DistanceEnemyDead = true;

				enemy.DistanceShotDeadPoint = false;

				enemy.DistanceShotDeadSE = false;

			}

			
		}
		

	}
	//���o���I�������A�j���[�V������߂�
	if (enemy.DistanceEnemyDead == true)
	{
		enemy.AnimCount = 0;
	}
}

void DistanceEnemy::DrawShot(EnemyShot shot[],int EnemyShotSize,int ScrollX,Player& player,Shield& shield)
{
	//�e�̈ړ�
	//���˂��Ă�e������
	for (int i = 0; i < EnemyShotSize; i++)
	{
		if (shot[i].Flag == true)
		{

			shot[i].X += shot[i].PX;
			shot[i].Y += shot[i].PY;

			DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].Graph, true);

			//�����蔻��̍X�V
			shot[i].m_colRect.SetCenter(static_cast<float>(shot[i].X + ScrollX), static_cast<float>(shot[i].Y), static_cast<float>(shot[i].Width), static_cast<float>(shot[i].Height));

			shot[i].m_colRect.Draw(GetColor(0, 0, 255), false);

			//��ʊO�ɍs�������������
			if (shot[i].Y <= -10)
			{
				shot[i].Flag = false;
			}


			//���ɓ���������
			//�����E�������ꍇ
			if (shield.RightFlag == true)
			{
				if (shot[i].m_colRect.IsCollision(shield.m_colRect) == true)
				{

					shot[i].ShotSparkTime++;
					if (shot[i].ShotSparkTime >= 10)
					{
						shot[i].ShotSparkRightCount++;

						shot[i].ShotSparkTime = 0;
					}

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotSparkGraphRight[shot[i].ShotSparkRightCount], true);

				}
			}
			//�������������ꍇ
			if (shield.LeftFlag == true)
			{
				if (shot[i].m_colRect.IsCollision(shield.m_colRect) == true)
				{
					shot[i].ShotSparkTime++;
					if (shot[i].ShotSparkTime >= 10)
					{
						shot[i].ShotSparkLeftCount++;

						shot[i].ShotSparkTime = 0;
					}

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotSparkGraphLeft[shot[i].ShotSparkLeftCount], true);

				}
			}

			shot[i].ShotSparkRightCount = 0;
			shot[i].ShotSparkLeftCount = 0;

			//�v���C���[�ɓ���������
			
			if (shot[i].m_colRect.IsCollision(player.m_colRect) == true)
			{
				//�v���C���[�����������ꍇ
				if (shot[i].X + ScrollX > player.PlayerX)
				{
					shot[i].ShotHitTime++;
					if (shot[i].ShotHitTime >= 10)
					{
						shot[i].ShotHitLeftCount++;

						shot[i].ShotHitTime = 0;
					}

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotHitGraphLeft[shot[i].ShotHitLeftCount], true);
				}
				//�v���C���[���E�������ꍇ
				if (shot[i].X + ScrollX < player.PlayerX)
				{
					shot[i].ShotHitTime++;
					if (shot[i].ShotHitTime >= 10)
					{
						shot[i].ShotHitRightCount++;

						shot[i].ShotHitTime = 0;
					}

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotHitGraphRight[shot[i].ShotHitRightCount], true);
				}

			}

			shot[i].ShotHitLeftCount = 0;
			shot[i].ShotHitRightCount = 0;

		}
		if (shot[i].Flag == false)
		{
			//�����蔻����I��点��
			shot[i].m_colRect.SetCenter(0, 0, 0, 0);
		}
	}
	
}
