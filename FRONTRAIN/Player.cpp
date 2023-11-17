#include "Player.h"
#include "DxLib.h"
#include<math.h>

class Shot;

Player::Player():
	HP(100),
	Speed(2),
	playerGraph(0),
	Aiming(0),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
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

	//�Ə��̑傫���𓾂�
	GetGraphSize(Aiming, &AimingW, &AimingH);


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

	//�}�E�X�̍��W�擾
	GetMousePoint(&MouseX, &MouseY);
	
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

					//�e�̈ړ����x��ݒ肷��
					double sb, sbx, sby, ax, ay, sx, sy;

					sx = shot[i].X + shot[i].Width / 2;
					sy = shot[i].Y + shot[i].Height / 2;

					ax = MouseX + AimingW / 2;
					ay = MouseY + AimingH / 2;

					sbx = ax - sx;
					sby = ay - sy;

					sb = sqrt(sbx * sbx + sby * sby);

					//1�t���[��������10�h�b�g�œ���
					shot[i].AimX = sbx / sb * 10;
					shot[i].AimY = sby / sb * 10;

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
			shot[i].X += shot[i].AimX;
			shot[i].Y += shot[i].AimY;

			//��ʂ̊O�ɂ͂ݏo������t���O��߂�
			if (shot[i].X > 640 || shot[i].X < 0 || shot[i].Y > 480 || shot[i].Y < 0)
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
		ShotGraph = DrawCircle(shot[i].X, shot[i].Y, 2, GetColor(0, 0, 0), true);
	}

	playerGraph = DrawCircle(PlayerX, PlayerY, 8, GetColor(255, 255, 255), true);
	
	Aiming = LoadGraphScreen(MouseX, MouseY, "date/�W��(��).png", true);
}


	
