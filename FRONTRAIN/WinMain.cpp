#include "Player.h"
#include "WalkEnemy.h"
#include "Background.h"
#include "DxLib.h"
#include "Map.h"

// �v���O������ WinMain ����n�܂�܂�

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������

	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������

	{

		return -1;			// �G���[���N�����璼���ɏI��

	}

	

	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	Shot shot[SHOT];
	WalkEnemy WEnemy;
	Map map;
	Background Back;
	int shotGraph = LoadGraph("date/�e�e.png");

	player.Init();
	for (int i = 0; i < SHOT; i++)
	{
		player.InitShot(shot[i],shotGraph);
	}
	
	WEnemy.Init();

	map.InitMap();
	// �Q�[�����[�v

	while (ProcessMessage() != -1)

	{

		// ���̃t���[���̊J�n�������o���Ă���

		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����

		ClearDrawScreen();

		// �Q�[���̏���
		Back.Draw();

		player.Update();
		WEnemy.Update();

		player.ShotUpdate(player, shot, SHOT);
		map.UpdateMap();
		

		player.Draw();
		for (int i = 0; i < SHOT; i++)
		{
			player.DrawShot(shot[i]);
		}
		
		WEnemy.Draw();

		map.DrawMap();

		

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