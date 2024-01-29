#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"
#include "GraphMode.h"
#include<math.h>



class Shot;
GraphMode graph;

Player::Player():
	HP(10),
	Speed(1.0f),
	Aiming(-1),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
	PlayerWidth(16),
	PlayerHeight(16),
	PlayerX(640.00f / 12.0f),
	PlayerY(480.00f - 100.0f),
	ScrollX(0.0f),
	ScrollY(0.0f),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0),
	Gravity(0),
	BulletTime(0),
	W(0),
	H(0),
	PlayerRight(false),
	PlayerDamage(false),
	Left(false),
	Right(false),
	PlayerRise(false),
	Count(0),
	RightAnimCount(0),
	LeftAnimCount(11),
	RightAnimTime(0),
	LeftAnimTime(0),
	DeadAnim(0),
	DeadAnimTime(0),
	DeadAnimCount(9)
{
	//�e������
	memset(shot, 0, sizeof(shot));

	
}

Player::~Player()
{
}

void Player::Init(Shield& shield,Shot shot[],Player& player)
{
	//DrawGraph(PlayerX, PlayerY, playerGraph, true);

	player.BulletTime = 0;

	player.Aiming = LoadGraph("date/�W��.png");

	player.DeadAnim = LoadGraph("date/��.png");

	player.HP = 10;
	player.Speed = 1.0f;
	player.AimingW = 0;
	player.AimingH = 0;
	player.MouseX = 0;
	player.MouseY = 0;
	player.PlayerWidth = 16;
	player.PlayerHeight = 16;
	player.PlayerX = 640.0f / 12.0f;
	player.PlayerY = 480.0f - 100.0f;
	player.ScrollX = 0.0f;
	player.ScrollY = 0.0f;
	player.PlayerShotFlag = false;
	player.PlayerW = 0;
	player.PlayerH = 0;
	player.W = 0;
	player.H = 0;
	player.Gravity = 0.3f;
	player.PlayerRight = false;
	player.PlayerDamage = false;
	player.Bullet = 12;
	player.BulletTime = 0;
	player.Left = false;
	player.Right = false;
	player.PlayerRise = false;
	player.Count = 0;
	player.RightAnimCount = 0;
	player.LeftAnimCount = 11;
	player.RightAnimTime = 0;
	player.LeftAnimTime = 0;

	player.DeadAnimCount = 9;
	player.DeadAnimTime = 0;

	LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, player.DeadGraph);

	LoadDivGraph("date/PlayerMove.png", 12, 6, 2, 20, 25, player.playerGraph);

	for (int i = 0; i < SHOT; i++)
	{
		shot[i].Graph = LoadGraph("date/�e�e��.png");
	}
	

	shield.LeftFlag = false;
	shield.RightFlag = false;
	shield.ShieldGraph = LoadGraph("date/Shiled.png");
	shield.ShieldWidth = 3;
	shield.ShieldHeight = 30;
}

void Player::InitShot(Shot shot[])
{
	for (int i = 0; i < SHOT; i++)
	{
		shot[i].Flag = false;

		shot[i].Damage = 3;
	}
	
}

void Player::Update(Player& player,Map& map,Shield& shield)
{
	//��ɏd�͂�^����
	/*player.PlayerY += player.Gravity;*/

	//������
	//���L�[����������
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		//�v���C���[�𓮂��Ȃ�����
		Left = true;
		Right = true;
		player.PlayerShotFlag = true;

		//���ɏ����\����
		if (player.PlayerX > player.MouseX)
		{
			shield.LeftFlag = true;

			shield.RightFlag = false;

			player.LeftAnimCount = 11;
		}
		//�E�ɏ����\����
		if (player.PlayerX < player.MouseX)
		{
			shield.RightFlag = true;

			shield.LeftFlag = false;

			player.RightAnimCount = 0;
		}
		
	}
	//���L�[�������ĂȂ��Ƃ�
	else if (CheckHitKey(KEY_INPUT_DOWN) == false)
	{
		//��������
		shield.LeftFlag = false;
		shield.RightFlag = false;

		Left = false;
		Right = false;
	}

	//���L�[���������Ƃ�
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		if (player.HP >= 0)
		{

			if (Left == false)
			{
				//�W�����v���C���[���E�Ȃ�
				if (player.MouseX >= player.PlayerX)
				{
					player.RightAnimTime++;
					if (player.RightAnimTime >= 10)
					{
						player.RightAnimCount++;

						player.RightAnimTime = 0;
					}
				}
				//�W�����v���C���[��荶�Ȃ�
				else if (player.MouseX < player.PlayerX)
				{
					player.LeftAnimTime++;
					if (player.LeftAnimTime >= 10)
					{
						player.LeftAnimCount--;

						player.LeftAnimTime = 0;
					}
				}

				player.PlayerX -= Speed;

				//���[�����ɂ����Ȃ�
				if (player.PlayerX < 8.0f)
				{
					player.PlayerX = 8.0f;
				}
			}
		}
		
	}
	//�E�L�[���������Ƃ�
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		if (player.HP >= 0)
		{
			Left = true;

			if (Right == false)
			{
				//�W�����v���C���[���E�Ȃ�
				if (player.MouseX >= player.PlayerX)
				{
					player.RightAnimTime++;
					if (player.RightAnimTime >= 10)
					{
						player.RightAnimCount++;

						player.RightAnimTime = 0;
					}
				}
				//�W�����v���C���[��荶�Ȃ�
				else if (player.MouseX < player.PlayerX)
				{
					player.LeftAnimTime++;
					if (player.LeftAnimTime >= 10)
					{
						player.LeftAnimCount--;

						player.LeftAnimTime = 0;
					}
				}

				player.PlayerX += player.Speed;

				//�^�񒆂����ɍs���Ɖ�ʂ����Ă���
				if (player.PlayerX >= graph.GraphModeWIDTH / 4)
				{
					player.PlayerRight = true;
					player.PlayerX = graph.GraphModeWIDTH / 4;
				}
			}
		}

	}
	//�ړ����ĂȂ��Ɖ�ʂ��~�܂�
	else if (player.PlayerX <= graph.GraphModeWIDTH / 2)
	{
		//��~���͉�ʂ̃X�N���[���͍s��Ȃ�
		player.PlayerRight = false;
		
	}
	

	if (player.PlayerRight == true)
	{
		//�v���C���[���삩��X�N���[���ʂ��Z�o����
		player.ScrollX -= Speed;
		player.ScrollY = 0.0f;
	}
	
	//�����蔻��̍X�V
	m_colRect.SetCenter(player.PlayerX, player.PlayerY - 1, player.PlayerWidth - 2, player.PlayerHeight);
	
	//�}�E�X�̍��W�擾
	GetMousePoint(&player.MouseX, &player.MouseY);

	if (player.PlayerDamage == true)
	{
		Count++;
	}
	//4�t���[����
	if (Count <= 224)
	{
		player.PlayerDamage = false;
		Count = 0;
	}
}


