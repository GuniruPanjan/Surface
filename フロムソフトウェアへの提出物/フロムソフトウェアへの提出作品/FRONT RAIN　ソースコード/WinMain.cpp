#include "DxLib.h"
#include "GraphMode.h"
#include "SceneMgr.h"
#include "Font.h"
#include "icon/icon.h"

//�t�H���g�ύX����
Font font;

// �v���O������ WinMain ����n�܂�܂�

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Window�̖��O��ύX����
	SetWindowText("FRONT RAIN");
	SetWindowIconID(IDI_ICON1);    //�E�B���h�E�A�C�R���̐ݒ�

	GraphMode graph;

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������

	ChangeWindowMode(true);

	SetWindowSize(graph.GraphModeWIDTH, graph.GraphModeHEIGHT);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������

	{

		return -1;			// �G���[���N�����璼���ɏI��

	}

	

	SetDrawScreen(DX_SCREEN_BACK);


	font.FontInit();
	SceneMgr_Initialize();
	// �Q�[�����[�v

	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���

		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		// �Q�[���̏���

		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();  //�`��


		// ��ʂ��؂�ւ��̂�҂�

		ScreenFlip();

		// esc�L�[�ŃQ�[���I��

		if (CheckHitKey(KEY_INPUT_ESCAPE))

		{

			break;

		}

		// FPS60�ɌŒ肷��

		while (GetNowHiPerformanceCount() - start < 16667)

		{

			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�

		}

	}

	SceneMgr_Finalize();    //�I������

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 

}