#include "Save.h"
#include "DxLib.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Save::Save():
	Start(false),
	name(0),
	White(0),
	end(false),
	Soundname(0)
{
}

Save::~Save()
{
}

void Save::FinalizeSave()
{
	DeleteSoundMem(Soundname);
}

void Save::SaveInit()
{
	Start = false;
	end = false;

	White = GetColor(255, 255, 255); //���F����

	name = MakeKeyInput(8, TRUE, FALSE, FALSE);
	SetActiveKeyInput(name);

	Soundname = LoadSoundMem("BGM/���ʉe�G.mp3");
}

void Save::SaveDate(Point& point,TimeCount& timecount)
{
	save_date = { point.DistancePoint, point.PointPoint, timecount.SaveTime };

	FILE *fp;

	fopen_s(&fp, "save.txt", "wb");

	if (fp == NULL)
	{
		//�t�@�C���ǂݍ��݃G���[
		MessageBox(NULL, "�t�@�C���ǂݍ��ݎ��s", "", MB_OK);
	}

	//fprintf(fp, "�X�R�A:%d\n�^�C��:%d�b\n����:%dm", point.PointPoint, timecount.SaveTime, point.DistancePoint);

	fwrite(&save_date, sizeof(save_date), 1, fp);   //save_date�\���̂̒��g���o��

	fclose(fp);
}

void Save::SaveInput()
{
	DrawFormatString(120, 100, White, "8�����ȓ��Ŗ��O����͂��Ă�������");

	DrawKeyInputModeString(640, 480);
	DrawKeyInputString(250, 150, name);

	DrawFormatString(100, 300, White, "���܂�����}�E�X�E�N���b�N���Ă�������");

	//�}�E�X�̉E�N���b�N�������ꂽ��
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		if (name == NULL)
		{
			DrawFormatString(120, 250, White, "���O����͂��Ă�������");
		}
		else
		{
			Start = true;

			DeleteSoundMem(Soundname);
		}
		
	}

	PlaySoundMem(Soundname, DX_PLAYTYPE_LOOP, FALSE);

}

void Save::SaveLoad()
{
	FILE *fp;

	fopen_s(&fp, "save.txt", "rb");

	if (fp == NULL)
	{
		//�t�@�C���ǂݍ��݃G���[
		MessageBox(NULL, "�t�@�C���ǂݍ��ݎ��s", "", MB_OK);
	}
	fread(&save_date, sizeof(save_date), 1, fp);

	fclose(fp);

	DrawFormatString(100, 100, GetColor(255, 255, 255), "�X�R�A:%d", save_date.Point);
	DrawFormatString(100, 150, GetColor(255, 255, 255), "�^�C��:%d�b", save_date.Time);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "����:%dm", save_date.Distance);

}
