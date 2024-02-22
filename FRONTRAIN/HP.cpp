#include "HP.h"
#include "Player.h"

void HP::FinalizeHP()
{
	for (int i = 0; i < 11; i++)
	{
		DeleteGraph(HPberGraph[i]);
	}

	for (int i = 0; i < 13; i++)
	{
		DeleteGraph(MagazineGraph[i]);
	}

	for (int i = 0; i < 21; i++)
	{
		DeleteGraph(ReloadGraph[i]);
	}

	DeleteGraph(Reload);

	DeleteGraph(Botton);

	DeleteSoundMem(PointHPChange);
	DeleteSoundMem(PointAttackChange);
}

void HP::PlayerHPInit()
{

	LoadDivGraph("date/HPber.png", 11, 11, 1, 50, 25, HPberGraph);

	Botton = LoadGraph("date/�{�^��.png");

	LoadDivGraph("date/�e�q.png", 13, 7, 2, 40, 60, MagazineGraph);

	LoadDivGraph("date/ReloadGraph.png", 21, 7, 3, 20, 60, ReloadGraph);

	Reload = LoadGraph("date/Reload.png");

	GreenColor = GetColor(0, 255, 0);

	RedColor = GetColor(255, 0, 0);

	YelloColor = GetColor(255, 255, 0);

	HPColor = 0;

	AttackColor = 0;

	Blinking = 0;

	HPCount = 0;

	b = 255;

	b2 = 255;

	AttackShop = 0;
	AttackCount = 1;

	FirstBuy = 2500;
	SecondBuy = 5000;
	ThirdBuy = 8000;

	HPBuy = 3000;

	PointHPChange = LoadSoundMem("SE/�񕜖��@3.mp3");
	PointAttackChange = LoadSoundMem("SE/se_powerup.mp3");

	PointHPChangeUse = PointHPChange;
	PointAttackChangeUse = PointAttackChange;

	PointHP = false;
	PointAttack = false;

	AttackClick = false;

	UIMouseDecisionX = 10;
	UIMouseDecisionY = 10;

	UIWhiteColor = GetColor(255, 255, 255);
	UIBlackColor = GetColor(0, 0, 0);
}

