#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"
#include "GraphMode.h"
#include<math.h>


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
	DeadAnimCount(9),
	DamegeCount(0),
	Reload(false),
	SEReload(0),
	SEDamage(0),
	SEShotMem(0),
	SE(false),
	PlayerArm(0),
	PlayerArmFlag(false)
{
	//�e������
	memset(shot, 0, sizeof(shot));

	
}

Player::~Player()
{
}

void Player::FinalizePlayer(Player& player, Shot shot[],Shield& shield)
{
	DeleteGraph(player.Aiming);

	DeleteGraph(player.DeadAnim);

	for (int i = 0; i < 14; i++)
	{
		DeleteGraph(player.DeadGraph[i]);
	}

	for (int i = 0; i < 12; i++)
	{
		DeleteGraph(player.playerGraph[i]);
	}

	for (int i = 0; i < SHOT; i++)
	{
		DeleteGraph(shot[i].Graph);

		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(shot[i].ShotAnimGraphRight[j]);

			DeleteGraph(shot[i].ShotAnimGraphLeft[j]);

			DeleteGraph(shot[i].ShotSparkGraphRight[j]);

			DeleteGraph(shot[i].ShotSparkGraphLeft[j]);

			DeleteSoundMem(shot[i].SEShot);

			DeleteSoundMem(shot[i].SENotShot);
		}
	}
	DeleteSoundMem(player.SEReload);
	DeleteSoundMem(player.SEDamage);

	DeleteGraph(shield.ShieldGraph);
	DeleteGraph(player.PlayerArm);
}

void Player::Init(Shield& shield ,Player& player)
{
	player.BulletTime = 0;

	player.Aiming = LoadGraph("date/�W��.png");

	player.DeadAnim = LoadGraph("date/��.png");

	player.PlayerArm = LoadGraph("date/�r.png");
	player.PlayerArmFlag = false;

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
	player.DamegeCount = 0;
	player.Reload = false;

	player.DeadAnimCount = 9;
	player.DeadAnimTime = 0;
	player.ShotGraph = LoadGraph("date/�e�e.png");
	player.SEShotMem = LoadSoundMem("SE/���e������.mp3");
	player.SENotShotMem = LoadSoundMem("SE/���e�̒e�؂�.mp3");

	player.SE = false;

	LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, player.DeadGraph);

	LoadDivGraph("date/PlayerMove.png", 12, 6, 2, 20, 25, player.playerGraph);

	player.SEReload = LoadSoundMem("SE/����{�^��������31.mp3");
	player.SEDamage = LoadSoundMem("SE/�Ռ�.mp3");
	player.SEReloadCan = player.SEReload;

	shield.LeftFlag = false;
	shield.RightFlag = false;
	shield.ShieldGraph = LoadGraph("date/Shiled.png");
	shield.ShieldWidth = 3;
	shield.ShieldHeight = 30;
}

