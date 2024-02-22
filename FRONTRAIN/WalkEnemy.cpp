#include "WalkEnemy.h"
#include "DxLib.h"
#include<cmath>


WalkEnemy::WalkEnemy():
	T(0),
	TUP(20),
	WalkEnemyAppearance(true),
	HPUP(10),
	HPUP2(18)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::FinalizeWalkEnemy(WalkEnemyStruct enemy[], int WenemySize,EnemyLoadDate& date)
{
	for (int i = 0; i < WenemySize; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			DeleteGraph(enemy[i].WalkEnemyGraph[j]);
		}
		for (int j = 0; j < 14; j++)
		{
			DeleteGraph(enemy[i].Handle[j]);
		}

		DeleteSoundMem(enemy[i].SEWalkEnemy);

		DeleteSoundMem(enemy[i].SEWalkEnemyDead1);

		DeleteSoundMem(enemy[i].SEWalkEnemyDead2);
	}
}

void WalkEnemy::Init(WalkEnemyStruct enemy[], WalkEnemy& Wenemy,int WenemySize,EnemyLoadDate& date)
{
	for (int i = 0; i < WenemySize; i++)
	{
		enemy[i].WalkEnemyX = -30.0f;
		enemy[i].WalkEnemyY = -30.0f;
		enemy[i].WalkEnemyDeadY = -30.0f;

		enemy[i].WalkEnemySpeed = 0.07f;

		enemy[i].WalkEnemyDead = false;

		enemy[i].WalkShotDead = false;

		enemy[i].WalkEnemyflag = false;

		enemy[i].AnimTime = 0;

		enemy[i].RightAnim = 11;

		enemy[i].LeftAnim = 0;

		LoadDivGraph("date/WalkEnemy.png", 12, 6, 2, 20, 25, enemy[i].WalkEnemyGraph);

		LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, enemy[i].Handle);

		enemy[i].AnimCount = 9;

		enemy[i].AnimTimeDead = 0;

		enemy[i].DeadPoint = date.WalkPoint;
		enemy[i].DeadPointSe = date.LoadSEPoint;

		enemy[i].WalkShotDeadPoint = false;
		enemy[i].WalkShotDeadSE = false;

		enemy[i].SEWalkEnemy = date.WalkEnemySound;

		enemy[i].SEWalkEnemyDead1 = date.WalkEnmeyDeadSound1;

		enemy[i].SEWalkEnemyDead2 = date.WalkEnmeyDeadSound2;

		enemy[i].SE1 = false;
		enemy[i].SE2 = false;
	}

	Wenemy.Attack = 2;

	Wenemy.HP = 6;

	Wenemy.WalkEnemyAppearance = true;

	Wenemy.T = 0;

	Wenemy.TUP = 20;

	Wenemy.TUP2 = 60;

	Wenemy.TUP3 = 120;

	Wenemy.TUP4 = 300;

	Wenemy.HPUP = 10;

	Wenemy.HPUP2 = 18;

}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemyStruct enemy[],int WenemySize, float ScrollX, TimeCount* time, WalkEnemy& Wenemy)
{
	//���Ԃ����ƓG���o��
	//2���ȉ��̏ꍇ
	if (time->EnemyTime < 120)
	{
		if (time->EnemyTime == 10 + (12 * Wenemy.T))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.T++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

						enemy[i].WalkEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].WalkEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].WalkEnemyX = 680.0f - ScrollX;
						}

						enemy[i].WalkEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}

				}
				Wenemy.WalkEnemyAppearance = false;
			}

		}
		else
		{
			Wenemy.WalkEnemyAppearance = true;
		}
	}
	//2���o�߂�����o�����A�b�v
	else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
	{

		if (time->EnemyTime == (6 * Wenemy.TUP))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.TUP++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

						enemy[i].WalkEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].WalkEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].WalkEnemyX = 680.0f - ScrollX;
						}

						enemy[i].WalkEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}

				}
				Wenemy.WalkEnemyAppearance = false;
			}

		}
		else
		{
			Wenemy.WalkEnemyAppearance = true;
		}
	}
	//5���o�߂�����o�����A�b�v
	else if (time->EnemyTime >= 300 && time->EnemyTime < 480)
	{

		if (time->EnemyTime == (5 * Wenemy.TUP2))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.TUP2++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

						enemy[i].WalkEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].WalkEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].WalkEnemyX = 680.0f - ScrollX;
						}

						enemy[i].WalkEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}

				}
				Wenemy.WalkEnemyAppearance = false;
			}

		}
		else
		{
			Wenemy.WalkEnemyAppearance = true;
		}
	}
	//8���o�߂�����o�����A�b�v
	else if (time->EnemyTime >= 480 && time->EnemyTime < 600)
	{

		if (time->EnemyTime == (4 * Wenemy.TUP3))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.TUP3++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

						enemy[i].WalkEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].WalkEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].WalkEnemyX = 680.0f - ScrollX;
						}

						enemy[i].WalkEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}

				}
				Wenemy.WalkEnemyAppearance = false;
			}

		}
		else
		{
			Wenemy.WalkEnemyAppearance = true;
		}
	}
	//10���o�߂�����o�����A�b�v
	else if (time->EnemyTime >= 600)
	{

		if (time->EnemyTime == (2 * Wenemy.TUP4))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.TUP4++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

						enemy[i].WalkEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].WalkEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].WalkEnemyX = 680.0f - ScrollX;
						}

						enemy[i].WalkEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
						break;
					}

				}
				Wenemy.WalkEnemyAppearance = false;
			}

		}
		else
		{
			Wenemy.WalkEnemyAppearance = true;
		}
	}



	for (int i = 0; i < WenemySize; i++)
	{
		if (enemy[i].WalkEnemyflag == true)
		{
			//�G�l�~�[�������Ă��鎞
			if (enemy[i].HP >= 0)
			{

				//�G�̈ړ�����
				if (player.PlayerX - player.ScrollX <= enemy[i].WalkEnemyX)
				{
					enemy[i].WalkEnemyX -= enemy[i].WalkEnemySpeed;
				}
				else if (player.PlayerX - player.ScrollX > enemy[i].WalkEnemyX)
				{
					enemy[i].WalkEnemyX += enemy[i].WalkEnemySpeed;
				}

				//�����蔻��̍X�V
				enemy[i].m_colRect.SetCenter(static_cast<float>(enemy[i].WalkEnemyX + 10 + player.ScrollX), static_cast<float>(enemy[i].WalkEnemyY + 10), static_cast<float>(enemy[i].WalkEnemyWidth - 5), static_cast<float>(enemy[i].WalkEnemyHeight));

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
						player.HP -= Wenemy.Attack;

						player.PlayerDamage = true;
					}

					//�G�l�~�[�����ł�����
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

						PlaySoundMem(enemy[i].SEWalkEnemy, DX_PLAYTYPE_BACK, TRUE);

						//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
						shot.Flag = 0;

						if (enemy[i].HP <= 0)
						{
							enemy[i].WalkShotDead = true;
							enemy[i].WalkShotDeadPoint = true;
						}
						
						
					}

				}

			}

		}
	}
	
}

