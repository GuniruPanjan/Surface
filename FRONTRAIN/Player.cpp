#include "Player.h"
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
	PlayerH(0),
	ShotGraph(0),
	W(0),
	H(0)
{
	//�e������
	memset(shot, 0, sizeof(shot));

	
}

Player::~Player()
{
}

void Player::Init()
{
	DrawGraph(PlayerX, PlayerY, playerGraph, true);

	//�v���C���[�̑傫���𓾂�
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);

	//�e�̕`��
	for (int i = 0; i < SHOT; i++)
	{
		if (shot[i].Flag)
		{
			DrawGraph(shot[i].X, shot[i].Y, shot[i].Graph, true);
		}
	}


	for (int i = 0; i < SHOT; i++)
	{
		W, H;
		//�e�摜�̃T�C�Y�擾
		GetGraphSize(ShotGraph, &W, &H);

		//�t���O��S��false�ɂ��Ă���
		//�O���t�B�b�N�n���h���Ɖ摜�̃T�C�Y����
		shot[i].Flag = false;
		shot[i].Graph = ShotGraph;
		shot[i].Width = W;
		shot[i].Height = H;
	}
	
	

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

	
}

void Player::ShotUpdate()
{
	//�}�E�X�L�[(���N���b�N)���������Ɣ���
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (PlayerShotFlag == false)
		{
			for (int i = 0; i < SHOT; i++)
			{
				if (shot[i].Flag == false)
				{
					shot[i].Flag = true;
					shot[i].X = PlayerX;
					shot[i].Y = PlayerY;
					break;
				}
			}
			PlayerShotFlag = true;
		}

		
	}
	else
	{
		PlayerShotFlag = false;
	}

	//�e���ړ������鏈��
	for (int i = 0; i < SHOT; i++)
	{
		//���˂��Ă�e����
		if (shot[i].Flag)
		{
			shot[i].X += 10;

			//��ʂ̊O�ɂ͂ݏo������t���O��߂�
			if (shot[i].X > 640)
			{
				shot[i].Flag = false;
			}
		}
	}
}

void Player::Draw()
{
	

	//�e�摜�ǂݍ���
	for (int i = 0; i < SHOT; i++)
	{
		ShotGraph = DrawCircle(shot[i].X, shot[i].Y, 2, GetColor(0, 255, 0), true);
	}

	playerGraph = DrawCircle(PlayerX, PlayerY, 5, GetColor(255, 255, 255), true);
	
}


	
