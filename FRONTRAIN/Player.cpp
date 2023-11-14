#include "Player.h"
#include "Shot.h"
#include "DxLib.h"

class Shot;

Player::Player():
	HP(100),
	Speed(2),
	playerGraph(0),
	PlayerX(640 / 2),
	PlayerY(480 / 2),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0)
{

}

Player::~Player()
{
}

void Player::Init()
{
	DrawGraph(PlayerX, PlayerY, playerGraph, true);

	//�v���C���[�̑傫���𓾂�
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);
}

void Player::Update()
{
	

	//���L�[���������Ƃ�
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= Speed;
	}
	//�E�L�[���������Ƃ�
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PlayerX += Speed;
	}

	//�e�̔��ˏ���
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		//�O�t���[���ŃV���b�g�{�^�������������ۑ�����Ă���ϐ���false��������e�𔭎�
		if (PlayerShotFlag == false)
		{
			//��ʏ�ɏo�ĂȂ��e�̐��𒲂ׂ�
			for (int i = 0; i < SHOT; i++)
			{
				//�e����ʏ�ɏo�ĂȂ��ꍇ�͒e���o��
				if (shot[i]->ShotFlag == false)
				{
					//�e�̈ʒu���Z�b�g
					shot[i].X = (PlayerW - shot[i].Wdit) + PlayerX;
					shot[i].Y = (PlayerH - shot[i].Hight) + PlayerY;

					//�e�͌����_�������đ��݂���
					shot[i].ShotFlag = true;

					//�e���o�����[�v���甲����
					break;
				}
			}
		}
		//�O�t���[���ŃV���b�g�{�^�������������ۑ�����Ă���ϐ���
		PlayerShotFlag = true;
	}
	else
	{
		//�V���b�g�{�^����������Ă��Ȃ�������false����
		PlayerShotFlag = false;
	}
}

void Player::Draw()
{
	playerGraph = DrawCircle(PlayerX , PlayerY, 3, GetColor(255, 255, 255), true);
}
