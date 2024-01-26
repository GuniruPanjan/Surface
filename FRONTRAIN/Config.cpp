#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Save.h"

SceneFedo settingfedo;

Save savedate;

Point savepoint;
TimeCount savetime;

static int mimageHandle[9];   //�摜�n���h���i�[�p�ϐ�

static int AnimCount;   //�A�j���[�V�����J�E���g

static int Time;  //�A�j���[�V�����^�C��

static bool Plus, Mainas;

//������
void Config_Initialize()
{
	//mimageHandle = LoadGraph("date/Menu���.png");//�摜�̃��[�h

	LoadDivGraph("date/DanceMoveto.png", 9, 3, 3, 853, 480, mimageHandle);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;
}

//�I������
void Config_Finalize()
{
	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(mimageHandle[i]);//�摜�̉��
	}
	
}

//�X�V
void Config_Update(Point& point,TimeCount& timecount)
{
	settingfedo.UpdateInSetting();

	//save.SaveDate(point, timecount);

	//Z�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_Z) != 0)
	{
		SceneMgr_ChageScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Config_Draw(Point& point,TimeCount& timecount)
{
	Time++;
	if (Time >= 5)
	{
		if (Plus == true)
		{
			AnimCount++;

			if (AnimCount >= 9)
			{
				Plus = false;

				Mainas = true;
			}
		}
		if (Mainas == true)
		{
			AnimCount--;

			if (AnimCount <= 0)
			{
				Mainas = false;

				Plus = true;
			}
		}

		Time = 0;
	}

	

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(-106, 0, mimageHandle[AnimCount], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 125);

	savedate.SaveLoad();

	/*DrawFormatString(100, 100,GetColor(255, 255, 255), "�X�R�A:%d", point.PointPoint);
	DrawFormatString(100, 150, GetColor(255, 255, 255), "�^�C��:%d�b", timecount.SaveTime);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "����:%dm", point.DistancePoint);*/

	//DrawString(100, 240, "�L�^��ʂł��܂��ł��Ă܂��񂷂��܂���", GetColor(255, 255, 255));
	DrawString(100, 280, "Z�L�[�������ƃ��j���[��ʂɖ߂�܂�", GetColor(255, 255, 255));
}
