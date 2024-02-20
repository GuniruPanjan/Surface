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

static bool ContinueInit;

static int Botton;   //�{�^���̉摜�i�[�p�ϐ�

static int b;   //�摜���ߗp�ϐ�

// �}�E�X�̍��W���擾���邽�߂̕ϐ�
int CMouseX, CMouseY;

int CColor, Cblack, CYello;

bool CRecord;

int SceneTime;

//�T�E���h�p�i�[�ϐ�
int SoundConfig;

//SE�p�i�[�ϐ�
int SEClickConfig;

//������
void Config_Initialize()
{

	LoadDivGraph("date/DanceMoveto.png", 9, 3, 3, 853, 480, mimageHandle);

	AnimCount = 0;

	Time = 0;

	Plus = true;

	Mainas = false;

	ContinueInit = false;

	CMouseX = 0;
	CMouseY = 0;

	CColor = 0;
	Cblack = GetColor(0, 0, 0);
	CYello = GetColor(255, 255, 0);

	Botton = LoadGraph("date/�{�^��.png");

	b = 255;

	CRecord = false;

	SceneTime = 0;

	SoundConfig = LoadSoundMem("BGM/�D��������.mp3");

	SEClickConfig = LoadSoundMem("SE/����{�^��������40.mp3");

}

//�I������
void Config_Finalize()
{
	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(mimageHandle[i]);//�摜�̉��
	}

	DeleteSoundMem(SoundConfig);

	DeleteSoundMem(SEClickConfig);

	DeleteGraph(Botton);

	settingfedo.FinalizeFedo();
	
}

//�X�V
void Config_Update(Point& point,TimeCount& timecount)
{

	SceneTime++;

	//�V�[���J�ڂ̉��o
	settingfedo.UpdateInSetting();


	//�N���b�N���ꂽ��V�[����ύX
	if(CRecord == true)
	{

		SceneMgr_ChageScene(eScene_Menu);//�V�[�������j���[�ɕύX

	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&CMouseX, &CMouseY);

	//�{�^���ɐG��Ă��Ȃ��Ƃ�
	if (m_Rect.IsCollision(m_Mouse) == false)
	{
		CColor = Cblack;

		b = 255;
	}
	//�{�^���ɐG��Ă���Ƃ�
	else if (m_Rect.IsCollision(m_Mouse) == true)
	{
		CColor = CYello;

		b = 120;
		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			if (SceneTime >= 20)
			{
				PlaySoundMem(SEClickConfig, DX_PLAYTYPE_BACK, FALSE);

				CRecord = true;

				SceneTime = 0;
			}
			
		}
	}

	PlaySoundMem(SoundConfig, DX_PLAYTYPE_LOOP, FALSE);

}

//�`��
void Config_Draw(Point& point,TimeCount& timecount)
{
	//��ʔw�i�ł̃A�j���[�V�����^�C��
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

	
	//�w�i�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(-106, 0, mimageHandle[AnimCount], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 125);

	//�Z�[�u�f�[�^�̓ǂݍ���
	savedate.SaveLoad();
	//�n�C�X�R�A�̓ǂݍ���
	savedate.SaveHiscoreLoad();

	DrawFormatString(100, 20, GetColor(255, 255, 255), "����̃X�R�A");

	DrawFormatString(400, 20, GetColor(255, 255, 255), "�n�C�X�R�A");

	m_Mouse.SetCenter(static_cast<float>(CMouseX), static_cast<float>(CMouseY + 5.0f), 10, 10);

	//�w�i���Â��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(263, 275, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//�{�^���̕\���Ɠ����蔻��
	m_Rect.SetCenter(323, 290, 120, 30);
	DrawString(276, 276, "�^�C�g��", CColor);
}