void HP::PlayerHP(Player& player, Background& back, Save& save, Point& point, Shot shot[])
{
	GetMousePoint(&MouseX, &MouseY);

	m_Mouse.SetCenter(static_cast<float>(MouseX), static_cast<float>(MouseY + 5), static_cast<float>(UIMouseDecisionX), static_cast<float>(UIMouseDecisionY));

	//�U���͂��������邽�тɕK�v�ȃ|�C���g�𑝂₵�Ă���
	if (AttackCount == 1)
	{
		AttackShop = FirstBuy;
	}
	if (AttackCount == 2)
	{
		AttackShop = SecondBuy;
	}
	if (AttackCount == 3)
	{
		AttackShop = ThirdBuy;
	}


	//�v���C���[�������
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
	DrawBox(10, 10, 200, 200, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//HP��
	DrawString(15, 20, "HP�S��", GreenColor, true);
	DrawFormatString(110, 20, UIWhiteColor, "%dpt", HPBuy);

	if (point.PointPoint >= HPBuy && player.HP < 10)
	{
		//�����蔻��擾
		m_HP.SetCenter(90, 75, 120, 30);

		if (m_HP.IsCollision(m_Mouse) == false)
		{
			b = 255;
			HPColor = GreenColor;
		}
		else if (m_HP.IsCollision(m_Mouse) == true)
		{
			b = 120;
			HPColor = YelloColor;
			//�{�^���ɓ������Ă���Ƃ��ɒe�����ĂȂ��悤�ɂ���
			player.PlayerShotFlag = true;

			//���N���b�N���������Ƃ�
			if (GetMouseInput() & MOUSE_INPUT_LEFT)
			{
				PlaySoundMem(PointHPChangeUse, DX_PLAYTYPE_BACK, TRUE);

				PointHP = true;

				player.HP = 10;

				point.PointShop -= HPBuy;
			}
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
		DrawGraph(30, 60, Botton, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawString(70, 63, "��", HPColor, true);
	}
	

	DrawString(15, 100, "�U����UP", RedColor, true);
	DrawFormatString(110, 100, UIWhiteColor, "%dpt", AttackShop);

	if (AttackCount <= 3)
	{
		if (point.PointPoint >= AttackShop)
		{
			//�����蔻��擾
			m_Attack.SetCenter(90, 155, 120, 30);

			if (m_Attack.IsCollision(m_Mouse) == false)
			{
				b2 = 255;
				AttackColor = RedColor;
			}
			else if (m_Attack.IsCollision(m_Mouse) == true)
			{
				b2 = 120;
				AttackColor = YelloColor;

				//�{�^���ɓ������Ă���Ƃ��ɒe�����ĂȂ��悤�ɂ���
				player.PlayerShotFlag = true;

				//�A���ŃN���b�N�ł��Ȃ��悤�ɂ��邽��
				if (AttackClick == false)
				{
					//���N���b�N���������Ƃ�
					if (GetMouseInput() & MOUSE_INPUT_LEFT)
					{
						for (int i = 0; i < SHOT; i++)
						{
							PlaySoundMem(PointAttackChangeUse, DX_PLAYTYPE_BACK, TRUE);

							shot[i].Damage += 2;

						}

						PointAttack = true;

						AttackCount += 1;

						point.PointShop -= AttackShop;

					}

					AttackClick = true;
				}
				
			}
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, b2);
			DrawGraph(30, 140, Botton, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			DrawString(45, 143, "�U����UP", AttackColor, true);
		}
	}
	else if (AttackCount >= 4)
	{
		SetFontSize(18);
		DrawString(10, 143, "����ȏ㋭���ł��Ȃ�", GetColor(255, 255, 255), true);
		SetFontSize(20);
	}
	
	
	//�w�i��ʂ�Ԃ�����
	if (player.HP == 10)
	{
		back.Red = 0;
	}
	if (player.HP == 9)
	{
		back.Red = 10;
	}
	if (player.HP == 8)
	{
		back.Red = 20;
	}
	if (player.HP == 7)
	{
		back.Red = 30;
	}
	if (player.HP == 6)
	{
		back.Red = 40;
	}
	if (player.HP == 5)
	{
		back.Red = 50;
	}
	if (player.HP == 4)
	{
		back.Red = 60;
	}
	if (player.HP == 3)
	{
		back.Red = 70;
	}
	if (player.HP == 2)
	{
		back.Red = 80;
	}
	if (player.HP == 1)
	{
		back.Red = 90;
	}
	if (player.HP <= 0)
	{
		back.Red = 100;
		
	}

	//�v���C���[�̐^��ɕ\�������
	SetFontSize(15);
	DrawFormatString(static_cast<int>(player.PlayerX - 30), static_cast<int>(player.PlayerY - 50), UIWhiteColor, "%s", save.String);
	DrawFormatString(310, 410, UIWhiteColor, "%s", save.String);
	DrawGraph(310, 430, HPberGraph[player.HP], true);

	SetFontSize(20);
	//��ʂ̍��[�ɕ`��
	DrawGraph(30, 410, MagazineGraph[player.Bullet], true);
	DrawFormatString(38, 432, UIBlackColor, "%d", player.Bullet);
	DrawFormatString(36, 430, UIWhiteColor, "%d", player.Bullet);

	//Reload�^�C����`�悷��
	DrawGraph(70, 410, ReloadGraph[player.BulletTime / 2], true);

	//�v���C���[�̒e���؂ꂽ��`�悷��
	if (player.Bullet == 0)
	{
		Blinking++;

		if (Blinking >= 5)
		{
			DrawGraph(25, 430, Reload, true);

			if (Blinking >= 20)
			{
				Blinking = 0;
			}
		}

		
	}

}
