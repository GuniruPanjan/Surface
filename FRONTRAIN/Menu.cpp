#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"

static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

bool ContinueInit; //�R���e�j���[�����Ƃ��ɏ���������

//������
void Menu_Initialize()
{
	mimageHandle = LoadGraph("date/�z�[�����.jpg");    //�摜���[�h

	ContinueInit = true;
}

//�I������
void Menu_Finalize()
{
	DeleteGraph(mimageHandle); //�摜�̉��
}

//�X�V
void Menu_Update()
{
	//ContinueInit��true�Ȃ�1����s����
	if (ContinueInit == true)
	{
		//�Q�[���V�[��������������
		Game_Initialize();
	}
	ContinueInit = false;
	

	//A�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{
		SceneMgr_ChageScene(eScene_Game);//�V�[�����Q�[����ʂɕύX

		ContinueInit = true;
	}
	//C�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgr_ChageScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
}

//�`��
void Menu_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);
	DrawString(0, 0, "���j���[��ʂł�", GetColor(255, 255, 255));
	DrawString(0, 20, "A�L�[�������ƃQ�[����ʂɐi�݂܂�", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������Ɛݒ��ʂɐi�݂܂�", GetColor(255, 255, 255));

}
