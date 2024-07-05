#include "Map.h"
// �d�͉����x
#define GravitationalAcceleration 9.80665 / 2

/// <summary>
/// �V���h�E�}�b�v�쐬�ɕK�v�ȕϐ��錾
/// </summary>
namespace
{
	//�V���h�E�}�b�v�̍쐬�ɕK�v�ȕϐ�
    int SizeX = 8192;
	int SizeY = 8192;

	//�V���h�E�}�b�v�̕`�悷��͈͕ϐ�
	float minx = -1000.0f;
	float miny = -1.0f;
	float minz = -1000.0f;
	float maxx = 1000.0f;
	float maxy = -8000.0f;
	float maxz = 1000.0f;

	//�V���h�E�}�b�v�̃��C�g���W
	float Shadowlight = 0.5f;
}

Map::Map():
	ShadowMapHandle(0),
	NotMoveTime(0),
	SE(0),
	PlaySe(true),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	MapdistanceX(0.0f),
	MapdistanceY(0.0f),
	MapdistanceZ(0.0f),
	MapWidth(0.0f),
	MapHeight(0.0f),
	MapDepth(0.0f),
	Goal(false)
{
	
}

Map::~Map()
{
	//���������
	DeleteSoundMem(SE);

	//�V���h�E�}�b�v�̍폜
	DeleteShadowMap(ShadowMapHandle);

}

void Map::Init()
{
	//Map�̏������W���
	MapX = 0.0f;
	MapY = -478.0f;
	MapZ = 0.0f;

	//Map�̋K���I����
	MapdistanceX = 500.0f;
	MapdistanceY = 800.0f;
	MapdistanceZ = 500.0f;

	//Map�̓����蔻��̑傫��
	MapWidth = 450.0f;
	MapHeight = 220.0f;
	MapDepth = -450.0f;

	//SE�ǂݍ���
	SE = LoadSoundMem("BGM�ESE/���{�b�g������1.mp3");

	//�V���h�E�}�b�v�n���h���̍쐬
	ShadowMapHandle = MakeShadowMap(SizeX, SizeY);

	//�V���h�E�}�b�v���z�肷�郉�C�g�̕������Z�b�g
	SetShadowMapLightDirection(ShadowMapHandle, VGet(Shadowlight, -Shadowlight, Shadowlight));

	//�V���h�E�}�b�v�ɕ`�悷��͈͂�ݒ�
	SetShadowMapDrawArea(ShadowMapHandle, VGet(minx, miny, minz), VGet(maxx, maxy, maxz));

	//�}�b�v�̈ʒu��������
	obustructmap1->SetPos(VGet(MapX, MapY, MapZ));
	obustructmap2->SetPos(VGet(MapX, MapY - MapdistanceY, MapZ + MapdistanceZ));
	obustructmap3->SetPos(VGet(MapX, MapY - MapdistanceY * 2, MapZ));
	obustructmap4->SetPos(VGet(MapX - MapdistanceX, MapY - MapdistanceY * 3, MapZ));
	obustructmap5->SetPos(VGet(MapX - MapdistanceX, MapY - MapdistanceY * 4, MapZ - MapdistanceZ));
	obustructmap6->SetPos(VGet(MapX, MapY - MapdistanceY * 5, MapZ - MapdistanceZ));
	obustructmap7->SetPos(VGet(MapX, MapY - MapdistanceY * 6, MapZ));
	obustructmap8->SetPos(VGet(MapX + MapdistanceX, MapY - MapdistanceY * 7, MapZ));
	obustructmap9->SetPos(VGet(MapX, MapY - MapdistanceY * 8, MapZ));
	obustructmap10->SetPos(VGet(MapX, MapY - MapdistanceY * 9, MapZ - MapdistanceZ));
}