void WalkEnemy::Draw(float ScrollX,WalkEnemyStruct enemy[], Point& point,int WenemySize,Player& player,Shot shot[], TimeCount* time)
{
	for (int i = 0; i < WenemySize; i++)
	{
		//�G�l�~�[�������Ă��鎞
		if (enemy[i].HP > 0)
		{


			//�v���C���[���G�l�~�[���E�ɂ���ꍇ
			if (enemy[i].WalkEnemyX + player.ScrollX > player.PlayerX)
			{
				enemy[i].AnimTime++;
				if (enemy[i].AnimTime >= 10)
				{
					enemy[i].RightAnim--;

					enemy[i].AnimTime = 0;
				}

				if (enemy[i].RightAnim == 6)enemy[i].RightAnim = 10;

				DrawGraph(static_cast<int>(enemy[i].WalkEnemyX + ScrollX), static_cast<int>(enemy[i].WalkEnemyY - 5), enemy[i].WalkEnemyGraph[enemy[i].RightAnim], true);
			}
			//�v���C���[���G�l�~�[�����ɂ���ꍇ
			if (enemy[i].WalkEnemyX + player.ScrollX < player.PlayerX)
			{
				enemy[i].AnimTime++;
				if (enemy[i].AnimTime >= 10)
				{
					enemy[i].LeftAnim++;

					enemy[i].AnimTime = 0;
				}

				if (enemy[i].LeftAnim == 6)enemy[i].LeftAnim = 1;

				DrawGraph(static_cast<int>(enemy[i].WalkEnemyX + ScrollX), static_cast<int>(enemy[i].WalkEnemyY - 5), enemy[i].WalkEnemyGraph[enemy[i].LeftAnim], true);
			}

			for (int s = 0; s < SHOT; s++)
			{
				//�v���C���[�̒e������������
				if (enemy[i].m_colRect.IsCollision(shot[s].m_colRect) == true)
				{
					shot[s].ShotAnimTime++;

					//�v���C���[���G�l�~�[���E�ɂ���ꍇ
					if (enemy[i].WalkEnemyX + player.ScrollX > player.PlayerX)
					{
						if (shot[s].ShotAnimTime >= 10)
						{
							shot[s].ShotAnimCountRight++;

							shot[s].ShotAnimTime = 0;
						}

						DrawGraph(static_cast<int>(shot[s].X), static_cast<int>(shot[s].Y), shot[s].ShotAnimGraphRight[shot[s].ShotAnimCountRight], true);

					}
					//�v���C���[���G�l�~�[�����ɂ���ꍇ
					if (enemy[i].WalkEnemyX + player.ScrollX < player.PlayerX)
					{
						if (shot[s].ShotAnimTime >= 10)
						{
							shot[s].ShotAnimCountLeft++;

							shot[s].ShotAnimTime = 0;
						}

						DrawGraph(static_cast<int>(shot[s].X), static_cast<int>(shot[s].Y), shot[s].ShotAnimGraphLeft[shot[s].ShotAnimCountLeft], true);

					}


				}
				shot[s].ShotAnimCountRight = 0;
				shot[s].ShotAnimCountLeft = 0;
			}

			


			//�G�l�~�[�̓����蔻��̕\��
			//enemy[i].m_colRect.Draw(GetColor(255, 0, 0), false);
		}
		//�G�����񂾎�
		else if (enemy[i].HP <= 0)
		{
			
			//���񂾎��̉��o
			if (enemy[i].SE1 == false)
			{
				PlaySoundMem(enemy[i].SEWalkEnemyDead1, DX_PLAYTYPE_BACK, TRUE);

				enemy[i].WalkEnemyDeadY = enemy[i].WalkEnemyY;

				enemy[i].SE1 = true;
			}

			if (enemy[i].WalkEnemyDead == false)
			{
				enemy[i].AnimTimeDead++;
				if (enemy[i].AnimTimeDead >= 5)
				{
					enemy[i].AnimCount++;

					enemy[i].AnimTimeDead = 0;
				}

				DrawGraph(static_cast<int>(enemy[i].WalkEnemyX + ScrollX), static_cast<int>(enemy[i].WalkEnemyY - 5), enemy[i].Handle[enemy[i].AnimCount], true);

				if (enemy[i].SE2 == false)
				{
					PlaySoundMem(enemy[i].SEWalkEnemyDead2, DX_PLAYTYPE_BACK, TRUE);

					enemy[i].SE2 = true;
				}
				//�|�C���g�l���\��
				if (enemy[i].WalkShotDeadPoint == true)
				{
					//1�񂾂����s
					if (enemy[i].WalkShotDeadSE == false)
					{
						PlaySoundMem(enemy[i].DeadPointSe, DX_PLAYTYPE_BACK, TRUE);

						enemy[i].WalkShotDeadSE = true;
					}
					

					DrawGraph(static_cast<int>(enemy[i].WalkEnemyX + ScrollX), static_cast<int>(enemy[i].WalkEnemyDeadY -= 1.0f), enemy[i].DeadPoint, true);
				}

				enemy[i].m_colRect.SetCenter(0, 0, 0, 0);
				if (enemy[i].WalkShotDead == true)
				{
					point.WenemyPoint += 100;

					enemy[i].WalkShotDead = false;
				}

				enemy[i].WalkEnemyflag = false;

				if (enemy[i].AnimCount == 13)
				{
					//2���ȉ��̏ꍇ
					if (time->EnemyTime < 120)
					{
						enemy[i].HP = 6;
					}
					//2���o�߂�����̗̓A�b�v
					else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
					{
						enemy[i].HP = HPUP;
					}
					//5���o�߂�����̗̓A�b�v
					else if (time->EnemyTime >= 300)
					{
						enemy[i].HP = HPUP2;
					}
					

					enemy[i].WalkEnemyX = -30.0f;
					enemy[i].WalkEnemyY = -30.0f;

					enemy[i].SE1 = false;
					enemy[i].SE2 = false;

					enemy[i].WalkEnemyDead = true;

				    enemy[i].WalkShotDeadPoint = false;

					enemy[i].WalkShotDeadSE = false;
				}

				
			}

		}
		//���o���I�������A�j���[�V������߂�
		if (enemy[i].WalkEnemyDead == true)
		{
			enemy[i].AnimCount = 9;
		}

	}
	
	
	
}
