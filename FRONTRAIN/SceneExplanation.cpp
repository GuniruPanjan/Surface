#include "SceneExplanation.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Explanationfedo;

Rect m_ERect;
Rect m_EMouse;

static int ExplanationHandle;  //�摜�n���h���i�[�p�ϐ�

static int Botton;    //�{�^���摜�i�[�p�ϐ�

static int b;    //�摜���ߗp�ϐ�

// �}�E�X�̍��W���擾���邽�߂̕ϐ�
int EMouseX, EMouseY;

int EColor, EBlack, EYello;

bool EMenu;

//�T�E���h�p�i�[�ϐ�
int SoundExplanation;

//SE�p�i�[�ϐ�
int SEClickExplanation;

//������
void Explanation_Initialize()
{
	ExplanationHandle = LoadGraph("date/������.png"); //�摜���[�h

	EMouseX = 0;
	EMouseY = 0;

	Botton = LoadGraph("date/�{�^��.png");

	b = 255;

	EColor = 0;
	EBlack = GetColor(0, 0, 0);
	EYello = GetColor(255, 255, 0);

	EMenu = false;

	SoundExplanation = LoadSoundMem("BGM/���ʉe�G.mp3");

	SEClickExplanation = LoadSoundMem("SE/����{�^��������40.mp3");
}

//�I������
void Explanation_Finalize()
{
	DeleteGraph(ExplanationHandle);//�摜�̉��

	DeleteSoundMem(SoundExplanation);

	DeleteSoundMem(SEClickExplanation);

	DeleteGraph(Botton);

	Explanationfedo.FinalizeFedo();
}

//�X�V
void Explanation_Update()
{
	Explanationfedo.UpdateInSetting();

	//Z�L�[��������Ă�����
	//if (CheckHitKey(KEY_INPUT_Z) != 0)
	if(EMenu == true)
	{

		SceneMgr_ChageScene(eScene_Menu); //�V�[�������j���[��ʂɕύX

	}

	//�}�E�X�̍��W�擾
	GetMousePoint(&EMouseX, &EMouseY);

	if (m_ERect.IsCollision(m_EMouse) == true)
	{
		EColor = EYello;

		b = 120;

		//���N���b�N���������Ƃ�
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			EMenu = true;

			PlaySoundMem(SEClickExplanation, DX_PLAYTYPE_BACK, FALSE);
		}

	}
	else if (m_ERect.IsCollision(m_EMouse) == false)
	{
		EColor = EBlack;

		b = 255;
	}

	PlaySoundMem(SoundExplanation, DX_PLAYTYPE_LOOP, FALSE);

}

//�`��
void Explanation_Draw()
{
	DrawGraph(0, 0, ExplanationHandle, TRUE);

	m_EMouse.SetCenter(EMouseX, EMouseY + 5, 10, 10);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(120, 395, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_ERect.SetCenter(180, 410, 120, 30);
	DrawString(135, 400, "���j���[", EColor);

	/*m_ERect.Draw(GetColor(255, 0, 0), false);
	m_EMouse.Draw(GetColor(255, 0, 0), false);*/
}
