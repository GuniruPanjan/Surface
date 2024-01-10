#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mimageHandle;   //�摜�n���h���i�[�p�ϐ�

//������
void Config_Initialize()
{
	mimageHandle = LoadGraph("date/���j���[���.jpg");//�摜�̃��[�h
}

//�I������
void Config_Finalize()
{
	DeleteGraph(mimageHandle);//�摜�̉��
}

//�X�V
void Config_Update()
{
	//SPACE�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_SPACE) != 0)
	{
		SceneMgr_ChageScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Config_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);
	DrawString(0, 0, "�ݒ��ʂł�", GetColor(255, 255, 255));
	DrawString(0, 20, "SPACE�L�[�������ƃ��j���[��ʂɖ߂�܂�", GetColor(255, 255, 255));
}