void Player::InitShot(Shot shot[],Player& player)
{
	for (int i = 0; i < SHOT; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			shot[i].ShotAnimGraphLeft[j] = 0;
			shot[i].ShotAnimGraphRight[j] = 0;
			shot[i].ShotSparkGraphLeft[j] = 0;
			shot[i].ShotSparkGraphRight[j] = 0;
		}

		shot[i].X = -50;
		shot[i].Y = -50;

		shot[i].Flag = false;

		shot[i].Damage = 3;

		shot[i].Graph = player.ShotGraph;

		shot[i].ShotAnimCountRight = 0;
		shot[i].ShotAnimCountLeft = 0;

		shot[i].ShotAnimTime = 0;

		LoadDivGraph("date/�����Ԃ�(��)�E.png", 2, 2, 1, 5, 5, shot[i].ShotAnimGraphRight);
		LoadDivGraph("date/�����Ԃ�(��)��.png", 2, 2, 1, 5, 5, shot[i].ShotAnimGraphLeft);

		shot[i].ShotSparkCountRight = 0;
		shot[i].ShotSparkCountLeft = 0;

		shot[i].ShotSparkTime = 0;

		LoadDivGraph("date/�Ή�(��)�E.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphRight);
		LoadDivGraph("date/�Ή�(��)��.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphLeft);

		shot[i].SEShot = player.SEShotMem;
		shot[i].SENotShot = player.SENotShotMem;
	}
	
}

void Player::Update(Player& player,Map& map,Shield& shield,Background& back)
{

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
		if (player.HP > 0)
		{

			if (Left == false)
			{
				//�W�����v���C���[���E�Ȃ�
				if (player.MouseX >= player.PlayerX)
				{
					player.RightAnimTime++;

					//�_���[�W����������
					if (player.Count == 0 || player.DamegeCount >= 10)
					{
						if (player.RightAnimTime >= 10)
						{
							player.RightAnimCount++;

							player.RightAnimTime = 0;
						}
					}
					
				}
				//�W�����v���C���[��荶�Ȃ�
				else if (player.MouseX < player.PlayerX)
				{
					player.LeftAnimTime++;

					//�_���[�W����������
					if (player.Count == 0 || player.DamegeCount >= 10)
					{
						if (player.LeftAnimTime >= 10)
						{
							player.LeftAnimCount--;

							player.LeftAnimTime = 0;
						}
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
		if (player.HP > 0)
		{
			Left = true;

			if (Right == false)
			{
				//�W�����v���C���[���E�Ȃ�
				if (player.MouseX >= player.PlayerX)
				{
					player.RightAnimTime++;

					//�_���[�W����������
					if (player.Count == 0 || player.DamegeCount >= 10)
					{
						if (player.RightAnimTime >= 10)
						{
							player.RightAnimCount++;

							player.RightAnimTime = 0;
						}
					}
				}
				//�W�����v���C���[��荶�Ȃ�
				else if (player.MouseX < player.PlayerX)
				{
					player.LeftAnimTime++;

					//�_���[�W����������
					if (player.Count == 0 || player.DamegeCount >= 10)
					{
						if (player.LeftAnimTime >= 10)
						{
							player.LeftAnimCount--;

							player.LeftAnimTime = 0;
						}
					}
				}

				player.PlayerX += player.Speed;

				//�^�񒆂����ɍs���Ɖ�ʂ����Ă���
				if (player.PlayerX >= graph.GraphModeWIDTH / 6)
				{
					player.PlayerRight = true;
					player.PlayerX = static_cast<float>(graph.GraphModeWIDTH / 6);
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
		//�V�[���h���\�������̓X�N���[���ʂ����Z���Ȃ�
		if (player.Right == false)
		{
			//�v���C���[���삩��X�N���[���ʂ��Z�o����
			player.ScrollX -= Speed;
			player.ScrollY = 0.0f;
		}
		
	}
	
	//�����蔻��̍X�V
	m_colRect.SetCenter(static_cast<float>(player.PlayerX), static_cast<float>(player.PlayerY - 1), static_cast<float>(player.PlayerWidth - 2), static_cast<float>(player.PlayerHeight));
	
	//�}�E�X�̍��W�擾
	GetMousePoint(&player.MouseX, &player.MouseY);

	if (player.PlayerDamage == true)
	{
		
		if (player.SE == false)
		{
			PlaySoundMem(player.SEDamage, DX_PLAYTYPE_BACK, TRUE);

			player.SE = true;
		}
		
		//��ʂ�h�炷
		if (player.Count > 1 && player.Count <= 100)
		{
			back.BackX = GetRand(10);

			back.BackY = GetRand(10);

			back.BackX = GetRand(-10);

			back.BackY = GetRand(-10);
		}
		if (player.Count > 100)
		{
			back.BackX = 0;

			back.BackY = 0;
		}

		player.Count++;

		player.DamegeCount++;

	}
	//4�t���[����
	if (player.Count >= 224)
	{
		player.SE = false;

		//�A�j���[�V������߂�
		player.LeftAnimCount = 10;
		player.RightAnimCount = 1;

		player.PlayerDamage = false;
		player.Count = 0;
	}
}


void Player::ShotUpdate(Player& player,Shot shot[], int shotSize)
{
	//�e�����^�����ƃ����[�h�ł��Ȃ�
	if (player.Bullet < 12)
	{
		//�E�N���b�N�Œe�������[�h
		if (GetMouseInput() & MOUSE_INPUT_RIGHT)
		{
			if (player.Reload == false)
			{
				PlaySoundMem(player.SEReloadCan, DX_PLAYTYPE_BACK, TRUE);

				player.Reload = true;
			}

		}
		if (player.Reload == true)
		{
			player.PlayerShotFlag = true;

			player.BulletTime++;
			if (player.BulletTime >= 40)
			{
				player.Bullet = 12;

				player.Reload = false;

				player.BulletTime = 0;
			}
		}
	}
	//�}�E�X�L�[(���N���b�N)���������Ɣ���
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		//�e�������Ă���ƌ��Ă�
		if (player.Bullet > 0)
		{
			

			if (player.PlayerShotFlag == false)
			{

				for (int i = 0; i < shotSize; i++)
				{
					PlaySoundMem(shot[i].SEShot, DX_PLAYTYPE_BACK, TRUE);

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
			//�e�؂�Ȃ特���o��
			for (int i = 0; i < shotSize; i++)
			{
				PlaySoundMem(shot[i].SENotShot, DX_PLAYTYPE_BACK, TRUE);
			}
		
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

	//�L�[��������ĂȂ��Ƃ�
	if (CheckHitKey(KEY_INPUT_LEFT) == false && CheckHitKey(KEY_INPUT_RIGHT) == false)
	{
		//�_���[�W������������_�ł�����
		if (player.Count == 0 || player.DamegeCount >= 10)
		{
			DrawGraph(static_cast<int>(player.PlayerX - 10), static_cast<int>(player.PlayerY - 15), player.playerGraph[0], true);

			player.DamegeCount = 0;
		}

	}
	//�L�[��������Ă�����
	//�_���[�W��H������Ƃ��_�ł�����
	else if (player.Count == 0 || player.DamegeCount >= 10)
	{
		//�v���C���[���}�E�X���E�Ȃ�
		if (player.MouseX >= player.PlayerX)
		{

			if (player.RightAnimCount == 6)player.RightAnimCount = 1;

			DrawGraph(static_cast<int>(player.PlayerX - 10), static_cast<int>(player.PlayerY - 15), player.playerGraph[player.RightAnimCount], true);

			player.PlayerArmFlag = false;
		}
		//�v���C���[���}�E�X�����Ȃ�
		if (player.MouseX < player.PlayerX)
		{
			if (player.LeftAnimCount == 6)player.LeftAnimCount = 10;

			DrawGraph(static_cast<int>(player.PlayerX - 10), static_cast<int>(player.PlayerY - 15), player.playerGraph[player.LeftAnimCount], true);

			player.PlayerArmFlag = true;

		}

		player.DamegeCount = 0;

	}

	//���ɏ����\����
	if (shield.LeftFlag == true)
	{
		DrawGraph(static_cast<int>(player.PlayerX - 12), static_cast<int>(player.PlayerY - 20), shield.ShieldGraph, true);
		//�����蔻��̍X�V
		shield.m_colRect.SetCenter(static_cast<float>(player.PlayerX - 13), static_cast<float>(player.PlayerY - 5), static_cast<float>(shield.ShieldWidth + 3), static_cast<float>(shield.ShieldHeight));

	}
	//�E�ɏ����\����
	if (shield.RightFlag == true)
	{

		DrawGraph(static_cast<int>(player.PlayerX + 10), static_cast<int>(player.PlayerY - 20), shield.ShieldGraph, true);
		//�����蔻��̍X�V
		shield.m_colRect.SetCenter(static_cast<float>(player.PlayerX + 12), static_cast<float>(player.PlayerY - 5), static_cast<float>(shield.ShieldWidth + 3), static_cast<float>(shield.ShieldHeight));

	}

	//�v���C���[�����S������
	if (player.HP <= 0)
	{
		//���񂾂Ƃ��̉��o
		player.DeadAnimTime++;
		if (player.DeadAnimTime >= 5)
		{
			player.DeadAnimCount++;

			player.DeadAnimTime = 0;
		}

		DrawGraph(static_cast<int>(player.PlayerX - 10), static_cast<int>(player.PlayerY - 15), player.DeadGraph[player.DeadAnimCount], true);


		for (int i = 0; i < 12; i++)
		{
			DeleteGraph(player.playerGraph[i]);
		}
		
		DeleteGraph(shield.ShieldGraph);

		player.PlayerShotFlag = true;

		player.Right = true;
		player.Left = true;


		if (player.DeadAnimCount >= 13)
		{
			DrawGraph(static_cast<int>(player.PlayerX - 10), static_cast<int>(player.PlayerY - 17), player.DeadAnim, true);
		}
		

	}

}

void Player::DrawShot(Shot& shot)
{
	//�e�̈ړ�
	//���˂��Ă�e������
	if (shot.Flag)
	{
		DrawGraph(static_cast<int>(shot.X), static_cast<int>(shot.Y), shot.Graph, true);

		shot.X += shot.AimX;
		shot.Y += shot.AimY;

		//�����蔻��̍X�V
		shot.m_colRect.SetCenter(static_cast<float>(shot.X), static_cast<float>(shot.Y), static_cast<float>(shot.Width), static_cast<float>(shot.Height));

		//��ʂ̊O�ɂ͂ݏo������t���O��߂�
		if (shot.X > 640 || shot.X < 0 || shot.Y > 480 || shot.Y < 0)
		{
			shot.Flag = false;
		}

	}

	
}



	
