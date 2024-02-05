#include "SceneExplanation.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Explanationfedo;

Rect m_ERect;
Rect m_EMouse;

static int ExplanationHandle;  //�摜�n���h���i�[�p�ϐ�

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
	}

	PlaySoundMem(SoundExplanation, DX_PLAYTYPE_LOOP, FALSE);

}

//�`��
void Explanation_Draw()
{
	DrawGraph(0, 0, ExplanationHandle, TRUE);

	m_EMouse.SetCenter(EMouseX, EMouseY + 5, 10, 10);

	m_ERect.SetCenter(200, 410, 150, 30);
	DrawString(130, 400, "���j���[���", EColor);

	/*m_ERect.Draw(GetColor(255, 0, 0), false);
	m_EMouse.Draw(GetColor(255, 0, 0), false);*/
}
