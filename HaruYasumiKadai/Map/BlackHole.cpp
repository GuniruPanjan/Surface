#include "BlackHole.h"

BlackHole::BlackHole() :
	BlackHole3D(0),
	BlackHoleX(0),
	BlackHoleY(0),
	pos(VGet(0,0,0)),
	BlackHoleWidth(0),
	BlackHoleHight(0),
	BlackDead(false)
{
}

BlackHole::~BlackHole()
{
	MV1DeleteModel(BlackHole3D);
}

void BlackHole::Init()
{
	//�u���b�N�z�[���̏����ʒu
	BlackHoleX = 0;
	BlackHoleY = 240;

	//3D�̃u���b�N�z�[���̏����ʒu
	pos = VGet(-420, -290, 0);

	//�u���b�N�z�[���̕�
	BlackHoleWidth = 150;
	BlackHoleHight = 480;

	BlackDead = false;

	//3D���f����ǂݍ���
	BlackHole3D = MV1LoadModel("date/BlackHole.mv1");
}

void BlackHole::Update(Player& player)
{

	//3D���f���̃X�P�[���ݒ�
	MV1SetScale(BlackHole3D, VGet(Scale, Scale, Scale));

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(BlackHole3D, pos);

	//�����蔻�������
	BlackHoleRect.SetCenter(static_cast<float>(BlackHoleX), static_cast<float>(BlackHoleY), static_cast<float>(BlackHoleWidth), static_cast<float>(BlackHoleHight));

	//�u���b�N�z�[���Ŏ��񂾔���
	if (BlackHoleRect.IsCollision(player.m_colrect) == true)
	{
		BlackDead = true;
	}
}

void BlackHole::Draw()
{
	//3D���f����`�悷��
	MV1DrawModel(BlackHole3D);
	//�����蔻���`�悷��
	//BlackHoleRect.Draw(GetColor(0, 0, 0), false);

	
}
