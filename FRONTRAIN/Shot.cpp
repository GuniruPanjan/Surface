#include "Shot.h"
#include "DxLib.h"

Shot::Shot():
	ShotGraph(0),
	X(0),
	Y(0),
	ShotFlag(false),
	Wdit(0),
	Hight(0)
{
}

Shot::~Shot()
{
}

void Shot::Init()
{
	//�V���b�g�̃O���t�B�b�N�����[�h
	ShotGraph = DrawCircle(X, Y, 1, GetColor(0, 255, 0), true);

	for (int i = 0; i < SHOT; i++)
	{
		shot[i]->ShotGraph = ShotGraph;
	}


	//ShotFlag�ϐ���false��������
	for (int i = 0; i < SHOT; i++)
	{
		shot[i]->ShotFlag = false;
	}

	//ShotGraph�̃T�C�Y�𓾂�
	int ShotW, ShotH;
	GetGraphSize(ShotGraph, &ShotW, &ShotH);
	for (int i = 0; i < SHOT; i++)
	{
		shot[i]->Wdit = ShotW;
		shot[i]->Hight = ShotH;
	}

}

void Shot::Update()
{
	

	




	
	
}

void Shot::Draw()
{
	

	for (int i = 0; i < SHOT; i++)
	{
		if (shot[i]->ShotFlag = true)
		{
			//�e�𓮂���
			shot[i]->X - 16;

			//�e����ʊO�ɏo����ShotFlag�ϐ���������
			if (shot[i]->X < 0 - shot[i]->Wdit)
			{
				shot[i]->ShotFlag = false;
			}
			if (shot[i]->X > shot[i]->Wdit)
			{
				shot[i]->ShotFlag = false;
			}
			if (shot[i]->Y < 0 - shot[i]->Hight)
			{
				shot[i]->ShotFlag = false;
			}
			if (shot[i]->Y > shot[i]->Hight)
			{
				shot[i]->ShotFlag = false;
			}

		}

	}
}
