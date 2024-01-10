#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mimageHandle;  //�摜�n���h���i�[�p�ϐ�

//������
void Menu_Initialize()
{
	mimageHandle = LoadGraph("date/�z�[�����.jpg");    //�摜���[�h
}

//�I������
void Menu_Finalize()
{
	DeleteGraph(mimageHandle); //�摜�̉��
}

//�X�V
void Menu_Update()
{
	//G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		SceneMgr_ChageScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
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
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂�", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������Ɛݒ��ʂɐi�݂܂�", GetColor(255, 255, 255));

}
