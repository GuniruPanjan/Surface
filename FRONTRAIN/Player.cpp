#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"
#include "Map.h"
#include "GraphMode.h"
#include<math.h>



class Shot;
MapEd maped;
Map map;
GraphMode graph;

Player::Player():
	HP(100),
	Speed(2),
	playerGraph(-1),
	Aiming(-1),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
	PlayerX(640 / 12),
	PlayerY(480 - 108.1),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0),
	W(0),
	H(0),
	PlayerRight(false)
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

}

void Player::InitShot(Shot& shot, int shotGraph)
{
	shot.Graph = shotGraph;

	shot.Flag = false;

	GetGraphSize(shot.Graph, &shot.Width, &shot.Height);
}

void Player::Update()
{
	

	//���L�[���������Ƃ�
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= Speed;
		//���[�����ɂ����Ȃ�
		if (PlayerX < 8)
		{
			PlayerX = 8;
		}
	}
	//�E�L�[���������Ƃ�
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PlayerX += Speed;
		//�^�񒆂����ɍs���Ɖ�ʂ����Ă���
		if (PlayerX >= graph.GraphModeWIDTH / 2)
		{
			PlayerRight = true;
			PlayerX = graph.GraphModeWIDTH / 2;
		}
	}

	int Pw, Ph, PwM, PhM;
	float bby;
	Pw = PlayerX + 8; //�E��
	Ph = PlayerY + 8; //����
	PwM = PlayerX - 8; //����
	PhM = PlayerY - 8; //���

	if (map.GetChipParm(Pw, Ph) == (0, 1) || map.GetChipParm(PwM, PhM) == (0, 1))
	{
		PlayerY;
	}
	if (map.GetChipParm(Pw,Ph) == (0,1) || map.GetChipParm(PwM, PhM) == (0,1))
	{
		

		//�u���b�N�ɓ������Ă�����ǂ����
		PlayerY -= 20;
		
	}
	else if(map.GetChipParm(Pw,Ph) == (0,0))
	{
		//���Ƀu���b�N�����������牺�ֈړ�
		PlayerY += 20;
	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&MouseX, &MouseY);
	
}

void Player::ShotUpdate(Player& player,Shot shot[], int shotSize)
{
	//�}�E�X�L�[(���N���b�N)���������Ɣ���
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (player.PlayerShotFlag == false)
		{
			for (int i = 0; i < shotSize; i++)
			{
				if (shot[i].Flag == false)
				{
					shot[i].Flag = true;
					shot[i].X = player.PlayerX;
					shot[i].Y = player.PlayerY;

					//�e�̈ړ����x��ݒ肷��
					double sb, sbx, sby, ax, ay, sx, sy;

					sx = shot[i].X + shot[i].Width / 2;
					sy = shot[i].Y + shot[i].Height / 2;

					ax = player.MouseX + player.AimingW / 2;
					ay = player.MouseY + player.AimingH / 2;

					sbx = ax - sx;
					sby = ay - sy;

					sb = sqrt(sbx * sbx + sby * sby);

					//1�t���[��������10�h�b�g�œ���
					shot[i].AimX = sbx / sb * 10;
					shot[i].AimY = sby / sb * 10;

					//��e���o�����̂Œe���o�����[�v���甲����
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
	
}

void Player::Draw()
{

	
	playerGraph = DrawCircle(PlayerX, PlayerY, 8, GetColor(255, 255, 255), true);

	//�v���C���[�̑傫���𓾂�
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);
	
	Aiming = LoadGraph("date/�W��(��).png");

	//�Ə��̑傫���𓾂�
	GetGraphSize(Aiming, &AimingW, &AimingH);

	DrawGraph(MouseX, MouseY, Aiming, true);
}

void Player::DrawShot(Shot& shot)
{
	//�e�̈ړ�
	//���˂��Ă�e������
	if (shot.Flag)
	{
		shot.X += shot.AimX;
		shot.Y += shot.AimY;

		//��ʂ̊O�ɂ͂ݏo������t���O��߂�
		if (shot.X > 640 || shot.X < 0 || shot.Y > 480 || shot.Y < 0)
		{
			shot.Flag = false;
		}

		DrawGraph(shot.X, shot.Y, shot.Graph, true);
	}

}



	
