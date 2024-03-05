#include "DxLib.h"
#include "Map.h"
#include "Camera.h"
#include "Dice.h"
#include "Background.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̃T�C�Y�ύX
	int WindowSizeX, WindowSizeY;
	WindowSizeX = 1280;
	WindowSizeY = 960;

	SetWindowSize(WindowSizeX, WindowSizeY);

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�}�b�v�𐶐�
	Map* map = new Map;

	//�J�����𐶐�
	Camera* camera = new Camera;

	//�_�C�X�𐶐�
	Dice* dice = new Dice;

	//�w�i�𐶐�
	Background* Back = new Background;


	map->Init();
	camera->Init();
	dice->Init();


	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		Back->Draw();

		//map->Draw();

		camera->Update();

		dice->Update();
		dice->Draw();
		

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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}