void Player::ShotUpdate(Player& player,Shot shot[], int shotSize)
{
	//�E�N���b�N�Œe�������[�h
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		player.PlayerShotFlag = true;

		player.BulletTime++;
		if (player.BulletTime >= 40)
		{
			player.Bullet = 12;

			player.BulletTime = 0;
		}

		
	}
	//�}�E�X�L�[(���N���b�N)���������Ɣ���
	else if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		//�e�������Ă���ƌ��Ă�
		if (player.Bullet > 0)
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

						player.Bullet--;

						//��e���o�����̂Œe���o�����[�v���甲����
						break;
					}
				}
				player.PlayerShotFlag = true;
			}
		}
		else if (player.Bullet <= 0)
		{
			DrawString(100, 100, "�e�؂�", GetColor(255, 255, 255));
		}
	}
	else
	{
		if (player.BulletTime <= 40)
		{
			player.PlayerShotFlag = false;
		}

	}

}

void Player::Draw(Shield& shield, Player& player)
{	

	//�v���C���[���}�E�X���E�Ȃ�
	if (player.MouseX >= player.PlayerX)
	{

		if (player.RightAnimCount == 6)player.RightAnimCount = 1;

		DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.playerGraph[player.RightAnimCount], true);
	}
	//�v���C���[���}�E�X�����Ȃ�
	if (player.MouseX < player.PlayerX)
	{
		if (player.LeftAnimCount == 6)player.LeftAnimCount = 10;

		DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.playerGraph[player.LeftAnimCount], true);

	}

	

	//�v���C���[�̓����蔻��̕\��
	//player.m_colRect.Draw(GetColor(0, 0, 255), false);
	//�W���̉摜�`��
	DrawGraph(MouseX - 10, MouseY - 10, Aiming, true);

	//���ɏ����\����
	if (shield.LeftFlag == true)
	{
		//shield.RightFlag = false;

		DrawGraph(player.PlayerX - 12, player.PlayerY - 20, shield.ShieldGraph, true);
		//�����蔻��̍X�V
		shield.m_colRect.SetCenter(player.PlayerX - 13, player.PlayerY - 5, shield.ShieldWidth + 3, shield.ShieldHeight);

		//shield.m_colRect.Draw(GetColor(0, 0, 255), false);
	}
	//�E�ɏ����\����
	if (shield.RightFlag == true)
	{
		//shield.LeftFlag = false;

		DrawGraph(player.PlayerX + 10, player.PlayerY - 20, shield.ShieldGraph, true);
		//�����蔻��̍X�V
		shield.m_colRect.SetCenter(player.PlayerX + 12, player.PlayerY - 5, shield.ShieldWidth + 3, shield.ShieldHeight);

		//shield.m_colRect.Draw(GetColor(0, 0, 255), false);

	}

	//�v���C���[�����S������
	if (player.HP <= 0)
	{
		player.DeadAnimTime++;
		if (player.DeadAnimTime >= 5)
		{
			player.DeadAnimCount++;

			player.DeadAnimTime = 0;
		}

		DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.DeadGraph[player.DeadAnimCount], true);


		for (int i = 0; i < 12; i++)
		{
			DeleteGraph(player.playerGraph[i]);
		}
		
		DeleteGraph(shield.ShieldGraph);

		player.PlayerShotFlag = true;

		if (player.DeadAnimCount >= 13)
		{
			DrawGraph(player.PlayerX - 10, player.PlayerY - 17, player.DeadAnim, true);
		}
		

	}

}

void Player::DrawShot(Shot& shot)
{
	//�e�̈ړ�
	//���˂��Ă�e������
	if (shot.Flag)
	{
		//shot.Graph = LoadGraph("date/�e�e.png");

		DrawGraph(shot.X, shot.Y, shot.Graph, true);

		shot.X += shot.AimX;
		shot.Y += shot.AimY;

		//�����蔻��̍X�V
		shot.m_colRect.SetCenter(shot.X, shot.Y, shot.Width, shot.Height);

		//��ʂ̊O�ɂ͂ݏo������t���O��߂�
		if (shot.X > 640 || shot.X < 0 || shot.Y > 480 || shot.Y < 0)
		{
			shot.Flag = false;
			//DeleteGraph(shot.Graph);
		}

	}

	
}



	