void Map::Update(Player& player, Enemy& enemy)
{
	

	//�}�b�v�̓����蔻����Ƃ�
	m_colrect.SetCenter(-230.0f, -220.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect2.SetCenter(-230.0f, -1023.0f, 720.0f, MapWidth, MapHeight, MapDepth);
	m_colrect3.SetCenter(-230.0f, -1822.5f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect4.SetCenter(-730.0f, -2623.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect5.SetCenter(-730.0f, -3423.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_colrect6.SetCenter(-230.0f, -4223.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_colrect7.SetCenter(-230.0f, -5023.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect8.SetCenter(270.0f, -5823.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect9.SetCenter(-230.0f, -6623.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect10.SetCenter(-230.0f, -7422.0f, -280.0f, MapWidth, MapHeight, MapDepth);

	//�G�l�~�[�̍��G�͈͂��쐬
	m_enemycol.SetCenter(-230.0f, -820.0f, 720.0f, MapWidth, MapHeight, MapDepth);
	m_enemycol2.SetCenter(-730.0f, -3223.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_enemycol3.SetCenter(-230.0f, -4823.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_enemycol4.SetCenter(-230.0f, -6423.0f, 220.0f, MapWidth, MapHeight, MapDepth);

	//�}�b�v����
	obustructmap1->Update();
	obustructmap2->Update();
	obustructmap3->Update();
	obustructmap4->Update();
	obustructmap5->Update();
	obustructmap6->Update();
	obustructmap7->Update();
	obustructmap8->Update();
	obustructmap9->Update();
	obustructmap10->Update();

	//�v���C���[�ɓ������Ă����
	if (m_colrect.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect2.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect3.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect4.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect5.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect6.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect7.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect8.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect9.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	//�S�[��
	else if (m_colrect10.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}

		Goal = true;
	}
	//�v���C���[�ɓ������ĂȂ���
	else if (m_colrect.IsCollision(player.m_colrect) == false || m_colrect2.IsCollision(player.m_colrect) == false)
	{
		player.PlayerGravity = player.Playerweight * static_cast<float>(GravitationalAcceleration);

		NotMoveTime++;

		if (NotMoveTime >= 50)
		{
			player.PlayerMoveFlag = false;
		}
		

		//SE����悤�ɂ���
		PlaySe = false;
	}
}

void Map::Draw(Player& player, Enemy& enemy)
{
	//�V���h�E�}�b�v�ւ̕`��̏���
	ShadowMap_DrawSetup(ShadowMapHandle);

	//�V���h�E�}�b�v�փL�����N�^�[���f���̕`��
	MV1DrawModel(player.PlayerGraph);

	//�V���h�E�}�b�v�ւ̕`����I��
	ShadowMap_DrawEnd();

	//�`��Ɏg�p����V���h�E�}�b�v��ݒ�
	SetUseShadowMap(1, ShadowMapHandle);

	//�}�b�v�`��
	obustructmap1->Draw();
	obustructmap2->Draw();
	obustructmap3->Draw();
	obustructmap4->Draw();
	obustructmap5->Draw();
	obustructmap6->Draw();
	obustructmap7->Draw();
	obustructmap8->Draw();
	obustructmap9->Draw();
	obustructmap10->Draw();

	//�`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
	SetUseShadowMap(1, -1);

	//�v���C���[���G�l�~�[�̍��G�͈͂ɓ����
	if (m_enemycol.IsCollision(player.m_colrect) == true)
	{
		enemy.enemy1->Enemyflag = true;
	}
	else if (m_enemycol.IsCollision(player.m_colrect) == false)
	{
		enemy.enemy1->Enemyflag = false;
	}
	if (m_enemycol2.IsCollision(player.m_colrect) == true)
	{
		enemy.enemy2->Enemyflag = true;
	}
	else if (m_enemycol2.IsCollision(player.m_colrect) == false)
	{
		enemy.enemy2->Enemyflag = false;
	}
	if (m_enemycol3.IsCollision(player.m_colrect) == true)
	{
		enemy.enemy3->Enemyflag = true;
	}
	else if (m_enemycol3.IsCollision(player.m_colrect) == false)
	{
		enemy.enemy3->Enemyflag = false;
	}
	if (m_enemycol4.IsCollision(player.m_colrect) == true)
	{
		enemy.enemy4->Enemyflag = true;
		enemy.enemy5->Enemyflag = true;

	}
	else if (m_enemycol4.IsCollision(player.m_colrect) == false)
	{
		enemy.enemy4->Enemyflag = false;
		enemy.enemy5->Enemyflag = false;
	}
}

void Map::End()
{
	//���f���̃A�����[�h
	obustructmap1->~ObstructMap();
	obustructmap2->~ObstructMap();
	obustructmap3->~ObstructMap();
	obustructmap4->~ObstructMap();
	obustructmap5->~ObstructMap();
	obustructmap6->~ObstructMap();
	obustructmap7->~ObstructMap();
	obustructmap8->~ObstructMap();
	obustructmap9->~ObstructMap();
	obustructmap10->~ObstructMap();

}
