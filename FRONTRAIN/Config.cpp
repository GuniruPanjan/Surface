#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Save.h"
#include "Rect.h"

SceneFedo settingfedo;

Save savedate;

Point savepoint;
TimeCount savetime;

Rect m_Rect;
Rect m_Mouse;

static int mimageHandle[9];   //�摜�n���h���i�[�p�ϐ�

static int AnimCount;   //�A�j���[�V�����J�E���g

static int Time;  //�A�j���[�V�����^�C��

static bool Plus, Mainas;

// �}�E�X�̍��W���擾���邽�߂̕ϐ�
int CMouseX, CMouseY;

int CColor, CWhite, CYello;

bool CRecord;

//������
void Config_Initialize()
{
	//mimageHandle = LoadGraph("date/Menu���.png");//�摜�̃��[�h

	LoadDivGraph("date/DanceMoveto.png", 9, 3, 3, 853, 480, mimageHandle);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;

	CMouseX = 0;
	CMouseY = 0;

	CColor = 0;
	CWhite = GetColor(255, 255, 255);
	CYello = GetColor(255, 255, 0);

	CRecord = false;
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
	//if (CheckHitKey(KEY_INPUT_Z) != 0)
	if(CRecord == true)
	{
		SceneMgr_ChageScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&CMouseX, &CMouseY);

	if (m_Rect.IsCollision(m_Mouse) == false)
	{
		CColor = CWhite;
	}
	else if (m_Rect.IsCollision(m_Mouse) == true)
	{
		CColor = CYello;
		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			CRecord = true;
		}
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

	//DrawString(100, 240, "�L�^��ʂł��܂��ł��Ă܂��񂷂��܂���", GetColor(255, 255, 255));

	m_Mouse.SetCenter(CMouseX, CMouseY + 5, 10, 10);

	m_Rect.SetCenter(330, 290, 150, 30);
	DrawString(260, 280, "���j���[���", CColor);

	/*m_Rect.Draw(GetColor(255, 0, 0), false);
	m_Mouse.Draw(GetColor(255, 0, 0), false);*/
}
