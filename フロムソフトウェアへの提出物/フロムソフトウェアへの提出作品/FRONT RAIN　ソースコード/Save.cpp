#include "Save.h"
#include "DxLib.h"
#include<stdio.h>
#include<time.h>

Save::Save():
	Start(false),
	name(0),
	White(0),
	end(false),
	Soundname(0),
	hiscore(0),
	NameSave(),
	NameDisplay(),
	String(),
	save_date(),
	save_hiscore()
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

	save_hiscore = { point.DistancePoint, point.PointPoint, timecount.SaveTime };

	NameSave = { String };

	NameDisplay = { String };

	hiscore = GetHiScore();

	FILE* fp;
	FILE* HiFp;
	FILE* HiUp;
	FILE* FName;
	FILE* FNameDis;

	//�t�@�C���ǂݍ���
	fopen_s(&fp, "save.txt", "wb");

	fopen_s(&HiUp, "HiUp.txt", "r");

	fopen_s(&FNameDis, "NameDis.txt", "w");

	if (fp == NULL)
	{
		//�t�@�C���ǂݍ��݃G���[
		MessageBox(NULL, "�t�@�C���ǂݍ��ݎ��s", "", MB_OK);
	}
	if (HiUp != NULL)
	{
		fscanf_s(HiUp, "%d", &hiscore);
		fclose(HiUp);
	}
	//�t�@�C���ւ̏������݂��s��
	if (HiUp == NULL || hiscore < point.PointPoint)
	{
		fopen_s(&HiUp, "HiUp.txt", "w");
		fprintf(HiUp, "%d", point.PointPoint);
		fclose(HiUp);
		//fopen_s(&HiFp, "Hiscore.txt", "wb");
		fopen_s(&HiFp, "Hiscore.txt", "wb");
		fopen_s(&FName, "Name.txt", "w");

		fwrite(&save_hiscore, sizeof(save_hiscore), 1, HiFp);    //save_date�\���̂̒��g���o��
		fprintf_s(FName, String);

		fclose(HiFp);
		fclose(FName);
		
	}

	fwrite(&save_date, sizeof(save_date), 1, fp);   //save_date�\���̂̒��g���o��

	fprintf_s(FNameDis, String);        //���O���L������

	fclose(fp);

	fclose(FNameDis);

	
}

int Save::GetHiScore(void)
{
	FILE* HiUp;

	//�t�@�C���ǂݍ���
	fopen_s(&HiUp, "HiUp.txt", "r");

	if (HiUp == NULL)
		return 0;

	//�n�C�X�R�A�ǂݍ���
	fscanf_s(HiUp, "%d", &hiscore);
	fclose(HiUp);
	return hiscore;
	
}

void Save::SaveInput()
{

	DrawFormatString(50, 100, White, "�A���t�@�x�b�g��8�����ȓ��Ŗ��O����͂��Ă�������");

	//���O�����
	DrawKeyInputModeString(640, 480);
	DrawKeyInputString(250, 150, name);

	DrawFormatString(100, 300, White, "���܂�����G���^�[�L�[�������Ă�������");

	//�G���^�[�L�[�������ꂽ��
	if(CheckHitKey(KEY_INPUT_RETURN))
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

void Save::NameOutPut()
{

	//���͂��ꂽ��������擾
	GetKeyInputString(String, name);
}

void Save::SaveLoad()
{
	//�Z�[�u�t�@�C���̕\���F
	int SaveFailColor = GetColor(255, 255, 255);

	FILE* fp;
	FILE* FNameDis;

	//�t�@�C���̓ǂݍ���
	fopen_s(&fp, "save.txt", "rb");
	fopen_s(&FNameDis, "NameDis.txt", "r");

	if (fp == NULL)
	{
		//�t�@�C���ǂݍ��݃G���[
		MessageBox(NULL, "�t�@�C���ǂݍ��ݎ��s", "", MB_OK);
	}

	fread(&save_date, sizeof(save_date), 1, fp);
	fread(&NameDisplay, sizeof(NameDisplay), 1, FNameDis);

	//�t�@�C���̃f�[�^���o��
	DrawFormatString(100, 60, SaveFailColor, "%s", NameDisplay.NameDisplay);
	DrawFormatString(100, 100, SaveFailColor, "�X�R�A:%d", save_date.Point);
	DrawFormatString(100, 150, SaveFailColor, "�^�C��:%d�b", save_date.Time);
	DrawFormatString(100, 200, SaveFailColor, "����:%dm", save_date.Distance);

	fclose(fp);
	fclose(FNameDis);

}

void Save::SaveHiscoreLoad()
{
	//�Z�[�u�t�@�C���̕\���F
	int SaveFailColor = GetColor(255, 255, 255);

	FILE* HiFp;
	FILE* FName;

	//�t�@�C���ǂݍ���
	fopen_s(&HiFp, "Hiscore.txt", "rb");
	fopen_s(&FName, "Name.txt", "r");

	if (HiFp == NULL)
	{
		//�t�@�C���ǂݍ��݃G���[
		MessageBox(NULL, "�t�@�C���ǂݍ��ݎ��s", "", MB_OK);
	}

	fread(&save_hiscore, sizeof(save_hiscore), 1, HiFp);
	fread(&NameSave, sizeof(NameSave), 1, FName);

	//�t�@�C���̃f�[�^���o��
	DrawFormatString(400, 60, SaveFailColor, "%s", NameSave.Name);
	DrawFormatString(400, 100, SaveFailColor, "�n�C�X�R�A:%d", save_hiscore.Point);
	DrawFormatString(400, 150, SaveFailColor, "�^�C��:%d�b", save_hiscore.Time);
	DrawFormatString(400, 200, SaveFailColor, "����:%dm", save_hiscore.Distance);

	fclose(HiFp);
	fclose(FName);
}
